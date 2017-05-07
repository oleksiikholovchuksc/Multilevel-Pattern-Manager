#pragma once

#include <vector>

namespace MPM {
namespace Model {

class IExpression 
{
public:
    virtual bool isEqual(const IExpression* other) const = 0;
    virtual std::vector<const IExpression*> getOperands() const = 0;
};

}
}