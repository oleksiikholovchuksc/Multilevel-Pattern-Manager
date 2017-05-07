#include "LeafNode.hpp"

int main()
{
    MPM::Model::IExpression* expr = new MPM::Model::SimpleExpression;
    (void)expr;

    MPM::Model::IExpression* leaf = new MPM::Model::LeafNode('c');
    (void)leaf;

    return 0;
}