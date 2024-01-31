#include "SpecSet.h"

void SpecSet::setSpecSetNumber(const std::string infoNumber, const std::string infoDescription){
    specSetNumber = infoNumber;
    specSetDescription = infoDescription;
}

void SpecSet::addData(const std::string infoSpecName, const std::string infoSetupValue,
                 const std::string infoMinimumValue, const std::string infoMaximumValue){
    
    specName.push_back(infoSpecName);
    setupValue.push_back(infoSetupValue);
    minimumValue.push_back(infoMinimumValue);
    maximumValue.push_back(infoMaximumValue);
}

void SpecSet::printSetNumber() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("SpecSet Number: {}", specSetNumber);
    levelLogger->info("SpecSet Description: {}", specSetDescription);
}

void SpecSet::printSetData() const {
    auto levelLogger = LoggerManager::getLevelLogger();

    levelLogger->info("SpecSet {} Data:",specSetDescription);

    if(!specName.empty()){
        for(size_t num = 0; num < specName.size(); num++){
            levelLogger->info("{} {} {} {}", specName[num], setupValue[num],minimumValue[num], maximumValue[num]);
        }
    }
}