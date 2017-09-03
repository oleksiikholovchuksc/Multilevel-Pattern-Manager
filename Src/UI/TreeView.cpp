#include "TreeView.h"

#include "TreeWidgetItem.h"
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
    setColumnCount(1);
    setHeaderLabel("Pattern tree");
}

void TreeView::addPattern(size_t parentId, const PatternTree &ptree)
{
    Q_UNUSED(parentId);

    std::shared_ptr<PatternTree::Node> rootNode = ptree.getRootNode();
    addTopLevelItem(unrollTree(nullptr, rootNode));
}

}
