#ifndef NODEDATACREATOR_H
#define NODEDATACREATOR_H

#include "Common/NodeUIData.h"
#include <memory>

// forw decl
namespace MPM {
namespace Model {
    class IExpression;
}
}

namespace MPM {
namespace Backend {
namespace NodeDataCreator {

NodeUIData createData(std::shared_ptr<Model::IExpression> expr);

}
}
}

#endif // NODEDATACREATOR_H
