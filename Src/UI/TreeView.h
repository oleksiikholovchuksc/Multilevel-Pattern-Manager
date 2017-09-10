#ifndef TREEVIEW_H
#define TREEVIEW_H

#include "Common/PatternTree.h"
#include <QTreeWidget>

namespace MPM {

class TreeWidgetItem;

class TreeView : public QTreeWidget
{
    Q_OBJECT

public:
    TreeView();

    void addPattern(size_t parentId, const PatternTree& ptree);
    void splicePatterns(size_t sourceId, size_t destId, const PatternTree& ptree);

signals:
    void splicingRequested(size_t id1, size_t id2);
    void selectedIdChanged(size_t selectedId);

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

private slots:
    void handleItemActivated(QTreeWidgetItem *item, int column);

private:
    TreeWidgetItem* itemById(size_t id);
    TreeWidgetItem* searchByIdHelper(TreeWidgetItem* currentItem, size_t targetId);

    size_t mCurrentSelectedId = std::numeric_limits<size_t>::max();
    TreeWidgetItem* mCurrentSelectedItem = nullptr;
};
}

#endif // TREEVIEW_H
