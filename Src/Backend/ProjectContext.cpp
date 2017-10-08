#include "ProjectContext.h"

#include "Backend/PatternFactory.h"
#include "Backend/Model/SimpleExpression.hpp"
#include "Backend/Model/LeafNode.hpp"
#include "Backend/Model/BinaryExpression.h"
#include "Backend/BackUtilsUtils.h"
#include "Backend/Processors/PatternProcessor.hpp"
#include <QDebug>

#include <algorithm>
#include <cassert>

namespace MPM {
namespace Backend {

static ProjectContext::ExprPtr getExprHelper(ProjectContext::ExprPtr e, size_t id)
{
    if(!e)
        return nullptr;

    if(e->getID() == id)
        return e;

    if(!std::dynamic_pointer_cast<Model::LeafNode>(e))
    {
        std::vector<std::shared_ptr<Model::IExpression>> exprVec = {};
        if(auto bin = std::dynamic_pointer_cast<Model::BinaryExpression>(e))
        {
            exprVec = bin->getOperands();
        }
        else if(auto simple = std::dynamic_pointer_cast<Model::SimpleExpression>(e))
        {
            for(auto structureUnit : simple->getStructure())
                exprVec.push_back(structureUnit);
        }
        else
        {
            assert(false);  // wtf blyat
        }

        for(auto expr : exprVec)
        {
            if(auto result = getExprHelper(expr, id))
                return result;
        }
    }

    return nullptr;
}

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

void ProjectContext::splice(size_t sourceId, size_t destId)
{
    // get patterns to splice
    auto p1 = getExpr(sourceId);
    auto p2 = getExpr(destId);

    if(!p1 || !p2)
    {
        qWarning() << "Couldn't splice on backend side";
        return;
    }

    // do actual splicing
    auto splicedExpr = mFactory->getSpliced(p1, p2);

    // remove source
    for(auto it = mPatterns.begin(); it < mPatterns.end(); ++it)
    {
        if((*it)->getID() == sourceId)
        {
            mPatterns.erase(it);
            break;
        }
    }

    // insert spliced expr instead of dest
    for(size_t i = 0; i < mPatterns.size(); ++i)
    {
        if(mPatterns[i]->getID() == destId)
        {
            mPatterns[i] = splicedExpr;
            break;
        }
    }

    emit patternsSpliced(sourceId, destId, BackUtils::ptreeFromIExpression(splicedExpr));
}

void ProjectContext::reparent(size_t sourceId, size_t destinationId)
{
    auto source = getTopLevelExpr(sourceId);
    auto dest = getExpr(destinationId);

    if(!source || !dest)
    {
        qWarning() << "Couldn't reparent on backend side";
        return;
    }

    if(auto asSimple = std::dynamic_pointer_cast<Model::SimpleExpression>(dest))
    {
        asSimple->addChild(source);
        removeTopLevelExpr(sourceId);
        emit reparented(sourceId, destinationId, BackUtils::ptreeFromIExpression(dest));
    }
    else
    {
        qWarning() << "It's possible to reparent only to simple expressions";
        return;
    }
}

void ProjectContext::minimize(size_t id)
{
    auto expr = getExpr(id);

    if(!expr)
        return;

    auto binExpr = std::dynamic_pointer_cast<Model::BinaryExpression>(expr);
    if(!binExpr)
    {
        qWarning() << "Couldn't cast to binary expression on backed side during minim. operation";
        return;
    }

    auto minimizedExpr = mFactory->getMinimized(binExpr);

    for(size_t i = 0; i < mPatterns.size(); ++i)
    {
        if(mPatterns[i] && mPatterns[i]->getID() == id)
        {
            mPatterns[i] = minimizedExpr;
            emit minimized(id, BackUtils::ptreeFromIExpression(minimizedExpr));
            break;
        }
    }
}

void ProjectContext::remove(size_t id)
{
    Q_UNUSED(id);
    // NIY
}

void ProjectContext::recognize(const QString &string)
{
    emit recognitionDone(string, Processor::recognizeString(mPatterns, string.toStdString()));
}

ProjectContext::ExprPtr ProjectContext::getExpr(size_t id)
{
    for(const auto& expr : mPatterns)
    {
        if(auto result = getExprHelper(expr, id))
            return result;
    }

    return nullptr;
}

ProjectContext::ExprPtr ProjectContext::getTopLevelExpr(size_t id)
{
    for(const auto expr : mPatterns)
    {
        if(expr->getID() == id)
            return expr;
    }

    return nullptr;
}

bool ProjectContext::removeTopLevelExpr(size_t id)
{
    for(auto it = mPatterns.begin(); it < mPatterns.end(); ++it)
    {
        if((*it)->getID() == id)
        {
            mPatterns.erase(it);
            return true;
        }
    }

    return false;
}

}
}
