#include "PowerSupplySafetyLimits.h"
#include <iostream>

void PowerSupplySafetyLimits::addData(const std::string infoMinVol, const std::string infoMaxVol,
                                      const std::string infoMaxSourceCurrent, const std::string infoMaxSinkCurrent,
                                      const std::vector<std::string> infoPinList) {
    minVoltage.push_back(infoMinVol);
    maxVoltage.push_back(infoMaxVol);
    maxSourceCurrent.push_back(infoMaxSourceCurrent);
    maxSinkCurrent.push_back(infoMaxSinkCurrent);
    pinlist.push_back(infoPinList);
}

void PowerSupplySafetyLimits::printPinList() const {
    std::cout << "PSSL Pinlist:" << std::endl;
    for (const auto pinGroup : pinlist) {
        for (const auto pin : pinGroup) {
            std::cout << pin << " ";
        }
        std::cout << std::endl;
    }
}

void PowerSupplySafetyLimits::printData() const {
    std::cout << "PSSL Data:" << std::endl;

    std::cout << "MinVoltage: ";
    for (const auto vol : minVoltage) {
        std::cout << vol << " ";
    }
    std::cout << std::endl;

    std::cout << "MaxVoltage: ";
    for (const auto vol : maxVoltage) {
        std::cout << vol << " ";
    }
    std::cout << std::endl;

    std::cout << "MaxSourceCurrent: ";
    for (const auto current : maxSourceCurrent) {
        std::cout << current << " ";
    }
    std::cout << std::endl;

    std::cout << "MaxSinkCurrent: ";
    for (const auto current : maxSinkCurrent) {
        std::cout << current << " ";
    }
    std::cout << std::endl;
}