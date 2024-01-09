#include "PowerSupplyLoadCapacitance.h"

void PowerSupplyLoadCapacitance::addData(const std::string infoValue, const std::string infoDCSValue,
                                         const std::vector<std::string> infoPinList) {
    value.push_back(infoValue);
    DCSValue.push_back(infoDCSValue);
    pinlist.push_back(infoPinList);
}

void PowerSupplyLoadCapacitance::printPinList() const {
    auto copnfigLogger = LoggerManager::getConfigLogger();
    copnfigLogger->info("PSLC Pinlist:");

    if(!pinlist.empty()){
        for (const auto pinGroup : pinlist) {
            std::string vectorContents;
            for (const auto pin : pinGroup) {
                vectorContents += pin + ",";
            }
            copnfigLogger->info(vectorContents);
            vectorContents.clear();            
        }
    }    
}

void PowerSupplyLoadCapacitance::printData() const {
    auto copnfigLogger = LoggerManager::getConfigLogger();
    copnfigLogger->info("PSLC Data:");

    std::string vectorValue;
    std::string vectorDCSValue;

    if(!value.empty()){
        for (const auto val : value) {
            vectorValue += val + ",";
        }
        copnfigLogger->info("Value: {}", vectorValue);
        vectorValue.clear();
    }
    
    if(!DCSValue.empty()){
        for (const auto val : DCSValue) {
            vectorDCSValue += val + ",";
        }
        copnfigLogger->info("DCSValue: {}", vectorDCSValue);
        vectorDCSValue.clear();
    }
}