#pragma once

#include "IExpression.hpp"

namespace MPM {
namespace Model {

class BinaryExpression : public IExpression {
public:
    BinaryExpression(
            std::shared_ptr<IExpression> left,
            std::shared_ptr<IExpression> right,
            size_t id = IExpression::INVALID_ID);

    bool isEqual(const IExpression* other) const override;
    std::vector<const IExpression*> getOperands() const override;
    std::shared_ptr<IExpression> clone() const override;
    std::string getName() const override;

private:
    std::shared_ptr<IExpression> mLeft;
    std::shared_ptr<IExpression> mRight;
};

}
}
