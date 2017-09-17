#include "GraphicsView.h"

#include "QGV/QGVScene.h"
#include "QGV/QGVNode.h"
#include "QGV/QGVSubGraph.h"

#include <QGraphicsScene>


namespace MPM {

GraphicsView::GraphicsView()
    : mScene(new QGVScene("Graph scene", this))
{
    setScene(mScene);
}

void GraphicsView::addPattern(size_t parentId, const PatternTree &ptree)
{
    Q_UNUSED(parentId);

    unrollTree(ptree.getRootNode(), mSubgraphCount++);
    mScene->applyLayout();
}

void GraphicsView::splicePatterns(size_t sourceId, size_t destId, const PatternTree &ptree)
{
    deleteCompByNodeId(sourceId);
    deleteCompByNodeId(destId);

    addPattern(std::numeric_limits<size_t>::max(), ptree);
}

QGVNode *GraphicsView::unrollTree(std::shared_ptr<PatternTree::Node> node, size_t comp)
{
    if(!node || !mScene)
        return nullptr;

    auto qgvNode = mScene->addNode(QString::fromStdString(node->name));
    mNodeMap[node->id] = qgvNode;
    mNodeMapComp[qgvNode] = comp;

    for(auto child : node->children)
    {
        if(auto qgvChild = unrollTree(child, comp))
        {
            auto edge = mScene->addEdge(qgvNode, qgvChild);
            mEdgesMapComp.insert(std::make_pair(edge, comp));
        }
    }

    return qgvNode;
}

void GraphicsView::deleteCompByNodeId(size_t id)
{
    size_t compId = mNodeMapComp[mNodeMap[id]];

    auto size = mEdgesMapComp.size();
    (void)size;

    std::vector<QGVEdge*> edgeDeathList;
    for(auto item : mEdgesMapComp)
    {
        if(item.second == compId)
        {
            edgeDeathList.push_back(item.first);
        }
    }

    for(auto e : edgeDeathList)
    {
        mEdgesMapComp.erase(e);
        mScene->deleteEdge(e);
    }

    std::vector<QGVNode*> nodeDeathList;
    for(auto item : mNodeMapComp)
    {
        if(item.second == compId)
        {
            nodeDeathList.push_back(item.first);
        }
    }

    for(auto n : nodeDeathList)
    {
        mNodeMapComp.erase(n);
        mScene->deleteNode(n);
    }
}
}
