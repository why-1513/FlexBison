#include "DefinePowerSupply.h"

void DefinePowerSupply::addData(const std::string infoDpsChannel,
                                const std::string infoPolarity, const std::string infoPin) {
    dpsChannel.push_back(infoDpsChannel);
    polarity.push_back(infoPolarity);
    pin.push_back(infoPin);
}

void DefinePowerSupply::printData() const {
    auto copnfigLogger = LoggerManager::getConfigLogger();
    copnfigLogger->info("DFPS Data:");

    std::string vectorDpsChannel;
    std::string vectorPolarity;
    std::string vectorPin;

    if(!dpsChannel.empty()){
        for (const auto channel : dpsChannel) {
            vectorDpsChannel += channel + ",";
        }
        copnfigLogger->info("DPS Channel: {}", vectorDpsChannel);
        vectorDpsChannel.clear();
    }

    if(!polarity.empty()){
        for (const auto polarity : polarity) {
            vectorPolarity += polarity + ",";
        }
        copnfigLogger->info("Polarity: {}", vectorPolarity);
        vectorPolarity.clear();
    }

    if(pin.empty()){
        for (const auto pin : pin) {
            vectorPin += pin + ",";
        }
        copnfigLogger->info("Pin: {}", vectorPin);
        vectorPin.clear();
    }
}