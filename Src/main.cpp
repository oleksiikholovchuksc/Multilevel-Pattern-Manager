#include <iostream>

#include "Tests/MinimizationTest.hpp"
#include "Tests/SplicingTest.hpp"

int main()
{
    MPM::Testing::SplicingTest t1;
    std::cout << "Splicing test: " << t1.exec() << std::endl;

    MPM::Testing::MinimizationTest t2;
    std::cout << "Minimization test: " << t2.exec() << std::endl;

    return 0;
}