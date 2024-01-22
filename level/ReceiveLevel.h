#ifndef RECEIVELEVEL_H
#define RECEIVELEVEL_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class ReceiveLevel {
public:
    std::vector<std::string> levelSetNo;
    std::vector<std::string> levelSetId;
    std::vector<std::string> vth;
    std::vector<std::string> logicLevel0;
    std::vector<std::string> logicLevel1;

    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string infoLevelSetNo, const std::string infoLevelSetId,
                 const std::string infoVth, const std::string infoLogicLevel0,
                 const std::string infoLogicLevel1, const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // RECEIVELEVEL_H