#include "PatternTree.h"

namespace MPM {

PatternTree::PatternTree(std::shared_ptr<Node> rootNode)
    : mRootNode(rootNode)
{

}

std::shared_ptr<PatternTree::Node> PatternTree::getRootNode() const
{
    return mRootNode;
}

}
