#include "StringInputDialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>

namespace MPM {

StringInputDialog::StringInputDialog(QWidget *parent)
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
    connect(box, &QDialogButtonBox::accepted, this, &StringInputDialog::accept);
    connect(box, &QDialogButtonBox::rejected, this, &StringInputDialog::reject);

    // lay
    QVBoxLayout *vLayout = new QVBoxLayout();
    setLayout(vLayout);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(box);
}

QStringList StringInputDialog::getSequence()
{
    if(!mLine)
        return {};

    return mLine->text().split(' ');
}

QString StringInputDialog::getString()
{
    if(!mLine)
        return "";

    return mLine->text();
}

void StringInputDialog::clear()
{
    if(mLine) mLine->clear();
}

}
