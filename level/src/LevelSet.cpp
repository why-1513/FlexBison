#include "LevelSet.h"

void LevelSet::setSpecSetNumber(const std::string infoNumber, const std::string infoDescription){
    levelSetNumber = infoNumber;
    levelSetDescription = infoDescription;
}

void LevelSet::addPinsInData(const std::string infoPinsInName, const std::string infoPinsInValue){
    pinsInNames.push_back(infoPinsInName);
    pinsInValues.push_back(infoPinsInValue);
}

void LevelSet::addPinsOutData(const std::string infoPinsOutName, const std::string infoPinsOutValue){
    pinsOutNames.push_back(infoPinsOutName);
    pinsOutValues.push_back(infoPinsOutValue);
}

void LevelSet::printSetNumber() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("levelSet Number: {}", levelSetNumber);
    levelLogger->info("levelSet Description: {}", levelSetDescription);
}

void LevelSet::printSetData() const {
    auto levelLogger = LoggerManager::getLevelLogger();

    if(!pinsInNames.empty()){
        levelLogger->info("LevelSet Pins In Data:");
        for(size_t num = 0; num < pinsInNames.size(); num++){
            levelLogger->info("{} = {}", pinsInNames[num], pinsInValues[num]);
        }
    }

    if(pinsOutNames.empty()){
        levelLogger->info("LevelSet Pins Out Data:");
        for(size_t num = 0; num < pinsOutNames.size(); num++){
            levelLogger->info("{} = {}", pinsOutNames[num], pinsOutValues[num]);
        }
    }

}