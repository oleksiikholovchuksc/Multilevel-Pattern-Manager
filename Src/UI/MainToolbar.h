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
    void removeRequested();

private slots:
    void requestNewPattern();

private:
    QPushButton *mAddButton;
    QPushButton *mRemoveButton;
    NewPatternDialog *mDialog;
};
}

#endif // MAINTOOLBAR_H
