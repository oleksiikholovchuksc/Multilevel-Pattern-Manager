cmake_minimum_required(VERSION 3.7)
project(Src)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        Model/IExpression.hpp
        Model/LeafNode.cpp
        Model/LeafNode.hpp
        Model/SimpleExpression.cpp
        Model/SimpleExpression.hpp
        Model/BinaryExpression.cpp
        Model/BinaryExpression.h
        Processors/PatternProcessor.cpp
        Processors/PatternProcessor.hpp
        Tests/ITest.h
        Tests/SplicingTest.hpp
        Tests/MinimizationTest.hpp)

add_executable(Src ${SOURCE_FILES})