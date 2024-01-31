#ifndef SPECSET_H
#define SPECSET_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class SpecSet {
public:
    std::string specSetNumber;
    std::string specSetDescription;

    std::vector<std::string> specName;
    std::vector<std::string> setupValue;
    std::vector<std::string> minimumValue;
    std::vector<std::string> maximumValue;

    void setSpecSetNumber(const std::string infoNumber, const std::string infoDescription);
    void addData(const std::string infoSpecName, const std::string infoSetupValue,
                 const std::string infoMinimumValue, const std::string infoMaximumValue);

    void printSetNumber() const;
    void printSetData() const;
  
};

#endif // SPECSET_H