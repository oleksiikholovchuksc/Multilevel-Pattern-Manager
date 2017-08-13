#-------------------------------------------------
#
# Project created by QtCreator 2017-01-01T02:04:19
#
#-------------------------------------------------

QT += core gui widgets

TARGET = Multilevel-Pattern-Manager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Src/main.cpp \
    Src/UI/MainWindow.cpp \
    Src/Model/BinaryExpression.cpp \
    Src/Model/LeafNode.cpp \
    Src/Model/SimpleExpression.cpp \
    Src/Processors/PatternProcessor.cpp

HEADERS += \
    Src/UI/MainWindow.h \
    Src/Model/BinaryExpression.h \
    Src/Model/IExpression.hpp \
    Src/Model/LeafNode.hpp \
    Src/Model/SimpleExpression.hpp \
    Src/Processors/PatternProcessor.hpp \
    Src/Tests/ITest.h \
    Src/Tests/MinimizationTest.hpp \
    Src/Tests/SplicingTest.hpp

QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic -Wold-style-cast -Werror
