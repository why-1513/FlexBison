#include "ReceiveLevel.h"

void ReceiveLevel::addData(const std::string infoLevelSetNo, const std::string infoLevelSetId,
                 const std::string infoVth, const std::string infoLogicLevel0,
                 const std::string infoLogicLevel1, const std::vector<std::string> infoPinList){
    levelSetNo.push_back(infoLevelSetNo);
    levelSetId.push_back(infoLevelSetId);
    vth.push_back(infoVth);
    logicLevel0.push_back(infoLogicLevel0);
    logicLevel1.push_back(infoLogicLevel1);
    pinlist.push_back(infoPinList);
}

void ReceiveLevel::printPinList() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("RCLV Pinlist:");

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

void ReceiveLevel::printData() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("RCLV Data:");

    std::string vectorLevelSetNo;
    std::string vectorLevelSetId;
    std::string vectorVth;
    std::string vectorLogicLevel0;
    std::string vectorLogicLevel1;

    if(!levelSetNo.empty()){
        for (const auto setno : levelSetNo) {
            vectorLevelSetNo += setno + " ";
        }
        levelLogger->info("levelSetNo: {}", vectorLevelSetNo);
        vectorLevelSetNo.clear();
    }

    if(!levelSetId.empty()){
        for (const auto id : levelSetId) {
            vectorLevelSetId += id + " ";
        }
        levelLogger->info("levelSetId: {}", vectorLevelSetId);
        vectorLevelSetId.clear();
    }

    if(!vth.empty()){
        for (const auto v : vth){
            vectorVth += v + " ";
        }
        levelLogger->info("vth: {}", vectorVth);
        vectorVth.clear();
    }

    if(!logicLevel0.empty()){
        for (const auto vol : logicLevel0) {
            vectorLogicLevel0 += vol + " ";
        }
        levelLogger->info("logicLevel0: {}", vectorLogicLevel0);
        vectorLogicLevel0.clear();
    }

    if(!logicLevel1.empty()){
        for (const auto current : logicLevel1){
            vectorLogicLevel1 += current + " ";
        }
        levelLogger->info("logicLevel1: {}", vectorLogicLevel1);
        vectorLogicLevel1.clear();
    }

}