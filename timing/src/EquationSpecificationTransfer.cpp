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

void EquationSpecificationTransfer::addWaveTbl(const std::shared_ptr<WaveTBL> waveTbl){
    waveTbls.push_back(waveTbl);
}

void EquationSpecificationTransfer::addTimingSet(const std::shared_ptr<TimingSet> timingSet){
    timingSets.push_back(timingSet);
}

void EquationSpecificationTransfer::printNumber() const{
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("EquationSpecificationTransferr specType: {}", specType);
    timingLogger->info("EquationSpecificationTransfer part: {}", eqspart);
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

void EquationSpecificationTransfer::printWaveTbls() const{
    if(!waveTbls.empty()){
        for(const auto tbl : waveTbls){
            tbl->printWaveName();
            tbl->printWaveform();
            tbl->printSpecSets();
        }
    }
}

void EquationSpecificationTransfer::printLevelSets() const{
    if(!timingSets.empty()){
        for(const auto set : timingSets){
            set->printSetNumber();
            set->printSets();
        }
    }
}