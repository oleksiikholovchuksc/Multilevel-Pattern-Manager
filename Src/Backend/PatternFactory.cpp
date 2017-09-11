#include "PatternFactory.h"
#include "Processors/PatternProcessor.hpp"

namespace MPM {
namespace Backend {

PatternFactory::PatternFactory()
{

}

std::shared_ptr<Model::SimpleExpression>
PatternFactory::createLowLevelPattern(std::vector<Model::LeafNode::DataType> sequence)
{
    // get new id
    size_t id = getNextID();

    // create name
    std::string name = "P" + std::to_string(id);

    // create structure
    std::vector<std::shared_ptr<Model::IExpression>> list = {};
    for(const auto& elem : sequence)
    {
        list.push_back(std::make_shared<Model::LeafNode>(elem, getNextID()));
    }

    return std::make_shared<Model::SimpleExpression>(id, name, list);
}

std::shared_ptr<Model::BinaryExpression> PatternFactory::getSpliced(
        std::shared_ptr<Model::IExpression> left,
        std::shared_ptr<Model::IExpression> right)
{
    return Processor::splice(getNextID(), left, right);
}

std::shared_ptr<Model::SimpleExpression> PatternFactory::getMinimized(
        std::shared_ptr<Model::BinaryExpression> expr)
{
    return Processor::minimize(expr);
}

size_t PatternFactory::getNextID()
{
    return mIdCounter++;
}

}
}
