#include "WaveTBL.h"

void WaveTBL::setName(const std::string infoWavetblName){
    wavetblName = infoWavetblName;
}

void WaveTBL::addWaveform(const std::shared_ptr<LogicalWaveform> waveform){
    waveforms.push_back(waveform);
}

void WaveTBL::addSpecSet(const std::shared_ptr<SpecSet> specSet){
    specSets.push_back(specSet);
}

void WaveTBL::printWaveName() const{
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("WaveTBL Name: {}", wavetblName);
}

void WaveTBL::printWaveform() const{
    auto timingLogger = LoggerManager::getTimingLogger();

    if(!waveforms.empty()){
        for(const auto form : waveforms){
            form->printGroup();
            form->printWaveformData();
        }
    }

}

void WaveTBL::printSpecSets() const {

    if(!specSets.empty()){
        for(const auto set : specSets){
            set->printSetNumber();
            set->printSetData();
        }
    }
}