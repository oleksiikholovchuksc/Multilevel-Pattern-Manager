cmake_minimum_required(VERSION 3.7)
project(Src)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Model/IExpression.hpp
        Model/LeafNode.cpp
        Model/LeafNode.hpp
        Model/main.cpp
        Model/SimpleExpression.cpp
        Model/SimpleExpression.hpp)

add_executable(Src ${SOURCE_FILES})