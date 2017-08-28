#include "BackendLayer.h"

#include <QDebug>

namespace MPM {
namespace Backend {

BackendLayer::BackendLayer()
{
    moveToThread(this);

    connect(this, &BackendLayer::started, this, &BackendLayer::init);
}

void BackendLayer::addPattern(const QStringList &sequence)
{
    mContext->addPattern(sequence);
}

void BackendLayer::init()
{
    mContext = std::make_shared<ProjectContext>();
}

}
}
