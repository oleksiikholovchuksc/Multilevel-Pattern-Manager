#pragma once

#include "IExpression.hpp"
#include <memory>

namespace MPM {
namespace Model {

class SimpleExpression : public IExpression
{
public:
    SimpleExpression(
            size_t id = IExpression::INVALID_ID,
            const std::string& name = std::string(),
            const std::vector<std::shared_ptr<IExpression>>& structure = {});

    const std::vector<std::shared_ptr<IExpression>>& getStructure() const;

    bool isEqual(const IExpression* other) const override;
    std::vector<const IExpression*> getOperands() const override;
    std::shared_ptr<IExpression> clone() const override;
    std::string getName() const override;

private:
    std::string mName;
    std::vector<std::shared_ptr<IExpression>> mStructure;
};

}
}
