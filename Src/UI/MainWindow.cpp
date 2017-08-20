#include "MainWindow.h"

#include <QPushButton>
#include <QToolBar>
#include <QThread>
#include <QDebug>

namespace MPM {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mAddObjectButton(new QPushButton("Create object"))
{
    createToolbar();
}

void MainWindow::createToolbar()
{
    QToolBar *toolbar = new QToolBar();
    addToolBar(Qt::TopToolBarArea, toolbar);

    toolbar->addWidget(mAddObjectButton);
    connect(mAddObjectButton, &QPushButton::clicked, [this]() {
        qDebug() << QThread::currentThreadId() << " ui ui ui";
        emit addObjectRequest(-1);
    });
}

}
