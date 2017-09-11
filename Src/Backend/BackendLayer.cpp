#include "BackendLayer.h"

#include "ProjectContext.h"
#include "NodeDataCreator.h"

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

void BackendLayer::handleSelectedIdChanged(size_t id)
{
    auto expr = mContext->getExpr(id);
    emit currentNodeChanged(NodeDataCreator::createData(expr));
}

void BackendLayer::reparent(size_t sourceId, size_t targetId)
{
    mContext->reparent(sourceId, targetId);
}

void BackendLayer::minimize(size_t id)
{
    mContext->minimize(id);
}

void BackendLayer::remove(size_t id)
{
    mContext->remove(id);
}

void BackendLayer::init()
{
    mContext = std::make_shared<ProjectContext>();
    connect(mContext.get(), &ProjectContext::patternAdded, this, &BackendLayer::patternAdded);
    connect(mContext.get(), &ProjectContext::patternsSpliced, this, &BackendLayer::patternsSpliced);
    connect(mContext.get(), &ProjectContext::reparented, this, &BackendLayer::reparented);
    connect(mContext.get(), &ProjectContext::minimized, this, &BackendLayer::minimized);
}

}
}
