#include "BackendLayer.h"

#include <QDebug>

namespace MPM {
namespace Backend {

BackendLayer::BackendLayer()
{
    moveToThread(this);
    connect(this, &BackendLayer::started, this, &BackendLayer::init);
}

void BackendLayer::addObject(int parentId)
{
    qDebug() << QThread::currentThreadId() << " parent id " << parentId;
}

void BackendLayer::init()
{

}

}
}
