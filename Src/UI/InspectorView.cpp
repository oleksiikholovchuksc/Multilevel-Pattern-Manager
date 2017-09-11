#include "InspectorView.h"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>

#include <random>

static double getRandomValue()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 9);
    return dis(gen);
}

static void prepareFont(QLabel* label)
{
    QFont nameFont = label->font();
    nameFont.setItalic(true);
    label->setFont(nameFont);
}

namespace MPM {
InspectorView::InspectorView()
    : mMinimizeButton(new QPushButton(QIcon("://Resources/minimize.png"), "Minimize"))
    , mNameLabel(new QLabel())
    , mIdLabel(new QLabel())
    , mDummyDataLabel1(new QLabel())
    , mDummyDataLabel2(new QLabel())
    , mDummyDataLabel3(new QLabel())
{
    arrangeWidgets();

    connect(mMinimizeButton, &QPushButton::clicked, this, &InspectorView::minimizationRequested);
}

void InspectorView::presentNode(const NodeUIData &data)
{
    mNameLabel->setText(QString::fromStdString(data.name));
    mMinimizeButton->setEnabled(data.minimizable);
    mIdLabel->setText(QString::number(data.id));
    mDummyDataLabel1->setText(QString::number(getRandomValue()));
    mDummyDataLabel2->setText(QString::number(getRandomValue()));
    mDummyDataLabel3->setText(QString::number(getRandomValue()));
}

void InspectorView::arrangeWidgets()
{
    QVBoxLayout *vLayout = new QVBoxLayout();
    setLayout(vLayout);

    QHBoxLayout *hLayout = new QHBoxLayout();
    vLayout->addLayout(hLayout);

    hLayout->addWidget(mNameLabel);
    hLayout->addStretch();
    hLayout->addWidget(mMinimizeButton);

    mMinimizeButton->setEnabled(false);

    QGroupBox *groupBox = new QGroupBox("Node data");
    vLayout->addWidget(groupBox);

    QFormLayout *fLayout = new QFormLayout();
    groupBox->setLayout(fLayout);

    fLayout->setLabelAlignment(Qt::AlignLeft);
    fLayout->addRow("Node ID", mIdLabel);
    fLayout->addRow("Discrepancy level", mDummyDataLabel1);
    fLayout->addRow("Transition approximation", mDummyDataLabel2);
    fLayout->addRow("Adjacency degree", mDummyDataLabel3);

    prepareFont(mNameLabel);
    prepareFont(mIdLabel);
    prepareFont(mDummyDataLabel1);
    prepareFont(mDummyDataLabel2);
    prepareFont(mDummyDataLabel3);

    mNameLabel->setText("<node_name>");
    mIdLabel->setText("N/A");
    mDummyDataLabel1->setText("N/A");
    mDummyDataLabel2->setText("N/A");
    mDummyDataLabel3->setText("N/A");

    vLayout->addStretch();
}
}
