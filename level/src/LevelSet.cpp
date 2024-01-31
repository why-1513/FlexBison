#include "LevelSet.h"

void LevelSet::setSpecSetNumber(const std::string infoNumber, const std::string infoDescription){
    levelSetNumber = infoNumber;
    levelSetDescription = infoDescription;
}

void LevelSet::addPinsInData(const std::string infoPinsInName, const std::string infoPinsInValue){
    pinsInName.push_back(infoPinsInName);
    pinsInValue.push_back(infoPinsInValue);
}

void LevelSet::addPinsOutData(const std::string infoPinsOutName, const std::string infoPinsOutValue){
    pinsOutName.push_back(infoPinsOutName);
    pinsOutValue.push_back(infoPinsOutValue);
}

void LevelSet::printSetNumber() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("levelSet Number: {}", levelSetNumber);
    levelLogger->info("levelSet Description: {}", levelSetDescription);
}

void LevelSet::printSetData() const {
    auto levelLogger = LoggerManager::getLevelLogger();

    if(!pinsInName.empty()){
        levelLogger->info("LevelSet Pins In Data:");
        for(size_t num = 0; num < pinsInName.size(); num++){
            levelLogger->info("{} = {}", pinsInName[num], pinsInValue[num]);
        }
    }

    if(pinsOutName.empty()){
        levelLogger->info("LevelSet Pins Out Data:");
        for(size_t num = 0; num < pinsOutName.size(); num++){
            levelLogger->info("{} = {}", pinsOutName[num], pinsOutValue[num]);
        }
    }

}