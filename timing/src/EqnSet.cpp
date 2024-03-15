#include "EqnSet.h"

void EqnSet::setNumber(const std::string infoNumber, const std::string infoDescription){
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

void EqnSet::addExpression(const std::string infoEquationVariable, const std::string infoExpression){
    equationVariable.push_back(infoEquationVariable);
    expression.push_back(infoExpression);
}

void EqnSet::printSetNumber() const{
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("EqnSet Number: {}", equationSetNumber);
    timingLogger->info("EqnSet Description: {}", equationSetDescription);
}

void EqnSet::printSetData() const{
    auto timingLogger = LoggerManager::getTimingLogger();

    timingLogger->info("EqnSet {} Data:",equationSetDescription);

    if(!specNames.empty()){
        timingLogger->info("spec:");
        for(size_t num = 0; num < specNames.size(); num++){
            timingLogger->info("{} [{}]", specNames[num], specUnits[num]);
        }
    }

    if(!dpsPinNames.empty()){
        timingLogger->info("dpspins:");
        for(size_t num = 0; num < dpsPinNames.size(); num++){
            timingLogger->info("{} = {}", dpsPinNames[num], dpsPinValues[num]);
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

void EqnSet::printExpression() const{

    auto timingLogger = LoggerManager::getTimingLogger();

    if(!equationVariable.empty()){
        timingLogger->info("equations:");
        for(size_t num = 0; num < dpsPinNames.size(); num++){
            timingLogger->info("{} = {}", equationVariable[num], expression[num]);
        }
    }
}