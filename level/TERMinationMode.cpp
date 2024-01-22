#include "TERMinationMode.h"

void TERMinationMode::addData(const std::string infoLevelSetNo, std::string infoLevelSetId,
                 const std::string infoTermMode, std::vector<std::string> infoPinList){
    levelSetNo.push_back(infoLevelSetNo);
    levelSetId.push_back(infoLevelSetId);
    termMode.push_back(infoTermMode);
    pinlist.push_back(infoPinList);
}

void TERMinationMode::printPinList() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("TERM Pinlist:");

    if(!pinlist.empty()){
        for (const auto pinGroup : pinlist) {
            std::string vectorContents;
            for (const auto pin : pinGroup) {
                vectorContents += pin + ",";
            }
            levelLogger->info(vectorContents);
            vectorContents.clear();
        }
    }
}

void TERMinationMode::printData() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("TERM Data:");

    std::string vectorLevelSetNo;
    std::string vectorLevelSetId;
    std::string vectorTermMode;

    if(!levelSetNo.empty()){
        for (const auto setno : levelSetNo) {
            vectorLevelSetNo += setno + ",";
        }
        levelLogger->info("levelSetNo: {}", vectorLevelSetNo);
        vectorLevelSetNo.clear();
    }

    if(!levelSetId.empty()){
        for (const auto id : levelSetId) {
            vectorLevelSetId += id + ",";
        }
        levelLogger->info("levelSetId: {}", vectorLevelSetId);
        vectorLevelSetId.clear();
    }

    if(!termMode.empty()){
        for (const auto v : termMode){
            vectorTermMode += v + ",";
        }
        levelLogger->info("termMode: {}", vectorTermMode);
        vectorTermMode.clear();
    }

}