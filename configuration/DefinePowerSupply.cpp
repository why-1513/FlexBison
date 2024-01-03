#include "DefinePowerSupply.h"
#include <iostream>

void DefinePowerSupply::addData(const std::string& infoDpsChannel,
                                const std::string& infoPolarity, const std::string& infoPin) {
    dpsChannel.push_back(infoDpsChannel);
    polarity.push_back(infoPolarity);
    pin.push_back(infoPin);
}

void DefinePowerSupply::printData() const {
    std::cout << "DFPS Data:" << std::endl;
    std::cout << "DPS Channel: ";
    for (const auto& channel : dpsChannel) {
        std::cout << channel << " ";
    }
    std::cout << std::endl;

    std::cout << "Polarity: ";
    for (const auto& polarity : polarity) {
        std::cout << polarity << " ";
    }
    std::cout << std::endl;

    std::cout << "Pin: ";
    for (const auto& pin : pin) {
        std::cout << pin << " ";
    }
    std::cout << std::endl;
}