#include "ProjectContext.h"

#include "Backend/PatternFactory.h"
#include "Backend/Model/SimpleExpression.hpp"
#include "Backend/Model/LeafNode.hpp"
#include "Backend/BackUtilsUtils.h"
#include <QDebug>

namespace MPM {
namespace Backend {

ProjectContext::ProjectContext()
    : mFactory(std::make_unique<PatternFactory>())
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

}
}
