#include "PatternProcessor.hpp"

#include "Backend/Model/LeafNode.hpp"

#include <QString>
#include <QRegularExpression>

namespace MPM {
namespace Processor {

static std::shared_ptr<Model::SimpleExpression> addDummyParent(std::shared_ptr<Model::BinaryExpression> expr) {
    std::vector<std::shared_ptr<Model::IExpression>> exprVec {expr->clone()};
    return std::make_shared<Model::SimpleExpression>(0, "Dummy", exprVec);
}

std::shared_ptr<Model::BinaryExpression> splice(
        size_t splicedId,
        std::shared_ptr<Model::IExpression> left,
        std::shared_ptr<Model::IExpression> right)
{
    return std::make_shared<Model::BinaryExpression>(left->clone(), right->clone(), splicedId);
}

std::shared_ptr<Model::SimpleExpression> minimize(std::shared_ptr<Model::BinaryExpression> expr) {
    auto left = expr->getOperands()[0];
    auto right = expr->getOperands()[1];

    auto exprLeft = std::dynamic_pointer_cast<Model::SimpleExpression>(left);
    auto exprRight = std::dynamic_pointer_cast<Model::SimpleExpression>(right);

    if(!exprLeft || !exprRight)
        return addDummyParent(expr);

    auto structLeft = exprLeft->getStructure();
    auto structRight = exprRight->getStructure();
    if(structLeft.size() != structRight.size())
        return addDummyParent(expr);

    std::vector<std::shared_ptr<Model::IExpression>> structure;
    for(size_t i = 0; i < structLeft.size(); ++i)
    {
        const auto leftItem = structLeft[i].get();
        const auto rightItem = structRight[i].get();
        std::shared_ptr<Model::IExpression> newItem;

        if(leftItem->isEqual(rightItem))
        {
            newItem = leftItem->clone();
        }
        else
        {
            newItem = std::make_shared<Model::BinaryExpression>(leftItem->clone(), rightItem->clone());
        }

        structure.push_back(newItem);
    }

    return std::make_shared<Model::SimpleExpression>(
                expr->getID(),
                "Min(" + expr->getName() + ")",
                structure);
}

static QString getNodePattern(std::shared_ptr<Model::IExpression> node)
{
    QString result;

    if(std::shared_ptr<Model::LeafNode> asLeaf = std::dynamic_pointer_cast<Model::LeafNode>(node))
    {
        result += QString::fromStdString(asLeaf->getValue());
    }
    else if(std::shared_ptr<Model::SimpleExpression> asSimple = std::dynamic_pointer_cast<Model::SimpleExpression>(node))
    {
        auto structure = asSimple->getStructure();
        for(auto item : structure)
        {
            result += getNodePattern(item);
        }
    }
    else if(std::shared_ptr<Model::BinaryExpression> asBinary = std::dynamic_pointer_cast<Model::BinaryExpression>(node))
    {
        result += "(";
        result += getNodePattern(asBinary->getOperands()[0]);
        result += "|";
        result += getNodePattern(asBinary->getOperands()[1]);
        result += ")";
    }

    return result;
}

static QRegularExpression buildRegexp(std::shared_ptr<Model::IExpression> expr)
{
    QString patternString = "^" + getNodePattern(expr) + "$";
    return QRegularExpression(patternString, QRegularExpression::CaseInsensitiveOption);
}

bool recognizeString(const std::vector<std::shared_ptr<Model::IExpression>> &expressions, const std::string &inputString)
{
    QString string = QString::fromStdString(inputString);
    for(auto expr : expressions)
    {
        QRegularExpression regexp = buildRegexp(expr);
        if(regexp.isValid() && regexp.match(string).hasMatch())
        {
            return true;
        }
    }

    return false;
}

}
}
