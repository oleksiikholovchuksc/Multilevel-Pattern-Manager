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

    std::shared_ptr<MPM::Model::SimpleExpression>
    createLowLevelPattern(std::vector<MPM::Model::LeafNode::DataType> sequence);

private:
    std::string getNewNameLowLevel(std::vector<MPM::Model::LeafNode::DataType> sequence);
    size_t getNextID();

    size_t mIdCounter = 0;
};

}
}

#endif // PATTERNFACTORY_H
