#ifndef PROJECTCONTEXT_H
#define PROJECTCONTEXT_H

#include <QObject>

namespace MPM {
namespace Backend {

class ProjectContext : public QObject
{
    Q_OBJECT

public:
    ProjectContext();
    
public slots:
    void addPattern(const QSttringList& sequence);
};

}
}

#endif // PROJECTCONTEXT_H
