#include "Application.h"
#include "Common/PatternTree.h"
#include "UI/MainWindow.h"
#include "Backend/BackendLayer.h"

namespace MPM {

Application::Application(int argc, char** argv)
    : QApplication(argc, argv)
    , mMainWindow(new MainWindow())
    , mBackendLayer(new Backend::BackendLayer())
{
    qRegisterMetaType<size_t>("size_t");
    qRegisterMetaType<PatternTree>("PatternTree");
    qRegisterMetaType<NodeUIData>("NodeUIData");
}

void Application::connectLayers()
{
    // add new
    connect(mMainWindow, &MainWindow::addPatternRequest, mBackendLayer, &Backend::BackendLayer::addPattern);
    connect(mBackendLayer, &Backend::BackendLayer::patternAdded, mMainWindow, &MainWindow::addPattern);

    // splice
    connect(mMainWindow, &MainWindow::splicingRequested, mBackendLayer, &Backend::BackendLayer::splice);
    connect(mBackendLayer, &Backend::BackendLayer::patternsSpliced, mMainWindow, &MainWindow::splicePatterns);

    // selection and data moves
    connect(mMainWindow, &MainWindow::selectedIdChanged, mBackendLayer, &Backend::BackendLayer::handleSelectedIdChanged);
    connect(mBackendLayer, &Backend::BackendLayer::currentNodeChanged, mMainWindow, &MainWindow::presentNode);
}

int Application::exec()
{
    mBackendLayer->start();
    mMainWindow->show();

    return QApplication::exec();
}

}
