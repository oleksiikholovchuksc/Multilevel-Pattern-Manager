#ifndef BACKENDLAYER_H
#define BACKENDLAYER_H

#include "Common/PatternTree.h"
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

public slots:
    void addPattern(const QStringList& sequence);

private slots:
    void init();

private:
    std::shared_ptr<ProjectContext> mContext;
};

}
}

#endif // BACKENDLAYER_H
