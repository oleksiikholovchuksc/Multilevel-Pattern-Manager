#ifndef PATTERNTREE_H
#define PATTERNTREE_H

#include <string>
#include <vector>
#include <memory>

namespace MPM {

class PatternTree
{
public:
    struct Node
    {
        size_t id = std::numeric_limits<size_t>::max();
        std::string name;
        std::weak_ptr<Node> parent;
        std::vector<std::shared_ptr<Node>> children;
    };

    PatternTree(std::shared_ptr<Node> rootNode = nullptr);
    std::shared_ptr<Node> getRootNode() const;

private:
    std::shared_ptr<Node> mRootNode;
};

}

#endif // PATTERNTREE_H
