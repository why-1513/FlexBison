#include "DefineGroup.h"

void DefineGroup::addData(const std::string infoPinType,
                          const std::vector<std::string> infoPinList, const std::string infoPinGroup) {
    pinType.push_back(infoPinType);
    pinGroup.push_back(infoPinGroup);
    pinlist.push_back(infoPinList);
}

void DefineGroup::printPinList() const {
    auto configLogger = LoggerManager::getConfigLogger();
    configLogger->info("DFGP Pinlist:");
    
    if(!pinlist.empty()){
        for (const auto pinGroup : pinlist) {
            std::string vectorContents;
            for (const auto pin : pinGroup) {
                vectorContents += pin + " ";
            }
            configLogger->info(vectorContents);
            vectorContents.clear();
        }
    }
}

void DefineGroup::printData() const {
    auto configLogger = LoggerManager::getConfigLogger();
    configLogger->info("DFGP Data:");

    std::string vectorPinType;
    std::string vectorPinGroup;

    if(!pinType.empty()){
        for (const auto type : pinType) {
            vectorPinType += type + " ";
        }
        configLogger->info("PinType: {}", vectorPinType);
        vectorPinType.clear();
    }

    if(!pinGroup.empty()){
        for (const auto group : pinGroup) {
            vectorPinGroup += group + " ";
        }
        configLogger->info("PinGroup: {}", vectorPinGroup);
        vectorPinGroup.clear();
    }
}