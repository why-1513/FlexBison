#include "PowerSupplyLoadCapacitance.h"
#include <iostream>

void PowerSupplyLoadCapacitance::addData(const std::string infoValue, const std::string infoDCSValue,
                                         const std::vector<std::string> infoPinList) {
    value.push_back(infoValue);
    DCSValue.push_back(infoDCSValue);
    pinlist.push_back(infoPinList);
}

void PowerSupplyLoadCapacitance::printPinList() const {
    std::cout << "PSLC Pinlist:" << std::endl;
    for (const auto pinGroup : pinlist) {
        for (const auto pin : pinGroup) {
            std::cout << pin << " ";
        }
        std::cout << std::endl;
    }
}

void PowerSupplyLoadCapacitance::printData() const {
    std::cout << "PSLC Data:" << std::endl;

    std::cout << "Value: ";
    for (const auto val : value) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "DCSValue: ";
    for (const auto val : DCSValue) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}