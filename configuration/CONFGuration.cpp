#include "CONFGuration.h"

void CONFGuration::addData(const std::string infoContext, const std::string infoPinType,
                           const std::string infoPinOperMode, const std::vector<std::string> infoPinList) {
    context.push_back(infoContext);
    pinType.push_back(infoPinType);
    pinOperMode.push_back(infoPinOperMode);
    pinlist.push_back(infoPinList);
}

void CONFGuration::printPinList() const {
    auto configLogger = LoggerManager::getConfigLogger();
    configLogger->info("CONF Pinlist:");

    if(!pinlist.empty()){
        for (const auto pinGroup : pinlist) {
            std::string vectorContents;
            for (const auto pin : pinGroup) {
                vectorContents += pin + ",";
            }
            configLogger->info(vectorContents);
            vectorContents.clear();
        }
    }
}

void CONFGuration::printData() const {
    auto configLogger = LoggerManager::getConfigLogger();
    configLogger->info("CONF Data:");

    std::string vectorContext;
    std::string vectorPinType;
    std::string vectorPinOperMode;

    if(!context.empty()){
        for (const auto text : context) {
            vectorContext += text + ",";
        }
        configLogger->info("Context: {}", vectorContext);
        vectorContext.clear();
    }

    if(!pinType.empty()){
        for (const auto type : pinType) {
            vectorPinType += type + ",";
        }
        configLogger->info("PinType: {}", vectorPinType);
        vectorPinType.clear();
    }

    if(!pinOperMode.empty()){
        for (const auto mode : pinOperMode) {
            vectorPinOperMode += mode + ",";
        }
        configLogger->info("PinOperMode: {}", vectorPinOperMode);
        vectorPinOperMode.clear();
    }
}