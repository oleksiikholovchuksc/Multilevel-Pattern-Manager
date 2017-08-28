#pragma once

#include "IExpression.hpp"
#include <memory>

namespace MPM {
namespace Model {

class SimpleExpression : public IExpression
{
public:
    SimpleExpression(
            const std::string& name,
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
