#include "MainToolbar.h"

#include "NewPatternDialog.h"
#include <QPushButton>

namespace MPM {
MainToolbar::MainToolbar()
    : mAddButton(new QPushButton(QIcon("://Resources/add.png"), "Add pattern", this))
    , mRemoveButton(new QPushButton(QIcon("://Resources/minus.png"), "Remove", this))
    , mDialog(new NewPatternDialog(this))
{
    // conf button
    addWidget(mAddButton);
    connect(mAddButton, &QPushButton::clicked,
            [this]()
    {
        if(mDialog)
        {
            mDialog->clear();
            mDialog->exec();
        }
    });

    // conf dialog
    connect(mDialog, &NewPatternDialog::accepted, this, &MainToolbar::requestNewPattern);

    addWidget(mRemoveButton);
}

void MainToolbar::requestNewPattern()
{
    if(mDialog)
        emit addPatternRequested(mDialog->getSequence());
}
}
