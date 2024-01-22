#ifndef TERMINATIONMODE_H
#define TERMINATIONMODE_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class TERMinationMode {
public:
    std::vector<std::string> levelSetNo;
    std::vector<std::string> levelSetId;
    std::vector<std::string> termMode;
    std::vector<std::string> termPullDown;
    std::vector<std::string> param1;
    std::vector<std::string> param2;
    std::vector<std::string> param3;
    std::vector<std::string> LRange;
    std::vector<std::string> HRange;

    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string infoLevelSetNo, const std::string infoLevelSetId,
                 const std::string infoTermMode, const std::string infoTermPullDown,
                 const std::string infoParam1, const std::string infoParam2,
                 const std::string infoParam3, const std::string infoLRange,
                 const std::string infoHRange, const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // TERMINATIONMODE_H