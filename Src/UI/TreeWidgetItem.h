#ifndef TREEWIDGETITEM_H
#define TREEWIDGETITEM_H

#include <QTreeWidgetItem>

namespace MPM {

class TreeWidgetItem : public QTreeWidgetItem
{
public:
    void setId(size_t id);
    size_t id() const;

private:
    size_t mId;
};

}

#endif // TREEWIDGETITEM_H
