#pragma once

#include "../Model/IExpression.hpp"
#include "../Model/BinaryExpression.h"
#include "../Model/SimpleExpression.hpp"

#include <vector>
#include <memory>

namespace MPM {
namespace Processor {

std::shared_ptr<Model::BinaryExpression> splice(
        size_t splicedId,
        std::shared_ptr<Model::IExpression> left,
        std::shared_ptr<Model::IExpression> right);

std::shared_ptr<Model::SimpleExpression> minimize(std::shared_ptr<Model::BinaryExpression> expr);

bool recognizeString(const std::vector<std::shared_ptr<Model::IExpression>>& expressions,
                     const std::string& inputString);

}
}
