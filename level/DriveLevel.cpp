#include "DriveLevel.h"

void DriveLevel::addData(const std::string infoLevelSetNo, const std::string infoLevelSetId,
                 const std::string infoLogicLevel0, const std::string infoLogicLevel1,
                 const std::vector<std::string> infoPinList){
    levelSetNo.push_back(infoLevelSetNo);
    levelSetId.push_back(infoLevelSetId);
    logicLevel0.push_back(infoLogicLevel0);
    logicLevel1.push_back(infoLogicLevel1);
    pinlist.push_back(infoPinList);
}

void DriveLevel::printPinList() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("DRLV Pinlist:");

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

void DriveLevel::printData() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("DRLV Data:");

    std::string vectorLevelSetNo;
    std::string vectorLevelSetId;
    std::string vectorLogicLevel0;
    std::string vectorLogicLevel1;

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

    if(!logicLevel0.empty()){
        for (const auto vol : logicLevel0) {
            vectorLogicLevel0 += vol + ",";
        }
        levelLogger->info("logicLevel0: {}", vectorLogicLevel0);
        vectorLogicLevel0.clear();
    }

    if(!logicLevel1.empty()){
        for (const auto current : logicLevel1){
            vectorLogicLevel1 += current + ",";
        }
        levelLogger->info("logicLevel1: {}", vectorLogicLevel1);
        vectorLogicLevel1.clear();
    }

}