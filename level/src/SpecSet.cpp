#include "SpecSet.h"

void SpecSet::setSpecSetNumber(const std::string infoNumber, const std::string infoDescription){
    specSetNumber = infoNumber;
    specSetDescription = infoDescription;
}

void SpecSet::addData(const std::string infoSpecName, const std::string infoSetupValue,
                 const std::string infoMinimumValue, const std::string infoMaximumValue){
    
    specNames.push_back(infoSpecName);
    setupValues.push_back(infoSetupValue);
    minimumValues.push_back(infoMinimumValue);
    maximumValues.push_back(infoMaximumValue);
}

void SpecSet::printSetNumber() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("SpecSet Number: {}", specSetNumber);
    levelLogger->info("SpecSet Description: {}", specSetDescription);
}

void SpecSet::printSetData() const {
    auto levelLogger = LoggerManager::getLevelLogger();

    levelLogger->info("SpecSet {} Data:",specSetDescription);

    if(!specNames.empty()){
        for(size_t num = 0; num < specNames.size(); num++){
            levelLogger->info("{} {} {} {}", specNames[num], setupValues[num],minimumValues[num], maximumValues[num]);
        }
    }
}