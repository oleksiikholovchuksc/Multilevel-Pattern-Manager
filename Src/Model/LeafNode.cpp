#include "LeafNode.hpp"


namespace MPM {
namespace Model {

LeafNode::LeafNode(DataType value)
    : mValue(value)
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

}
}