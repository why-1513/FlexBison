#include "CONFGuration.h"
#include <iostream>

void CONFGuration::addData(const std::string infoContext, const std::string infoPinType,
                           const std::string infoPinOperMode, const std::vector<std::string> infoPinList) {
    context.push_back(infoContext);
    pinType.push_back(infoPinType);
    pinOperMode.push_back(infoPinOperMode);
    pinlist.push_back(infoPinList);
}

void CONFGuration::printPinList() const {
    std::cout << "CONF Pinlist:" << std::endl;
    for (const auto pinGroup : pinlist) {
        for (const auto pin : pinGroup) {
            std::cout << pin << " ";
        }
        std::cout << std::endl;
    }
}

void CONFGuration::printData() const {
    std::cout << "CONF Data:" << std::endl;
    std::cout << "Context: ";
    for (const auto text : context) {
        std::cout << text << " ";
    }
    std::cout << std::endl;

    std::cout << "PinType: ";
    for (const auto type : pinType) {
        std::cout << type << " ";
    }
    std::cout << std::endl;

    std::cout << "PinOperMode: ";
    for (const auto mode : pinOperMode) {
        std::cout << mode << " ";
    }
    std::cout << std::endl;
}