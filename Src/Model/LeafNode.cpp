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
    if(asLeaf && asLeaf->getValue() == mValue)
        return true;

    return false;
}

LeafNode::DataType LeafNode::getValue() const
{
    return mValue;
}

}
}