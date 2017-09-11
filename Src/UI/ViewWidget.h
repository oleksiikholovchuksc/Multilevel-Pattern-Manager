#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include "Common/PatternTree.h"
#include "Common/NodeUIData.h"

#include <QWidget>


namespace MPM {

class GraphicsView;
class InspectorView;
class TreeView;

class ViewWidget : public QWidget
{
    Q_OBJECT

public:
    ViewWidget();

    size_t getSelectedId() const;

    void addPattern(size_t parentId, const PatternTree& ptree);
    void splicePatterns(size_t sourceId, size_t destId, const PatternTree& ptree);
    void presentNode(const NodeUIData& data);
    void reparent(size_t sourceId, size_t targetId);
    void minimize(size_t id, const PatternTree& ptree);

signals:
    void splicingRequested(size_t id1, size_t id2);
    void selectedIdChanged(size_t id);
    void reparentingRequested(size_t sourceId, size_t targetId);
    void minimizationRequested(size_t id);

private slots:
    void handleSelectionChanged(size_t id);
    void handleMinimizationRequest();

private:
    void arrangeWidgets();

    GraphicsView *mGraphView;
    InspectorView *mInspectorView;
    TreeView *mTreeView;
    size_t mCurrentSelectedId = std::numeric_limits<size_t>::max();
};

}

#endif // VIEWWIDGET_H
