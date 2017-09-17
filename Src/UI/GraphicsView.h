#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include "Common/PatternTree.h"
#include <QGraphicsView>

class QGVScene;
class QGVNode;
class QGVEdge;

namespace MPM {
class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView();

    void addPattern(size_t parentId, const PatternTree& ptree);
    void splicePatterns(size_t sourceId, size_t destId, const PatternTree& ptree);
    void reparent(size_t sourceId, size_t destId, const PatternTree& tree);
    void minimize(size_t id, const PatternTree& tree);
    void highlightNode(size_t id);

private:
    QGVNode* unrollTree(std::shared_ptr<PatternTree::Node> node, size_t comp);
    void deleteCompByNodeId(size_t id);

    QGVScene *mScene;
    std::map<size_t, QGVNode*> mNodeMap;
    std::map<QGVNode*, size_t> mNodeMapComp;
    std::map<QGVEdge*, size_t> mEdgesMapComp;
    size_t mSubgraphCount = 0;
};
}
#endif // GRAPHICSVIEW_H
