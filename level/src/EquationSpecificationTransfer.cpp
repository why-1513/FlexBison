#include "EquationSpecificationTransfer.h"

void EquationSpecificationTransfer::setNumber(const std::string infoType, const std::string infoPart){
    specType = infoType;
    eqspart = infoPart;
}

void EquationSpecificationTransfer::addEqnSet(const std::shared_ptr<EqnSet> eqnSet){
    eqnSets.push_back(eqnSet);
}

void EquationSpecificationTransfer::addLevelSet(const std::shared_ptr<LevelSet> levelSet){
    levelSets.push_back(levelSet);
}

void EquationSpecificationTransfer::printNumber() const{
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("EquationSpecificationTransferr specType: {}", specType);
    levelLogger->info("EquationSpecificationTransfer part: {}", eqspart);
}

void EquationSpecificationTransfer::printEqnSets() const{
    if(!eqnSets.empty()){
        for(const auto set : eqnSets){
            set->printSetNumber();
            set->printSetData();
            set->printSpecSets();
        }
    }
}

void EquationSpecificationTransfer::printLevelSets() const{
    if(!levelSets.empty()){
        for(const auto set : levelSets){
            set->printSetNumber();
            set->printSetData();
        }
    }
}