#include "Application.h"


int main(int argc, char *argv[])
{
    MPM::Application app(argc, argv);
    app.connectLayers();
    return app.exec();
}
