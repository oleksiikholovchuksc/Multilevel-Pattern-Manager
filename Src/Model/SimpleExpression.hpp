#pragma once

#include "IExpression.hpp"
#include <memory>

namespace MPM {
namespace Model {

class SimpleExpression : public IExpression
{
public:
    SimpleExpression(const std::vector<std::shared_ptr<IExpression>>& structure = {});

    const std::vector<std::shared_ptr<IExpression>>& getStructure() const;

    bool isEqual(const IExpression* other) const override;
    std::vector<const IExpression*> getOperands() const override;
    std::shared_ptr<IExpression> clone() const override;

private:
    std::vector<std::shared_ptr<IExpression>> mStructure;
};

}
}