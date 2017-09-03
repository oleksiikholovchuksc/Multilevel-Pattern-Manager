#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include "Common/PatternTree.h"
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

signals:
    void splicingRequested(size_t id1, size_t id2);

private:
    void arrangeWidgets();

    GraphicsView *mGraphView;
    InspectorView *mInspectorView;
    TreeView *mTreeView;
};

}

#endif // VIEWWIDGET_H
