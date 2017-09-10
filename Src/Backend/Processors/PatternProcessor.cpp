#include "PatternProcessor.hpp"

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

    return std::make_shared<Model::SimpleExpression>(expr->getID(), "minimized", structure);
}

}
}
