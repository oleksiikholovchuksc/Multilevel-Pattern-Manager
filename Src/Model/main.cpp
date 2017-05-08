#include "LeafNode.hpp"

#include <iostream>

int main()
{
    MPM::Model::IExpression* expr = new MPM::Model::SimpleExpression;
    (void)expr;

    auto leaf = std::make_shared<MPM::Model::LeafNode>('c');
    std::cout << "Leaf value: " << leaf->getValue();

    return 0;
}