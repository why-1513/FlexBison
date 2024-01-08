#ifndef POWERSUPPLYLOADCAPACITANCE_H
#define POWERSUPPLYLOADCAPACITANCE_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class PowerSupplyLoadCapacitance {
public:
    std::vector<std::string> value;
    std::vector<std::string> DCSValue;
    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string infoValue, const std::string infoDCSValue,
                 const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // POWERSUPPLYLOADCAPACITANCE_H