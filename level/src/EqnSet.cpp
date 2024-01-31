#include "EqnSet.h"

void EqnSet::setEqnSetNumber(const std::string infoNumber, const std::string infoDescription){
    equationSetNumber = infoNumber;
    equationSetDescription = infoDescription;
}

void EqnSet::addSpecsData(const std::string infoSpceName, const std::string infoSpecUnit){
    specNames.push_back(infoSpceName);
    specUnits.push_back(infoSpecUnit);
}

void EqnSet::addDpsPinsData(const std::string infoDpsPinName, const std::string infoDpsPinValue){
    dpsPinNames.push_back(infoDpsPinName);
    dpsPinValues.push_back(infoDpsPinValue);
}

void EqnSet::addSpecSet(const std::shared_ptr<SpecSet> specSet){
    specSets.push_back(specSet);
}

void EqnSet::printSetNumber() const{
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("EqnSet Number: {}", equationSetNumber);
    levelLogger->info("EqnSet Description: {}", equationSetDescription);
}

void EqnSet::printSetData() const{
    auto levelLogger = LoggerManager::getLevelLogger();

    levelLogger->info("EqnSet {} Data:",equationSetDescription);

    if(!specNames.empty()){
        for(size_t num = 0; num < specNames.size(); num++){
            levelLogger->info("{} [{}]", specNames[num], specUnits[num]);
        }
    }

    if(!dpsPinNames.empty()){
        for(size_t num = 0; num < dpsPinNames.size(); num++){
            levelLogger->info("{} = {}", dpsPinNames[num], dpsPinValues[num]);
        }
    }
}

void EqnSet::printSpecSets() const {

    if(!specSets.empty()){
        for(const auto set : specSets){
            set->printSetNumber();
            set->printSetData();
        }
    }
}