#include "SimpleExpression.hpp"


namespace MPM {
namespace Model {

SimpleExpression::SimpleExpression(const std::string& name,
                                   const std::vector<std::shared_ptr<IExpression>>& structure)
    : mName(name)
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

std::vector<const IExpression*> SimpleExpression::getOperands() const
{
    return { this };
}

const std::vector<std::shared_ptr<IExpression>>& SimpleExpression::getStructure() const
{
    return mStructure;
}

std::shared_ptr<IExpression> SimpleExpression::clone() const {
    std::vector<std::shared_ptr<IExpression>> cloneStructure;
    for(const auto& structureItem : mStructure)
    {
        auto expressionClone = std::dynamic_pointer_cast<IExpression>(structureItem->clone());
        cloneStructure.push_back(expressionClone);
    }

    return std::make_shared<SimpleExpression>(getName(), cloneStructure);
}

std::string SimpleExpression::getName() const
{
    return mName;
}

}
}
