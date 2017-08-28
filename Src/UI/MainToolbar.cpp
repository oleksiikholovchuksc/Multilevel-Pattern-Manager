#include "MainToolbar.h"

#include "NewPatternDialog.h"
#include <QPushButton>

namespace MPM {
MainToolbar::MainToolbar()
    : mAddButton(new QPushButton("Add pattern", this))
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
}

void MainToolbar::requestNewPattern()
{
    if(mDialog)
        emit addPatternRequested(mDialog->getSequence());
}
}
