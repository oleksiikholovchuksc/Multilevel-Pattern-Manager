#include "TreeView.h"

#include "TreeWidgetItem.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDebug>

namespace MPM {

TreeWidgetItem* unrollTree(TreeWidgetItem* parent, std::shared_ptr<PatternTree::Node> node)
{
    if(!node)
        return nullptr;

    TreeWidgetItem *item = new TreeWidgetItem();
    item->setText(0, QString::fromStdString(node->name));
    item->setId(node->id);
    if(parent)
    {
        parent->addChild(item);
    }

    for(auto nodeChild : node->children)
    {
        unrollTree(item, nodeChild);
    }

    return item;
}

TreeView::TreeView()
{
    setHeaderLabel("Pattern tree");
    setColumnCount(1);
    setAcceptDrops(true);
    setDragDropMode(QAbstractItemView::DragDrop);
    setSelectionBehavior(QAbstractItemView::SelectItems);
    setSelectionMode(QAbstractItemView::SingleSelection);

    connect(this, &QTreeWidget::itemPressed, this, &TreeView::handleItemActivated);
}

void TreeView::addPattern(size_t parentId, const PatternTree &ptree)
{
    Q_UNUSED(parentId);

    std::shared_ptr<PatternTree::Node> rootNode = ptree.getRootNode();
    auto item = unrollTree(nullptr, rootNode);
    addTopLevelItem(item);
    expandItem(item);
}

void TreeView::splicePatterns(size_t sourceId, size_t destId, const PatternTree &ptree)
{
    // ensure correctness
    auto sourceItem = itemById(sourceId);
    auto destItem = itemById(destId);
    if(!sourceItem || !destItem)
    {
        qWarning() << "Can't splice on UI side.";
        return;
    }

    // remove source
    removeItemWidget(sourceItem, 0);
    delete sourceItem;

    // find pos of dest
    int destPos = 0;
    for(int i = 0; i < topLevelItemCount(); ++i, ++destPos)
    {
        auto child = dynamic_cast<TreeWidgetItem*>(topLevelItem(i));
        if(child && child->id() == destId)
            break;
    }

    // remove dest
    removeItemWidget(destItem, 0);
    delete destItem;

    // place new item to destPos
    auto splicedItem = unrollTree(nullptr, ptree.getRootNode());
    insertTopLevelItem(destPos, splicedItem);
    expandItem(splicedItem);
}

void TreeView::dragEnterEvent(QDragEnterEvent *e)
{
    TreeWidgetItem* sourceItem = mCurrentSelectedItem;
    if(sourceItem)
    {
        auto* mimeData = const_cast<QMimeData*>(e->mimeData());
        if(mimeData)
            mimeData->setText(QString::number(sourceItem->id()));
    }

    QTreeWidget::dragEnterEvent(e);
}

void TreeView::dropEvent(QDropEvent *e)
{
    QTreeWidgetItem* targetQItem = itemAt((e->pos()));
    TreeWidgetItem* targetItem = dynamic_cast<TreeWidgetItem*>(targetQItem);
    if(targetItem)
    {
        auto* mimeData = const_cast<QMimeData*>(e->mimeData());
        if(mimeData)
        {
            std::string sourceIdStr = mimeData->text().toStdString();
            size_t sourceId = std::numeric_limits<size_t>::max();
            sscanf(sourceIdStr.c_str(), "%zu", &sourceId);

            size_t targetId = targetItem->id();

            emit splicingRequested(sourceId, targetId);
        }
    }

    // QTreeWidget::dropEvent(e);  // not called intentionally
}

void TreeView::handleItemActivated(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);

    auto myItem = dynamic_cast<TreeWidgetItem*>(item);
    if(myItem)
    {
        mCurrentSelectedId = myItem->id();
        mCurrentSelectedItem = myItem;
        emit selectedIdChanged(mCurrentSelectedId);
    }
}

TreeWidgetItem *TreeView::itemById(size_t id)
{
    for(int i = 0; i < invisibleRootItem()->childCount(); ++i)
    {
        auto child = dynamic_cast<TreeWidgetItem*>(invisibleRootItem()->child(i));
        if(!child)
            continue;

        if(auto result = searchByIdHelper(child, id))
            return result;
    }

    return nullptr;
}

TreeWidgetItem *TreeView::searchByIdHelper(TreeWidgetItem *currentItem, size_t targetId)
{
    if(!currentItem)
        return nullptr;

    if(currentItem->id() == targetId)
        return currentItem;

    for(int i = 0; i < currentItem->childCount(); ++i)
    {
        auto child = dynamic_cast<TreeWidgetItem*>(currentItem->child(i));
        if(!child)
            continue;

        if(auto result = searchByIdHelper(child, targetId))
            return result;
    }

    return nullptr;
}

}
