#include "ViewWidget.h"

#include "GraphicsView.h"
#include "InspectorView.h"
#include "TreeView.h"

#include <QHBoxLayout>
#include <QDebug>

namespace MPM {

ViewWidget::ViewWidget()
    : mGraphView(new GraphicsView())
    , mInspectorView(new InspectorView())
    , mTreeView(new TreeView())
{
    arrangeWidgets();
}

size_t ViewWidget::getSelectedId() const
{
    // NIY

    return 123;
}

void ViewWidget::addPattern(size_t parentId, const PatternTree &ptree)
{
    mTreeView->addPattern(parentId, ptree);
}

void ViewWidget::splicePatterns(size_t sourceId, size_t destId, const PatternTree &ptree)
{
    mTreeView->splicePatterns(sourceId, destId, ptree);
}

void ViewWidget::arrangeWidgets()
{
    // lay it out
    auto hLayout = new QHBoxLayout();
    setLayout(hLayout);
    hLayout->addWidget(mTreeView);
    hLayout->addWidget(mGraphView);
    hLayout->addWidget(mInspectorView);

    mTreeView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    mGraphView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mInspectorView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    mTreeView->setFixedWidth(250);
    mInspectorView->setFixedWidth(250);

    connect(mTreeView, &TreeView::splicingRequested, this, &ViewWidget::splicingRequested);
}

}
