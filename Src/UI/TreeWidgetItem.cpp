#include "TreeWidgetItem.h"

namespace MPM
{

void TreeWidgetItem::setId(size_t id)
{
    mId = id;
}

size_t TreeWidgetItem::id() const
{
    return mId;
}

}
