#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

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

private:
    void arrangeWidgets();

    GraphicsView *mGraphView;
    InspectorView *mInspectorView;
    TreeView *mTreeView;
};

}

#endif // VIEWWIDGET_H
