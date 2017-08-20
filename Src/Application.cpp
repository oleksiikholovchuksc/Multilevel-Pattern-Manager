#include "Application.h"
#include "UI/MainWindow.h"
#include "Backend/BackendLayer.h"

namespace MPM {

Application::Application(int argc, char** argv)
    : QApplication(argc, argv)
    , mMainWindow(new MainWindow())
    , mBackendLayer(new Backend::BackendLayer())
{

}

void Application::connectLayers()
{
    connect(mMainWindow, &MainWindow::addObjectRequest, mBackendLayer, &Backend::BackendLayer::addObject);
}

int Application::exec()
{
    mBackendLayer->start();
    mMainWindow->show();

    return QApplication::exec();
}

}
