#include "DefineGroup.h"
#include <iostream>

void DefineGroup::addData(const std::string& infoPinType,
                          const std::vector<std::string>& infoPinList, const std::string& infoPinGroup) {
    pinType.push_back(infoPinType);
    pinGroup.push_back(infoPinGroup);
    pinlist.push_back(infoPinList);
}

void DefineGroup::printPinList() const {
    std::cout << "DFGP Pinlist:" << std::endl;
    for (const auto& pinGroup : pinlist) {
        for (const auto& pin : pinGroup) {
            std::cout << pin << " ";
        }
        std::cout << std::endl;
    }
}

void DefineGroup::printData() const {
    std::cout << "DFGP Data:" << std::endl;

    std::cout << "PinType: ";
    for (const auto& type : pinType) {
        std::cout << type << " ";
    }
    std::cout << std::endl;

    std::cout << "PinGroup: ";
    for (const auto& group : pinGroup) {
        std::cout << group << " ";
    }
    std::cout << std::endl;
}