#pragma once

#include "SimpleExpression.hpp"

namespace MPM {
namespace Model {

class LeafNode : public SimpleExpression
{
public:
    using DataType = char;

    LeafNode(DataType data);
    bool isEqual(const IExpression* other) const override;
    DataType getValue() const;

private:
    DataType mValue;    
};

}
}