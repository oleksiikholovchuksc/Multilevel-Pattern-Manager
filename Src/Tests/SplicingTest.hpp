#pragma once

#include "../Model/LeafNode.hpp"
#include "../Model/SimpleExpression.hpp"
#include "../Model/BinaryExpression.h"
#include "ITest.h"

namespace MPM {
namespace Testing {

class SplicingTest : public ITest {
public:
    bool exec() override {
        bool result = true;

        /*
     *    Create S1
     */
        std::vector<std::shared_ptr<Model::IExpression>> S1_args = {
                std::make_shared<Model::LeafNode>('a'),
                std::make_shared<Model::LeafNode>('b')
        };
        std::shared_ptr<Model::SimpleExpression> S1 = std::make_shared<Model::SimpleExpression>(S1_args);

        /*
         *    Create S2
         */
        std::vector<std::shared_ptr<Model::IExpression>> S2_args = {
                std::make_shared<Model::LeafNode>('c'),
                std::make_shared<Model::LeafNode>('d')
        };
        std::shared_ptr<Model::SimpleExpression> S2 = std::make_shared<Model::SimpleExpression>(S2_args);

        /*
         *    Create S3
         */
        std::vector<std::shared_ptr<Model::IExpression>> S3_args = { S1, S2 };
        std::shared_ptr<Model::SimpleExpression> S3 = std::make_shared<Model::SimpleExpression>(S3_args);


        return result;
    }
};

}
}

