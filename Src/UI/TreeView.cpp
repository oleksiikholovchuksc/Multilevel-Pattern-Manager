#include "TreeView.h"

#include <QTreeWidgetItem>

namespace MPM {

TreeView::TreeView()
{
    setColumnCount(1);
    setHeaderLabel("Pattern tree");
}
}
