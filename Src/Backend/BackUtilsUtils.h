#ifndef BACKUTILSUTILS_H
#define BACKUTILSUTILS_H

#include "Model/IExpression.hpp"
#include "Common/PatternTree.h"

namespace MPM {
namespace BackUtils {

PatternTree ptreeFromIExpression(std::shared_ptr<Model::IExpression> e);

}
}

#endif // BACKUTILSUTILS_H
