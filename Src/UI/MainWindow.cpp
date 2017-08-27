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
}

void MainWindow::createToolbar()
{
    MainToolbar *toolbar = new MainToolbar();
    addToolBar(Qt::TopToolBarArea, toolbar);
    connect(toolbar, &MainToolbar::addObjectRequested,
            [this]() { emit addObjectRequest(mViewWidget->getSelectedId()); });
}

}
