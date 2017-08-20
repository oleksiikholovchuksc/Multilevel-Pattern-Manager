#ifndef BACKENDLAYER_H
#define BACKENDLAYER_H

#include <QThread>


namespace MPM {
namespace Backend {

class BackendLayer : public QThread
{
public:
    BackendLayer();

public slots:
    void addObject(int parentId);

private slots:
    void init();
};

}
}

#endif // BACKENDLAYER_H
