#ifndef NEWPATTERNDIALOG_H
#define NEWPATTERNDIALOG_H

#include <QDialog>

class QLineEdit;

namespace MPM {

class NewPatternDialog : public QDialog
{
    Q_OBJECT

public:
    NewPatternDialog(QWidget *parent = 0);

    QStringList getSequence();
    QString getString();
    void clear();

private:
    QLineEdit *mLine;
};

}

#endif // NEWPATTERNDIALOG_H
