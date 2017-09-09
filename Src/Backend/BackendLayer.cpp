#include "BackendLayer.h"

#include "ProjectContext.h"
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

void BackendLayer::splice(size_t id1, size_t id2)
{
    mContext->splice(id1, id2);
}

void BackendLayer::init()
{
    mContext = std::make_shared<ProjectContext>();
    connect(mContext.get(), &ProjectContext::patternAdded, this, &BackendLayer::patternAdded);
    connect(mContext.get(), &ProjectContext::patternsSpliced, this, &BackendLayer::patternsSpliced);
}

}
}
