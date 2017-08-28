#include "Application.h"
#include "UI/MainWindow.h"
#include "Backend/BackendLayer.h"

namespace MPM {

Application::Application(int argc, char** argv)
    : QApplication(argc, argv)
    , mMainWindow(new MainWindow())
    , mBackendLayer(new Backend::BackendLayer())
{
    qRegisterMetaType<size_t>("size_t");
}

void Application::connectLayers()
{
    connect(mMainWindow, &MainWindow::addPatternRequest, mBackendLayer, &Backend::BackendLayer::addPattern);
}

int Application::exec()
{
    mBackendLayer->start();
    mMainWindow->show();

    return QApplication::exec();
}

}
