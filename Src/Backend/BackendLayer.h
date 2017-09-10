#ifndef BACKENDLAYER_H
#define BACKENDLAYER_H

#include "Common/PatternTree.h"
#include "Common/NodeUIData.h"

#include <QThread>
#include <memory>

namespace MPM {
namespace Backend {

class ProjectContext;

class BackendLayer : public QThread
{
    Q_OBJECT

public:
    BackendLayer();

signals:
    void patternAdded(size_t parentId, const PatternTree& ptree);
    void patternsSpliced(size_t sourceId, size_t destinationId, const PatternTree& splicedTree);
    void currentNodeChanged(const NodeUIData& data);
    void reparented(size_t sourceId, size_t destId);

public slots:
    void addPattern(const QStringList& sequence);
    void splice(size_t id1, size_t id2);
    void handleSelectedIdChanged(size_t id);
    void reparent(size_t sourceId, size_t targetId);

private slots:
    void init();

private:
    std::shared_ptr<ProjectContext> mContext;
};

}
}

#endif // BACKENDLAYER_H
