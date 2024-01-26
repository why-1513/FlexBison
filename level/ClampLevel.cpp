#include "ClampLevel.h"

void ClampLevel::addData(const std::string infoLevelSet, const std::string infoLevelSetId,
                 const std::string infoClampMode, const std::string infoLowClampLevel,
                 const std::string infoHighClampLevel, const std::vector<std::string> infoPinList){
    levelSet.push_back(infoLevelSet);
    levelSetId.push_back(infoLevelSetId);
    clampMode.push_back(infoClampMode);
    lowClampLevel.push_back(infoLowClampLevel);
    highClampLevel.push_back(infoHighClampLevel);
    pinlist.push_back(infoPinList);
}

void ClampLevel::printPinList() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("CLMP Pinlist:");

    if(!pinlist.empty()){
        for (const auto pinGroup : pinlist) {
            std::string vectorContents;
            for (const auto pin : pinGroup) {
                vectorContents += pin + " ";
            }
            levelLogger->info(vectorContents);
            vectorContents.clear();
        }
    }
}

void ClampLevel::printData() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("CLMP Data:");

    std::string vectorLevelSet;
    std::string vectorLevelSetId;
    std::string vectorClampMode;
    std::string vectorLowClampLevel;
    std::string vectorHighClampLevel;

    if(!levelSet.empty()){
        for (const auto set : levelSet) {
            vectorLevelSet += set + " ";
        }
        levelLogger->info("levelSet: {}", vectorLevelSet);
        vectorLevelSet.clear();
    }

    if(!levelSetId.empty()){
        for (const auto id : levelSetId) {
            vectorLevelSetId += id + " ";
        }
        levelLogger->info("levelSetId: {}", vectorLevelSetId);
        vectorLevelSetId.clear();
    }

    if(!clampMode.empty()){
        for (const auto mode : clampMode){
            vectorClampMode += mode + " ";
        }
        levelLogger->info("clampMode: {}", vectorClampMode);
        vectorClampMode.clear();
    }

    if(!lowClampLevel.empty()){
        for (const auto level : lowClampLevel) {
            vectorLowClampLevel += level + " ";
        }
        levelLogger->info("lowClampLevel: {}", vectorLowClampLevel);
        vectorLowClampLevel.clear();
    }

    if(!highClampLevel.empty()){
        for (const auto level : highClampLevel){
            vectorHighClampLevel += level + " ";
        }
        levelLogger->info("highClampLevel: {}", vectorHighClampLevel);
        vectorHighClampLevel.clear();
    }

}