#ifndef SPECSET_H
#define SPECSET_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class SPECSET {
public:
    std::string specSetNumber;
    std::string specsetDescription;

    std::vector<std::string> specName;
    std::vector<std::string> setupValue;
    std::vector<std::string> minimumValue;
    std::vector<std::string> maximumValue;
  
};

#endif // SPECSET_H