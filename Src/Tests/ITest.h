#pragma once

namespace MPM {
namespace Testing {

class ITest {
public:
    virtual bool exec() = 0;
};

}
}