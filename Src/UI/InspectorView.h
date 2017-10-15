#ifndef INSPECTORVIEW_H
#define INSPECTORVIEW_H

#include "Common/NodeUIData.h"

#include <QWidget>


class QPushButton;
class QLabel;

namespace MPM {

class StringInputDialog;

class InspectorView : public QWidget
{
    Q_OBJECT

public:
    InspectorView();

    void presentNode(const NodeUIData& data);
    void renameNodes(const std::map<size_t, std::string> renameMap);

signals:
    void minimizationRequested();
    void renameRequested(const QString& newName);

private:
    void arrangeWidgets();

    QPushButton *mMinimizeButton;
    QPushButton *mRenameButton;
    StringInputDialog *mDialog;
    QLabel *mNameLabel;
    QLabel *mIdLabel;
    QLabel *mDummyDataLabel1;
    QLabel *mDummyDataLabel2;
    QLabel *mDummyDataLabel3;
};
}

#endif // INSPECTORVIEW_H
