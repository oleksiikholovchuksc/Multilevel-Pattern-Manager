#pragma once

#include <vector>
#include <string>

namespace MPM {
namespace Model {

class IExpression 
{
public:
    size_t getID() const { return reinterpret_cast<size_t>(this); }

    virtual bool isEqual(const IExpression* other) const = 0;
    virtual std::vector<const IExpression*> getOperands() const = 0;
    virtual std::shared_ptr<IExpression> clone() const = 0;
    virtual std::string getName() const = 0;
};

}
}
