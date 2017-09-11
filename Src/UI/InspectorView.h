#ifndef INSPECTORVIEW_H
#define INSPECTORVIEW_H

#include "Common/NodeUIData.h"

#include <QWidget>


class QPushButton;
class QLabel;

namespace MPM {
class InspectorView : public QWidget
{
    Q_OBJECT

public:
    InspectorView();

    void presentNode(const NodeUIData& data);

signals:
    void minimizationRequested();

private:
    void arrangeWidgets();

    QPushButton *mMinimizeButton;
    QLabel *mNameLabel;
    QLabel *mIdLabel;
    QLabel *mDummyDataLabel1;
    QLabel *mDummyDataLabel2;
    QLabel *mDummyDataLabel3;
};
}

#endif // INSPECTORVIEW_H
