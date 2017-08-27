#include "BackendLayer.h"

#include <QDebug>

namespace MPM {
namespace Backend {

BackendLayer::BackendLayer()
{
    moveToThread(this);

    connect(this, &BackendLayer::started, this, &BackendLayer::init);
}

void BackendLayer::addObject(size_t)
{

}

void BackendLayer::init()
{

}

}
}
