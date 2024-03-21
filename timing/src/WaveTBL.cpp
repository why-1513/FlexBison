#include "WaveTBL.h"

void WaveTBL::setName(const std::string infoWavetblName){
    wavetblName = infoWavetblName;
}

void WaveTBL::addWaveform(const std::shared_ptr<LogicalWaveform> waveform){
    waveforms.push_back(waveform);
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
