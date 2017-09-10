#include "NodeDataCreator.h"

#include "Model/BinaryExpression.h"

namespace MPM {
namespace Backend {
namespace NodeDataCreator {

NodeUIData createData(std::shared_ptr<Model::IExpression> expr)
{
    NodeUIData result;

    if(expr)
    {
        result.id = expr->getID();
        result.name = expr->getName();
        result.minimizable = (std::dynamic_pointer_cast<Model::BinaryExpression>(expr) != nullptr);
    }

    return result;
}

}
}
}
