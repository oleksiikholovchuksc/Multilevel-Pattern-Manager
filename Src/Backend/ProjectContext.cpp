#include "ProjectContext.h"

#include "Backend/PatternFactory.h"
#include "Backend/Model/SimpleExpression.hpp"
#include "Backend/Model/LeafNode.hpp"
#include "Backend/Processors/PatternProcessor.hpp"
#include "Backend/BackUtilsUtils.h"

#include <QDebug>

#include <algorithm>

namespace MPM {
namespace Backend {

ProjectContext::ProjectContext()
    : mFactory(std::make_unique<PatternFactory>())
{

}

ProjectContext::~ProjectContext()
{

}

void ProjectContext::addPattern(const QStringList &sequence)
{
    std::vector<std::string> stringVec;
    for(const auto s : sequence)
        stringVec.push_back(s.toStdString());

    auto newExpr = mFactory->createLowLevelPattern(stringVec);
    mPatterns.push_back(newExpr);

    emit patternAdded(Model::IExpression::INVALID_ID, BackUtils::ptreeFromIExpression(newExpr));
}

void ProjectContext::splice(size_t id1, size_t id2)
{
    auto p1 = getExprById(id1);
    auto p2 = getExprById(id2);

    if(!p1 || !p2)
    {
        qWarning() << "Couldn't splice on backend side";
        return;
    }

    auto splicedExpr = Processor::splice(p1, p2);

    emit patternsSpliced(id1, id2, BackUtils::ptreeFromIExpression(splicedExpr));
}

ProjectContext::ExprPtr ProjectContext::getExprById(size_t id)
{
    auto it = std::find_if(mPatterns.begin(), mPatterns.end(),
                           [id](ExprPtr e) {
                                if(e) return e->getID() == id;
                                return false;
                            });

    if(it != mPatterns.end())
        return *it;

    return nullptr;
}

}
}
