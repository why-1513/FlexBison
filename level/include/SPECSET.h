#ifndef SPECSET_H
#define SPECSET_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class SpecSet {
public:
    std::string specSetNumber;
    std::string specSetDescription;

    std::vector<std::string> specNames;
    std::vector<std::string> setupValues;
    std::vector<std::string> minimumValues;
    std::vector<std::string> maximumValues;
    std::vector<std::string> units;

    void setNumber(const std::string infoNumber, const std::string infoDescription);
    void addData(const std::string infoSpecName, const std::string infoSetupValue,
                 const std::string infoMinimumValue, const std::string infoMaximumValue,
                 const std::string infoUnit);

    void printSetNumber() const;
    void printSetData() const;
  
};

#endif // SPECSET_H