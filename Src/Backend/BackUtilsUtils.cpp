#include "BackUtilsUtils.h"

#include "Model/LeafNode.hpp"
#include "Model/BinaryExpression.h"

#include <cassert>

namespace MPM {
namespace BackUtils {

std::shared_ptr<PatternTree::Node> conversionHelper(
        std::shared_ptr<PatternTree::Node> parent,
        const Model::IExpression* e)
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

    if(!dynamic_cast<const Model::LeafNode*>(e))
    {
        std::vector<const Model::IExpression*> exprVec = {};
        if(auto bin = dynamic_cast<const Model::BinaryExpression*>(e))
        {
            exprVec = bin->getOperands();
        }
        else if(auto simple = dynamic_cast<const Model::SimpleExpression*>(e))
        {
            for(auto structureUnit : simple->getStructure())
                exprVec.push_back(structureUnit.get());
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
    return PatternTree(conversionHelper(nullptr, e.get()));
}

}
}
