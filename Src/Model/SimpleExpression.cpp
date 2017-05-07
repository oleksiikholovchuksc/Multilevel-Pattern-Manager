#include "SimpleExpression.hpp"


namespace MPM {
namespace Model {

SimpleExpression::SimpleExpression(const std::vector<std::shared_ptr<SimpleExpression>>& structure)
    : mStructure(structure)
{

}

bool SimpleExpression::isEqual(const IExpression* other) const
{
    auto asSimpleExpr = dynamic_cast<const SimpleExpression*>(other);
    if(!asSimpleExpr)
        return false;

    return true;
}

std::vector<const IExpression*> SimpleExpression::getOperands() const
{
    return { this };
}

const std::vector<std::shared_ptr<SimpleExpression>>& SimpleExpression::getStructure() const
{
    return mStructure;
}

}
}