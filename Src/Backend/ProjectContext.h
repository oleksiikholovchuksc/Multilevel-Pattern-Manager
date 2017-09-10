#ifndef PROJECTCONTEXT_H
#define PROJECTCONTEXT_H

#include "Common/PatternTree.h"
#include <QObject>
#include <memory>

// forw decl
namespace MPM {
    namespace Model {
        class IExpression;
    }

    namespace Backend {
        class PatternFactory;
    }
}

namespace MPM {
namespace Backend {

class ProjectContext : public QObject
{
    Q_OBJECT

public:
    using ExprPtr = std::shared_ptr<Model::IExpression>;

    ProjectContext();
    ~ProjectContext();

    ExprPtr getExpr(size_t id);

signals:
    void patternAdded(size_t parentId, const PatternTree& ptree);
    void patternsSpliced(size_t sourceId, size_t destinationId, const PatternTree& splicedTree);

public slots:
    void addPattern(const QStringList& sequence);
    void splice(size_t sourceId, size_t destinationId);

private:

    std::unique_ptr<PatternFactory> mFactory;
    std::vector<ExprPtr> mPatterns;
};

}
}

#endif // PROJECTCONTEXT_H
