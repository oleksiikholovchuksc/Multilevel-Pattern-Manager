#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;

namespace MPM {

class ViewWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

signals:
    void addObjectRequest(size_t parentId);

private:
    void createToolbar();

    QPushButton* mAddObjectButton;
    ViewWidget *mViewWidget;
};

}

#endif // MAINWINDOW_H
