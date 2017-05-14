#pragma once

#include "../Model/LeafNode.hpp"
#include "../Model/SimpleExpression.hpp"
#include "../Model/BinaryExpression.h"
#include "../Processors/PatternProcessor.hpp"
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
         *    Perform splicing
         */
        std::shared_ptr<Model::BinaryExpression> splicedExpr = Processor::splice(S3, S4);

        /*
         *    Check operands equality
         */
        auto left = splicedExpr->getOperands()[0];
        updateResultVar(result, left->isEqual(S3.get()));

        auto right = splicedExpr->getOperands()[1];
        updateResultVar(result, right->isEqual(S4.get()));

        auto leftSimpleExpr = dynamic_cast<const Model::SimpleExpression*>(left);
        updateResultVar(result, leftSimpleExpr);

        auto rightSimpleExpr = dynamic_cast<const Model::SimpleExpression*>(right);
        updateResultVar(result, rightSimpleExpr);

        std::vector<std::shared_ptr<Model::IExpression>> leftStructure = leftSimpleExpr->getStructure();
        updateResultVar(result, leftStructure.size() == 2);

        std::vector<std::shared_ptr<Model::IExpression>> rightStructure = rightSimpleExpr->getStructure();
        updateResultVar(result, rightStructure.size() == 2);

        updateResultVar(result, leftStructure[0]->isEqual(S1.get()));
        updateResultVar(result, leftStructure[1]->isEqual(S2.get()));

        return result;
    }
};

}
}

