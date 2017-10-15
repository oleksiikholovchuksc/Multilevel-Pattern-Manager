#include "SimpleExpression.hpp"


namespace MPM {
namespace Model {

SimpleExpression::SimpleExpression(
        size_t id,
        const std::string& name,
        const std::vector<std::shared_ptr<IExpression>>& structure)
    : IExpression(id)
    , mName(name)
    , mStructure(structure)
{

}

bool SimpleExpression::isEqual(const IExpression* other) const
{
    auto asSimpleExpr = dynamic_cast<const SimpleExpression*>(other);
    if(!asSimpleExpr)
        return false;

    auto structure = asSimpleExpr->getStructure();
    if(structure.size() != mStructure.size())
        return false;

    for(size_t i = 0; i < mStructure.size(); ++i)
    {
        if(!structure[i]->isEqual(mStructure[i].get()))
            return false;
    }

    return true;
}

std::vector<std::shared_ptr<IExpression>> SimpleExpression::getOperands() const
{
    return mStructure;
}

const std::vector<std::shared_ptr<IExpression>>& SimpleExpression::getStructure() const
{
    return mStructure;
}

void SimpleExpression::addChild(std::shared_ptr<IExpression> expr)
{
    mStructure.push_back(expr);
}

std::shared_ptr<IExpression> SimpleExpression::clone() const {
    std::vector<std::shared_ptr<IExpression>> cloneStructure;
    for(const auto& structureItem : mStructure)
    {
        auto expressionClone = std::dynamic_pointer_cast<IExpression>(structureItem->clone());
        cloneStructure.push_back(expressionClone);
    }

    return std::make_shared<SimpleExpression>(getID(), getName(), cloneStructure);
}

std::string SimpleExpression::getName() const
{
    return mName;
}

void SimpleExpression::setName(const std::string &newName)
{
    mName = newName;
}

}
}
