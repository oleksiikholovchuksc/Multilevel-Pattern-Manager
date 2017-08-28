#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#include <QToolBar>

class QPushButton;

namespace MPM {

class NewPatternDialog;

class MainToolbar : public QToolBar
{
    Q_OBJECT

public:
    MainToolbar();

signals:
    void addPatternRequested(const QStringList& sequence);

private slots:
    void requestNewPattern();

private:
    QPushButton *mAddButton;
    NewPatternDialog *mDialog;
};
}

#endif // MAINTOOLBAR_H
