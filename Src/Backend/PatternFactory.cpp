#include "PatternFactory.h"

namespace MPM {
namespace Backend {

PatternFactory::PatternFactory()
{

}

std::shared_ptr<Model::SimpleExpression>
PatternFactory::createLowLevelPattern(std::vector<Model::LeafNode::DataType> sequence)
{
    // create name
    std::string name = getNewNameLowLevel(sequence);

    // create structure
    std::vector<std::shared_ptr<Model::IExpression>> list = {};
    for(const auto& elem : sequence)
    {
        list.push_back(std::make_shared<Model::LeafNode>(elem));
    }

    return std::make_shared<Model::SimpleExpression>(name, list);
}

std::string PatternFactory::getNewNameLowLevel(std::vector<Model::LeafNode::DataType> sequence)
{
    // NIY

    return "low_level_p";
}

}
}
