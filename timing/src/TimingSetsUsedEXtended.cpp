#include "TimingSetsUsedEXtended.h"

void TimingSetsUsedEXtended::addData(const std::string infoWaveformSet, const std::string infoTimingSet){
    waveformSet.push_back(infoWaveformSet);
    timingSet.push_back(infoTimingSet);
}

void TimingSetsUsedEXtended::printData() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("DCDT Data:");

    std::string vectorWaveformSet;
    std::string vectorTimingSet;

    if(!waveformSet.empty()){
        for (const auto set : waveformSet) {
            vectorWaveformSet += set + "";
        }
        timingLogger->info("waveformSet: {}", vectorWaveformSet);
        vectorWaveformSet.clear();
    }

    if(!timingSet.empty()){
        for (const auto set : timingSet) {
            vectorTimingSet += set + "";
        }
        timingLogger->info("timingSet: {}", vectorTimingSet);
        vectorTimingSet.clear();
    }

}