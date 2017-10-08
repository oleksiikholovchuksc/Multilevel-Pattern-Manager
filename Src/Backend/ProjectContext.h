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
    ExprPtr getTopLevelExpr(size_t id);
    bool removeTopLevelExpr(size_t id);

signals:
    void patternAdded(size_t parentId, const PatternTree& ptree);
    void patternsSpliced(size_t sourceId, size_t destinationId, const PatternTree& splicedTree);
    void reparented(size_t sourceId, size_t destId, const PatternTree& tree);
    void minimized(size_t id, const PatternTree& ptree);
    void recognitionDone(const QString& string, bool result);

public slots:
    void addPattern(const QStringList& sequence);
    void splice(size_t sourceId, size_t destinationId);
    void reparent(size_t sourceId, size_t destinationId);
    void minimize(size_t id);
    void remove(size_t id);
    void recognize(const QString& string);

private:
    std::unique_ptr<PatternFactory> mFactory;
    std::vector<ExprPtr> mPatterns;
};

}
}

#endif // PROJECTCONTEXT_H
