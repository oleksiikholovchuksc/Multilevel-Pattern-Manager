#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>


namespace MPM {
class MainWindow;

namespace Backend {
class BackendLayer;
}
}

namespace MPM {
class Application : public QApplication
{
public:
    Application(int argc, char** argv);

    void connectLayers();
    int exec();

private:
    MainWindow *mMainWindow;
    Backend::BackendLayer *mBackendLayer;
};
}

#endif // APPLICATION_H
