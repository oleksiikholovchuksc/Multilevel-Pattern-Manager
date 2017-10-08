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
    void recognitionRequested(const QString& string);
    void removeRequested();

private slots:
    void requestNewPattern();
    void requestRecognition();

private:
    QPushButton *mAddButton;
    QPushButton *mRecognizeButton;
    NewPatternDialog *mDialog;
    NewPatternDialog *mRecognitionDialog;
};
}

#endif // MAINTOOLBAR_H
