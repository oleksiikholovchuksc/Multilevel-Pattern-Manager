#include "MainToolbar.h"

#include "StringInputDialog.h"
#include <QPushButton>

namespace MPM {
MainToolbar::MainToolbar()
    : mAddButton(new QPushButton(QIcon("://Resources/add.png"), "Add pattern", this))
    , mRecognizeButton(new QPushButton("Recognize", this))
    , mDialog(new StringInputDialog(this))
    , mRecognitionDialog(new StringInputDialog(this))
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
    connect(mDialog, &StringInputDialog::accepted, this, &MainToolbar::requestNewPattern);

    // recognize button
    addWidget(mRecognizeButton);
    connect(mRecognizeButton, &QPushButton::clicked,
            [this]()
    {
        if(mRecognitionDialog)
        {
            mRecognitionDialog->clear();
            mRecognitionDialog->exec();
        }
    });
    connect(mRecognitionDialog, &StringInputDialog::accepted, this, &MainToolbar::requestRecognition);
}

void MainToolbar::requestNewPattern()
{
    if(mDialog)
        emit addPatternRequested(mDialog->getSequence());
}

void MainToolbar::requestRecognition()
{
    if(mRecognitionDialog)
        emit recognitionRequested(mRecognitionDialog->getString());
}
}
