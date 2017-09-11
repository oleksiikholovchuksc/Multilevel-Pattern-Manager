#ifndef PATTERNFACTORY_H
#define PATTERNFACTORY_H

#include "Backend/Model/LeafNode.hpp"

#include <vector>
#include <memory>

// forw decl
namespace MPM {
    namespace Model {
        class BinaryExpression;
    }
}

namespace MPM {
namespace Backend {

class PatternFactory
{
public:
    PatternFactory();

    std::shared_ptr<Model::SimpleExpression>
    createLowLevelPattern(std::vector<Model::LeafNode::DataType> sequence);

    std::shared_ptr<Model::BinaryExpression>
    getSpliced(std::shared_ptr<Model::IExpression> left, std::shared_ptr<Model::IExpression> right);

    std::shared_ptr<Model::SimpleExpression> getMinimized(std::shared_ptr<Model::BinaryExpression> expr);

private:
    size_t getNextID();
    size_t mIdCounter = 0;
};

}
}

#endif // PATTERNFACTORY_H
