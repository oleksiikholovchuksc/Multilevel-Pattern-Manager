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
};
}

#endif // TREEVIEW_H
