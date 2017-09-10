#ifndef NODE_UI_DATA_H_
#define NODE_UI_DATA_H_

#include <string>

namespace MPM {

struct NodeUIData
{
    std::string name;
    size_t id = std::numeric_limits<size_t>::max();
    bool minimizable = false;
};

}

#endif
