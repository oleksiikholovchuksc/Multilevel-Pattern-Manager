#include "MainWindow.h"

#include "ViewWidget.h"
#include "MainToolbar.h"

#include <QStatusBar>
#include <QPushButton>
#include <QToolBar>
#include <QThread>
#include <QDebug>

namespace MPM {

static const int STATUSBAR_MSG_TIMEOUT = 6;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mAddObjectButton(new QPushButton("Create object"))
    , mViewWidget(new ViewWidget())
{
    setMinimumSize(500, 500);
    showMaximized();

    createToolbar();
    createStatusBar();

    setCentralWidget(mViewWidget);

    connect(mViewWidget, &ViewWidget::splicingRequested, this, &MainWindow::splicingRequested);
    connect(mViewWidget, &ViewWidget::selectedIdChanged, this, &MainWindow::selectedIdChanged);
    connect(mViewWidget, &ViewWidget::reparentingRequested, this, &MainWindow::reparentingRequested);
}

void MainWindow::showStatusBarMessage(const QString &msg)
{
    if(statusBar())
        statusBar()->showMessage(msg, STATUSBAR_MSG_TIMEOUT);
}

void MainWindow::addPattern(size_t parentId, const PatternTree &ptree)
{
    mViewWidget->addPattern(parentId, ptree);
}

void MainWindow::splicePatterns(size_t sourceId, size_t destId, const PatternTree &ptree)
{
    mViewWidget->splicePatterns(sourceId, destId, ptree);
}

void MainWindow::presentNode(const NodeUIData &data)
{
    mViewWidget->presentNode(data);
}

void MainWindow::reparent(size_t sourceId, size_t targetId)
{
    mViewWidget->reparent(sourceId, targetId);
}

void MainWindow::createToolbar()
{
    MainToolbar *toolbar = new MainToolbar();
    addToolBar(Qt::TopToolBarArea, toolbar);
    connect(toolbar, &MainToolbar::addPatternRequested, this, &MainWindow::addPatternRequest);
}

void MainWindow::createStatusBar()
{
    QStatusBar *statusBar = new QStatusBar();
    setStatusBar(statusBar);
}

}
