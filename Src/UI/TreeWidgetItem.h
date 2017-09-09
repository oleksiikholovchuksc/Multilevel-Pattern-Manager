#ifndef TREEWIDGETITEM_H
#define TREEWIDGETITEM_H

#include <QTreeWidgetItem>
#include <climits>

namespace MPM {

class TreeWidgetItem : public QTreeWidgetItem
{
public:
    void setId(size_t id);
    size_t id() const;

private:
    size_t mId = std::numeric_limits<size_t>::max();
};

}

#endif // TREEWIDGETITEM_H
