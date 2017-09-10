#-------------------------------------------------
#
# Project created by QtCreator 2017-01-01T02:04:19
#
#-------------------------------------------------

QT += core gui widgets

CONFIG += c++14

TARGET = Multilevel-Pattern-Manager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += Src/

SOURCES += \
    Src/main.cpp \
    Src/UI/MainWindow.cpp \
    Src/Backend/Model/BinaryExpression.cpp \
    Src/Backend/Model/LeafNode.cpp \
    Src/Backend/Model/SimpleExpression.cpp \
    Src/Backend/Processors/PatternProcessor.cpp \
    Src/Backend/BackendLayer.cpp \
    Src/Application.cpp \
    Src/UI/ViewWidget.cpp \
    Src/UI/TreeView.cpp \
    Src/UI/GraphicsView.cpp \
    Src/UI/InspectorView.cpp \
    Src/UI/MainToolbar.cpp \
    Src/Backend/ProjectContext.cpp \
    Src/UI/NewPatternDialog.cpp \
    Src/Backend/PatternFactory.cpp \
    Src/Utils.cpp \
    Src/Common/PatternTree.cpp \
    Src/Backend/BackUtilsUtils.cpp \
    Src/UI/TreeWidgetItem.cpp \
    Src/Backend/NodeDataCreator.cpp

HEADERS += \
    Src/UI/MainWindow.h \
    Src/Backend/Model/BinaryExpression.h \
    Src/Backend/Model/IExpression.hpp \
    Src/Backend/Model/LeafNode.hpp \
    Src/Backend/Model/SimpleExpression.hpp \
    Src/Backend/Processors/PatternProcessor.hpp \
    Src/Tests/ITest.h \
    Src/Tests/MinimizationTest.hpp \
    Src/Tests/SplicingTest.hpp \
    Src/Backend/BackendLayer.h \
    Src/Application.h \
    Src/UI/ViewWidget.h \
    Src/UI/TreeView.h \
    Src/UI/GraphicsView.h \
    Src/UI/InspectorView.h \
    Src/UI/MainToolbar.h \
    Src/Backend/ProjectContext.h \
    Src/UI/NewPatternDialog.h \
    Src/Backend/PatternFactory.h \
    Src/Utils.h \
    Src/Common/PatternTree.h \
    Src/Backend/BackUtilsUtils.h \
    Src/UI/TreeWidgetItem.h \
    Src/Common/NodeUIData.h \
    Src/Backend/NodeDataCreator.h

mac {
    QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic -Wold-style-cast -Werror
}

RESOURCES += \
    resources.qrc
