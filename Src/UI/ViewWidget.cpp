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
    return mCurrentSelectedId;
}

void ViewWidget::addPattern(size_t parentId, const PatternTree &ptree)
{
    mTreeView->addPattern(parentId, ptree);
}

void ViewWidget::splicePatterns(size_t sourceId, size_t destId, const PatternTree &ptree)
{
    mTreeView->splicePatterns(sourceId, destId, ptree);
}

void ViewWidget::presentNode(const NodeUIData &data)
{
    mInspectorView->presentNode(data);
}

void ViewWidget::reparent(size_t sourceId, size_t targetId)
{
    mTreeView->reparent(sourceId, targetId);
}

void ViewWidget::minimize(size_t id, const PatternTree &ptree)
{
    mTreeView->minimize(id, ptree);
}

void ViewWidget::handleSelectionChanged(size_t id)
{
    if(id != mCurrentSelectedId)
    {
        mCurrentSelectedId = id;
        emit selectedIdChanged(mCurrentSelectedId);
    }
}

void ViewWidget::handleMinimizationRequest()
{
    emit minimizationRequested(mCurrentSelectedId);
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

    mTreeView->setFixedWidth(350);
    mInspectorView->setFixedWidth(350);

    connect(mTreeView, &TreeView::splicingRequested, this, &ViewWidget::splicingRequested);
    connect(mTreeView, &TreeView::selectedIdChanged, this, &ViewWidget::handleSelectionChanged);
    connect(mTreeView, &TreeView::reparentingRequested, this, &ViewWidget::reparentingRequested);

    connect(mInspectorView, &InspectorView::minimizationRequested, this, &ViewWidget::handleMinimizationRequest);
}

}
