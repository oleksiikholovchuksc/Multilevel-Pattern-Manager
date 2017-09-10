#include "TreeWidgetItem.h"

namespace MPM
{

TreeWidgetItem::TreeWidgetItem()
{

}

TreeWidgetItem::TreeWidgetItem(const QTreeWidgetItem& other)
    : QTreeWidgetItem(other)
{

}

void TreeWidgetItem::setId(size_t id)
{
    mId = id;
}

size_t TreeWidgetItem::id() const
{
    return mId;
}

}
