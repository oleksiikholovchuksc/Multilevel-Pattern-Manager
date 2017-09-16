#include "GraphicsView.h"

#include <QGraphicsScene>


namespace MPM {
GraphicsView::GraphicsView()
    : mScene(new QGraphicsScene(this))
{
    setScene(mScene);
}
}
