#include "MainWindow.h"

#include "ViewWidget.h"
#include "MainToolbar.h"

#include <QPushButton>
#include <QToolBar>
#include <QThread>
#include <QDebug>

namespace MPM {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mAddObjectButton(new QPushButton("Create object"))
    , mViewWidget(new ViewWidget())
{
    setMinimumSize(500, 500);
    showMaximized();

    createToolbar();

    setCentralWidget(mViewWidget);

    connect(mViewWidget, &ViewWidget::splicingRequested, this, &MainWindow::splicingRequested);
}

void MainWindow::addPattern(size_t parentId, const PatternTree &ptree)
{
    mViewWidget->addPattern(parentId, ptree);
}

void MainWindow::splicePatterns(size_t sourceId, size_t destId, const PatternTree &ptree)
{
    mViewWidget->splicePatterns(sourceId, destId, ptree);
}

void MainWindow::createToolbar()
{
    MainToolbar *toolbar = new MainToolbar();
    addToolBar(Qt::TopToolBarArea, toolbar);
    connect(toolbar, &MainToolbar::addPatternRequested, this, &MainWindow::addPatternRequest);
}

}
