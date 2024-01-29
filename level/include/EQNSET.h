#ifndef EQNSET_H
#define EQNSET_H

#include <vector>
#include <string>
#include <memory>
#include "LoggerManager.h"

#include "SPECSET.h"

class EQNSET {
public:
    std::string equationSetNumber;
    std::string equationSetDescription;

    std::vector<std::string> specNames;
    std::vector<std::string> specUnit;
    std::vector<std::string> dpsPinName;
    std::vector<std::string> dpsPinValue;


    std::vector<std::shared_ptr<SPECSET>> specSet;
  
};

#endif // EQNSET_H