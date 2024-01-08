#include "CONFGuration.h"

void CONFGuration::addData(const std::string infoContext, const std::string infoPinType,
                           const std::string infoPinOperMode, const std::vector<std::string> infoPinList) {
    context.push_back(infoContext);
    pinType.push_back(infoPinType);
    pinOperMode.push_back(infoPinOperMode);
    pinlist.push_back(infoPinList);
}

void CONFGuration::printPinList() const {
    auto logger = LoggerManager::getLogger();
    logger->info("CONF Pinlist:");
    for (const auto pinGroup : pinlist) {
        std::string vectorContents;
        for (const auto pin : pinGroup) {
            vectorContents += pin + ",";
        }
        logger->info(vectorContents);
    }
}

void CONFGuration::printData() const {
    auto logger = LoggerManager::getLogger();
    logger->info("CONF Data:");

    std::string vectorContext;
    std::string vectorPinType;
    std::string vectorPinOperMode;

    for (const auto text : context) {
        vectorContext += text + ",";
    }
    logger->info("Context: {}", vectorContext);

    for (const auto type : pinType) {
        vectorPinType += type + ",";
    }
    logger->info("PinType: {}", vectorPinType);

    for (const auto mode : pinOperMode) {
        vectorPinOperMode += mode + ",";
    }
    logger->info("PinOperMode: {}", vectorPinOperMode);
}