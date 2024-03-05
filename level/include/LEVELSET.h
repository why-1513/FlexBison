#ifndef LEVELSET_H
#define LEVELSET_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class LevelSet {
public:
    std::string levelSetNumber;
    std::string levelSetDescription;

    std::vector<std::string> pinsInNames;
    std::vector<std::string> pinsInValues;
    std::vector<std::string> pinsOutNames;
    std::vector<std::string> pinsOutValues;

    void setNumber(const std::string infoNumber, const std::string infoDescription);
    void addPinsInData(const std::string infoPinsInName, const std::string infoPinsInValue);
    void addPinsOutData(const std::string infoPinsOutName, const std::string infoPinsOutValue);

    void printSetNumber() const;
    void printSetData() const;
  
};

#endif // LEVELSET_H