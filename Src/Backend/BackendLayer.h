#ifndef BACKENDLAYER_H
#define BACKENDLAYER_H

#include <QThread>


namespace MPM {
namespace Backend {

class BackendLayer : public QThread
{
    Q_OBJECT

public:
    BackendLayer();

public slots:
    void addObject(size_t parentId);

private slots:
    void init();
};

}
}

#endif // BACKENDLAYER_H
