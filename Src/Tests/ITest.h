#pragma once

#include <cassert>

namespace MPM {
namespace Testing {

class ITest {
public:
    virtual bool exec() = 0;

protected:
    void updateResultVar(bool& var, bool expr)
    {
        assert(expr);
        var &= expr;
    }
};

}
}