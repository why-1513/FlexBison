#ifndef EQUATIONSPECIFICATIONTRANSFER_H
#define EQUATIONSPECIFICATIONTRANSFER_H

#include <vector>
#include <string>
#include <memory>
#include "LoggerManager.h"

#include "EQNSET.h"
#include "LEVELSET.h"

class EquationSpecificationTransfer {
public:
    std::string specType;
    std::string part;

    std::vector<std::shared_ptr<EQNSET>> eqnSet;
    std::vector<std::shared_ptr<LEVELSET>> levelSet;
  
};

#endif // EQUATIONSPECIFICATIONTRANSFER_H