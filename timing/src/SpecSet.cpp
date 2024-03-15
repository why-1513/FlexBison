#include "SpecSet.h"

void SpecSet::setNumber(const std::string infoNumber, const std::string infoDescription){
    specSetNumber = infoNumber;
    specSetDescription = infoDescription;
}

void SpecSet::addData(const std::string infoSpecName, const std::string infoSetupValue,
                 const std::string infoMinimumValue, const std::string infoMaximumValue
                 ,const std::string infoUnit){
    
    specNames.push_back(infoSpecName);
    setupValues.push_back(infoSetupValue);
    minimumValues.push_back(infoMinimumValue);
    maximumValues.push_back(infoMaximumValue);
    units.push_back(infoUnit);
}

void SpecSet::printSetNumber() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("SpecSet Number: {}", specSetNumber);
    timingLogger->info("SpecSet Description: {}", specSetDescription);
}

void SpecSet::printSetData() const {
    auto timingLogger = LoggerManager::getTimingLogger();

    timingLogger->info("SpecSet {} Data:",specSetDescription);

    if(!specNames.empty()){
        for(size_t num = 0; num < specNames.size(); num++){
            timingLogger->info("{} {} {} {} {}", specNames[num], setupValues[num],minimumValues[num], maximumValues[num], units[num]);
        }
    }
}