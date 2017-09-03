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
    setDragEnabled(true);
    setAcceptDrops(true);
    setDragDropMode(QAbstractItemView::DragDrop);
}

void TreeView::addPattern(size_t parentId, const PatternTree &ptree)
{
    Q_UNUSED(parentId);

    std::shared_ptr<PatternTree::Node> rootNode = ptree.getRootNode();
    auto item = unrollTree(nullptr, rootNode);
    addTopLevelItem(item);
    expandItem(item);


}

void TreeView::dragEnterEvent(QDragEnterEvent *e)
{
    QTreeWidgetItem* sourceQItem = itemAt(e->pos());
    TreeWidgetItem* sourceItem = dynamic_cast<TreeWidgetItem*>(sourceQItem);
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
    QTreeWidgetItem* targetQItem = itemAt(e->pos());
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

}
