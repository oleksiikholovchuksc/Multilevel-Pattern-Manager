#pragma once

#include "SimpleExpression.hpp"

namespace MPM {
namespace Model {

class LeafNode : public SimpleExpression
{
public:
    using DataType = char;

    LeafNode(DataType data);
    DataType getValue() const;

    bool isEqual(const IExpression* other) const override;
    std::shared_ptr<IExpression> clone() const override;

private:
    DataType mValue;    
};

}
}