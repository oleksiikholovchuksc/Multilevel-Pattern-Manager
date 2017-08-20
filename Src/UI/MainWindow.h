#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;

namespace MPM {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

signals:
    void addObjectRequest(int parentId);

private:
    void createToolbar();

    QPushButton* mAddObjectButton;
};

}

#endif // MAINWINDOW_H
