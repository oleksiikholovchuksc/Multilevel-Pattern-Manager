#include "NewPatternDialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>

namespace MPM {

NewPatternDialog::NewPatternDialog(QWidget *parent)
    : QDialog(parent)
    , mLine(new QLineEdit())
{
    // top
    QLabel *label = new QLabel("Enter pattern sequence:");

    QHBoxLayout *hLayout = new QHBoxLayout();

    hLayout->addWidget(label);
    hLayout->addWidget(mLine);

    // bot
    QDialogButtonBox *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(box, &QDialogButtonBox::accepted, this, &NewPatternDialog::accept);
    connect(box, &QDialogButtonBox::rejected, this, &NewPatternDialog::reject);

    // lay
    QVBoxLayout *vLayout = new QVBoxLayout();
    setLayout(vLayout);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(box);
}

QStringList NewPatternDialog::getSequence()
{
    if(!mLine)
        return {};

    return mLine->text().split(' ');
}

void NewPatternDialog::clear()
{
    if(mLine) mLine->clear();
}

}
