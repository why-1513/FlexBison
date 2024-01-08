#include "DefineGroup.h"

auto logger = LoggerManager::getLogger();

void DefineGroup::addData(const std::string infoPinType,
                          const std::vector<std::string> infoPinList, const std::string infoPinGroup) {
    pinType.push_back(infoPinType);
    pinGroup.push_back(infoPinGroup);
    pinlist.push_back(infoPinList);
}

void DefineGroup::printPinList() const {
    logger->info("DFGP Pinlist:");
    for (const auto pinGroup : pinlist) {
        std::string vectorContents;
        for (const auto pin : pinGroup) {
            vectorContents += pin + ",";
        }
        logger->info(vectorContents);
    }
}

void DefineGroup::printData() const {
    logger->info("DFGP Data:");

    std::string vectorPinType;
    std::string vectorPinGroup;

    for (const auto type : pinType) {
        vectorPinType += type + ",";
    }
    logger->info("PinType: {}", vectorPinType);

    for (const auto group : pinGroup) {
        vectorPinGroup += group + ",";
    }
    logger->info("PinGroup: {}", vectorPinGroup);
}