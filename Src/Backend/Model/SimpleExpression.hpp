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
    void addChild(std::shared_ptr<IExpression> expr);

    bool isEqual(const IExpression* other) const override;
    std::vector<std::shared_ptr<IExpression>> getOperands() const override;
    std::shared_ptr<IExpression> clone() const override;
    std::string getName() const override;

    void setName(const std::string& newName);

protected:
    std::string mName;

private:
    std::vector<std::shared_ptr<IExpression>> mStructure;
};

}
}
