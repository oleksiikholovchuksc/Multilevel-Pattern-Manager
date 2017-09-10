#include "LeafNode.hpp"

#include "Utils.h"


namespace MPM {
namespace Model {

LeafNode::LeafNode(DataType value, size_t id)
    : SimpleExpression(id, value)
    , mValue(value)
{

}

bool LeafNode::isEqual(const IExpression* other) const 
{
    auto asLeaf = dynamic_cast<const LeafNode*>(other);
    return asLeaf && asLeaf->getValue() == mValue;
}

LeafNode::DataType LeafNode::getValue() const
{
    return mValue;
}

std::shared_ptr<IExpression> LeafNode::clone() const {
    return std::make_shared<LeafNode>(mValue, getID());
}

std::string LeafNode::getName() const
{
    return getValue();
}

}
}
