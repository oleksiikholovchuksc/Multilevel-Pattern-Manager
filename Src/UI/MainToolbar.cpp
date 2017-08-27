#include "MainToolbar.h"

#include <QPushButton>

namespace MPM {
MainToolbar::MainToolbar()
{
    QPushButton *addObjectButton = new QPushButton("Add object");
    addWidget(addObjectButton);
    connect(addObjectButton, &QPushButton::clicked, this, &MainToolbar::addObjectRequested);
}
}
