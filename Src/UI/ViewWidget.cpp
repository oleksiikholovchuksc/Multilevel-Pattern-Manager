#include "ViewWidget.h"

#include "GraphicsView.h"
#include "InspectorView.h"
#include "TreeView.h"

#include <QHBoxLayout>

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
    return 123;
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
}

}
