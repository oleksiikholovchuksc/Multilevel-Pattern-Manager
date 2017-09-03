#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Common/PatternTree.h"
#include <QMainWindow>

class QPushButton;

namespace MPM {

class ViewWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void addPattern(size_t parentId, const PatternTree& ptree);

signals:
    void addPatternRequest(const QStringList& sequence);
    void splicingRequested(size_t id1, size_t id2);

private:
    void createToolbar();

    QPushButton* mAddObjectButton;
    ViewWidget *mViewWidget;
};

}

#endif // MAINWINDOW_H
