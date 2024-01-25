#include "TERMinationMode.h"

void TERMinationMode::addData(const std::string infoLevelSetNo, const std::string infoLevelSetId,
                 const std::string infoTermMode, const std::string infoTermPullDown,
                 const std::string infoParam1, const std::string infoParam2,
                 const std::string infoParam3, const std::string infoLRange,
                 const std::string infoHRange, const std::vector<std::string> infoPinList){
    levelSetNo.push_back(infoLevelSetNo);
    levelSetId.push_back(infoLevelSetId);
    termMode.push_back(infoTermMode);
    pinlist.push_back(infoPinList);

    termPullDown.push_back(infoTermPullDown);
    param1.push_back(infoParam1);
    param2.push_back(infoParam2);
    param3.push_back(infoParam3);
    LRange.push_back(infoLRange);
    HRange.push_back(infoHRange);
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