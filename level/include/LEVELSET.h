#ifndef LEVELSET_H
#define LEVELSET_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class LEVELSET {
public:
    std::string levelSetNumber;
    std::string levelSetDescription;

    std::vector<std::string> pinsInName;
    std::vector<std::string> pinsInValue;
    std::vector<std::string> pinsOutName;
    std::vector<std::string> pinsOutValue;
  
};

#endif // LEVELSET_H