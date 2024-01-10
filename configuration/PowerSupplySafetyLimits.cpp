#include "PowerSupplySafetyLimits.h"

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
    auto configLogger = LoggerManager::getConfigLogger();
    configLogger->info("PSSL Pinlist:");

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

void PowerSupplySafetyLimits::printData() const {
    auto configLogger = LoggerManager::getConfigLogger();
    configLogger->info("PSSL Data:");

    std::string vectorMinVoltage;
    std::string vectorMaxVoltage;
    std::string vectorMaxSourceCurrent;
    std::string vectorMaxSinkCurrent;

    if(!minVoltage.empty()){
        for (const auto vol : minVoltage) {
            vectorMinVoltage += vol + ",";
        }
        configLogger->info("MinVoltage: {}", vectorMinVoltage);
        vectorMinVoltage.clear();
    }

    if(!maxVoltage.empty()){
        for (const auto vol : maxVoltage) {
            vectorMaxVoltage += vol + ",";
        }
        configLogger->info("MaxVoltage: {}", vectorMaxVoltage);
        vectorMaxVoltage.clear();
    }

    if(!maxSourceCurrent.empty()){
        for (const auto current : maxSourceCurrent) {
            vectorMaxSourceCurrent += current + ",";
        }
        configLogger->info("MaxSourceCurrent: {}", vectorMaxSourceCurrent);
        vectorMaxSourceCurrent.clear();
    }

    if(!maxSinkCurrent.empty()){
        for (const auto current : maxSinkCurrent) {
            vectorMaxSinkCurrent += current + ",";
        }
        configLogger->info("MaxSinkCurrent: {}", vectorMaxSinkCurrent);
        vectorMaxSinkCurrent.clear();
    }
}