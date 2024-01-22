#ifndef POWERSUPPLYLEVEL_H
#define POWERSUPPLYLEVEL_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class PowerSupplyLevel {
public:
    std::vector<std::string> dpsNo;
    std::vector<std::string> dpsSetId;
    std::vector<std::string> voltage;
    std::vector<std::string> sourceCurrent;
    std::vector<std::string> sinkCurrent;
    std::vector<std::string> impedance;
    std::vector<std::string> setupTime;
    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string infoDpsNo, const std::string infoDpsSetId,
                 const std::string infoVoltage, const std::string infoSourceCurrent,
                 const std::string infoSinkCurrent, const std::string infoImpedance,
                 const std::string infoSetupTime, const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // POWERSUPPLYLEVEL_H