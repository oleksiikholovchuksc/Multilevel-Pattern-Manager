#include "BackUtilsUtils.h"

#include "Model/LeafNode.hpp"
#include "Model/BinaryExpression.h"

#include <cassert>

namespace MPM {
namespace BackUtils {

std::shared_ptr<PatternTree::Node> conversionHelper(
        std::shared_ptr<PatternTree::Node> parent,
        std::shared_ptr<Model::IExpression> e)
{
    if(!e)
        return nullptr;

    auto node = std::make_shared<PatternTree::Node>();
    node->id = e->getID();
    node->name = e->getName();
    node->parent = parent;
    if(parent)
    {
        parent->children.push_back(node);
    }

    if(!std::dynamic_pointer_cast<Model::LeafNode>(e))
    {
        std::vector<std::shared_ptr<Model::IExpression>> exprVec = {};
        if(auto bin = std::dynamic_pointer_cast<Model::BinaryExpression>(e))
        {
            exprVec = bin->getOperands();
        }
        else if(auto simple = std::dynamic_pointer_cast<Model::SimpleExpression>(e))
        {
            for(auto structureUnit : simple->getStructure())
                exprVec.push_back(structureUnit);
        }
        else
        {
            assert(false);  // wtf blyat
        }

        for(auto expr : exprVec)
            conversionHelper(node, expr);
    }

    return node;
}

PatternTree ptreeFromIExpression(std::shared_ptr<Model::IExpression> e)
{
    return PatternTree(conversionHelper(nullptr, e));
}

}
}
