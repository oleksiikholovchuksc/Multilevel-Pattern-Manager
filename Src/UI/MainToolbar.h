#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#include <QToolBar>

namespace MPM {
class MainToolbar : public QToolBar
{
    Q_OBJECT

public:
    MainToolbar();

signals:
    void addObjectRequested();
};
}

#endif // MAINTOOLBAR_H
