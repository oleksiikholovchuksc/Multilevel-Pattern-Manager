#include "LeafNode.hpp"

#include "Utils.h"


namespace MPM {
namespace Model {

LeafNode::LeafNode(DataType value, size_t id)
    : SimpleExpression(id, value)
{

}

bool LeafNode::isEqual(const IExpression* other) const 
{
    auto asLeaf = dynamic_cast<const LeafNode*>(other);
    return asLeaf && asLeaf->getName() == mName;
}

std::shared_ptr<IExpression> LeafNode::clone() const {
    return std::make_shared<LeafNode>(mName, getID());
}

}
}
