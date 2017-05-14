#pragma once

#include "../Model/LeafNode.hpp"
#include "../Model/SimpleExpression.hpp"
#include "../Model/BinaryExpression.h"
#include "ITest.h"

namespace MPM {
namespace Testing {

class MinimizationTest : public ITest
{
public:
    bool exec() override {
        bool result = true;

        return result;
    }
};

}
}