#ifndef CLAMPLEVEL_H
#define CLAMPLEVEL_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class ClampLevel {
public:
    std::vector<std::string> levelSet;
    std::vector<std::string> levelSetId;
    std::vector<std::string> clampMode;
    std::vector<std::string> lowClampLevel;
    std::vector<std::string> highClampLevel;

    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string infoLevelSet, const std::string infolevelSetId,
                 const std::string infoClampMode, const std::string infoLowClampLevel,
                 const std::string infoHighClampLevel, const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // CLAMPLEVEL_H