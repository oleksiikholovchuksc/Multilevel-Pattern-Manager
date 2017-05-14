#pragma once

#include "../Model/LeafNode.hpp"
#include "../Model/SimpleExpression.hpp"
#include "../Model/BinaryExpression.h"
#include "../Processors/PatternProcessor.hpp"
#include "ITest.h"

namespace MPM {
namespace Testing {

class MinimizationTest : public ITest
{
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

        /*
         *    Create S6
         */
        std::vector<std::shared_ptr<Model::IExpression>> S6_args = {
                std::make_shared<Model::LeafNode>('g'),
                std::make_shared<Model::LeafNode>('h')
        };
        std::shared_ptr<Model::SimpleExpression> S6 = std::make_shared<Model::SimpleExpression>(S6_args);

        /*
         *    Create S4
         */
        std::vector<std::shared_ptr<Model::IExpression>> S4_args = {S1->clone(), S6};
        std::shared_ptr<Model::SimpleExpression> S4 = std::make_shared<Model::SimpleExpression>(S4_args);

        /*
         *   Perform splicing
         */
        std::shared_ptr<Model::BinaryExpression> splicedExpr = Processor::splice(S3, S4);

        /*
         *    Perform minimization
         */
        std::shared_ptr<Model::SimpleExpression> minimizedExpr = Processor::minimize(splicedExpr);

        /*
         *    Check result size
         */
        std::vector<std::shared_ptr<Model::IExpression>> minimizedStruct = minimizedExpr->getStructure();
        updateResultVar(result, minimizedStruct.size() == 2);

        /*
         *    Check result types
         */
        std::shared_ptr<Model::SimpleExpression> left = std::dynamic_pointer_cast<Model::SimpleExpression>(minimizedStruct[0]);
        updateResultVar(result, left != nullptr);

        std::shared_ptr<Model::BinaryExpression> right = std::dynamic_pointer_cast<Model::BinaryExpression>(minimizedStruct[1]);
        updateResultVar(result, right != nullptr);

        /*
         *    Check result values
         */
        std::vector<std::shared_ptr<Model::IExpression>> leftStructure = left->getStructure();

        std::shared_ptr<Model::LeafNode> leftLeaf1 = std::dynamic_pointer_cast<Model::LeafNode>(leftStructure[0]);
        updateResultVar(result, leftLeaf1->getValue() == 'a');

        std::shared_ptr<Model::LeafNode> leftLeaf2 = std::dynamic_pointer_cast<Model::LeafNode>(leftStructure[1]);
        updateResultVar(result, leftLeaf2->getValue() == 'b');

        return result;
    }
};

}
}