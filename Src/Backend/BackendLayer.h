#ifndef BACKENDLAYER_H
#define BACKENDLAYER_H

#include <QThread>


namespace MPM {
namespace Backend {

class ProjectContext;

class BackendLayer : public QThread
{
    Q_OBJECT

public:
    BackendLayer();

public slots:
    void addPattern(const QStringList& sequence);

private slots:
    void init();

private:
    std::shared_ptr<ProjectContext> mContext;
};

}
}

#endif // BACKENDLAYER_H
