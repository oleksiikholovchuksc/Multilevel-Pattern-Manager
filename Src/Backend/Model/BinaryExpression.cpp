//
// Created by Oleksii Holovchuk on 5/13/17.
//

#include "BinaryExpression.h"

namespace MPM {
namespace Model {

BinaryExpression::BinaryExpression(std::shared_ptr<IExpression> left, std::shared_ptr<IExpression> right)
    : mLeft(left)
    , mRight(right)
{

}

bool BinaryExpression::isEqual(const IExpression *other) const {
    const BinaryExpression *asBinaryExpr = dynamic_cast<const BinaryExpression*>(other);
    if(!asBinaryExpr)
        return false;

    auto leftExpr = asBinaryExpr->getOperands()[0];
    auto rightExpr = asBinaryExpr->getOperands()[1];

    return mLeft->isEqual(leftExpr) && mRight->isEqual(rightExpr);
}

std::vector<const IExpression *> BinaryExpression::getOperands() const {
    return { mLeft.get(), mRight.get() };
}

std::shared_ptr<IExpression> BinaryExpression::clone() const {
    return std::make_shared<BinaryExpression>(mLeft->clone(), mRight->clone());
}

std::string BinaryExpression::getName() const
{
    return mLeft->getName() + " | " + mRight->getName();
}

}
}
