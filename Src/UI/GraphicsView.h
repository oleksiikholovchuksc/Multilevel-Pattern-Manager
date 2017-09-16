#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class QGraphicsScene;

namespace MPM {
class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView();



private:
    QGraphicsScene *mScene;
};
}
#endif // GRAPHICSVIEW_H
