#pragma once

#include <vector>
#include <string>
#include <memory>

namespace MPM {
namespace Model {

class IExpression 
{
public:
    static constexpr size_t INVALID_ID = std::numeric_limits<size_t>::max();

    IExpression(size_t id = INVALID_ID)
        : mId(id) {}

    virtual ~IExpression() {}

    virtual bool isEqual(const IExpression* other) const = 0;
    virtual std::vector<const IExpression*> getOperands() const = 0;
    virtual std::shared_ptr<IExpression> clone() const = 0;
    virtual std::string getName() const = 0;

    size_t getID() const { return mId; }

private:
    size_t mId = INVALID_ID;
};

}
}
