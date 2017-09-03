#ifndef TREEVIEW_H
#define TREEVIEW_H

#include "Common/PatternTree.h"
#include <QTreeWidget>

namespace MPM {
class TreeView : public QTreeWidget
{
    Q_OBJECT

public:
    TreeView();

    void addPattern(size_t parentId, const PatternTree& ptree);

signals:
    void splicingRequested(size_t id1, size_t id2);

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
};
}

#endif // TREEVIEW_H
