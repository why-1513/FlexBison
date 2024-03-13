#include "DeviceCycleDefault.h"

void DeviceCycleDefault::addData(const std::string infoWaveformSet, const std::string infoDefaultName){
    waveformSet.push_back(infoWaveformSet);
    defaultName.push_back(infoDefaultName);
}

void DeviceCycleDefault::printData() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("DCDT Data:");

    std::string vectorWaveformSet;
    std::string vectorDefaultName;

    if(!waveformSet.empty()){
        for (const auto set : waveformSet) {
            vectorWaveformSet += set + "";
        }
        timingLogger->info("waveformSet: {}", vectorWaveformSet);
        vectorWaveformSet.clear();
    }

    if(!defaultName.empty()){
        for (const auto name : defaultName) {
            vectorDefaultName += name + "";
        }
        timingLogger->info("defaultName: {}", vectorDefaultName);
        vectorDefaultName.clear();
    }

}