#pragma once

#include "SimpleExpression.hpp"

namespace MPM {
namespace Model {

class LeafNode : public SimpleExpression
{
public:
    using DataType = std::string;

    LeafNode(DataType data, size_t id = IExpression::INVALID_ID);

    bool isEqual(const IExpression* other) const override;
    std::shared_ptr<IExpression> clone() const override;
};

}
}
