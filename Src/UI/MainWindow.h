#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Common/PatternTree.h"
#include "Common/NodeUIData.h"

#include <QMainWindow>

class QPushButton;

namespace MPM {

class ViewWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    void showStatusBarMessage(const QString& msg);

public slots:
    void addPattern(size_t parentId, const PatternTree& ptree);
    void splicePatterns(size_t sourceId, size_t destId, const PatternTree& ptree);
    void presentNode(const NodeUIData& data);
    void reparent(size_t sourceId, size_t targetId, const PatternTree& tree);
    void minimize(size_t id, const PatternTree& ptree);
    void showRecognitionResult(const QString& string, bool result);
    void renameNodes(const std::map<size_t, std::string> renameMap);

signals:
    void addPatternRequest(const QStringList& sequence);
    void splicingRequested(size_t id1, size_t id2);
    void selectedIdChanged(size_t id);
    void reparentingRequested(size_t sourceId, size_t targetId);
    void minimizationRequested(size_t id);
    void removeRequested(size_t id);
    void recongnitionRequested(const QString& inputString);
    void renamingRequested(size_t id, const QString& newName);

private slots:
    void handleRemoveRequest();

private:
    void createToolbar();
    void createStatusBar();

    QPushButton* mAddObjectButton;
    ViewWidget *mViewWidget;
};

}

#endif // MAINWINDOW_H
