#include "ClockResolution.h"

void ClockResolution::addData(const std::string infoWaveformSet, const std::string infoPeriodRes){
    waveformSet.push_back(infoWaveformSet);
    periodRes.push_back(infoPeriodRes);

}

void ClockResolution::printData() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("CLKR Data:");

    std::string vectorWaveformSet;
    std::string vectorPeriodRes;

    if(!waveformSet.empty()){
        for (const auto set : waveformSet) {
            vectorWaveformSet += set + "";
        }
        timingLogger->info("waveformSet: {}", vectorWaveformSet);
        vectorWaveformSet.clear();
    }

    if(!periodRes.empty()){
        for (const auto period : periodRes) {
            vectorPeriodRes += period + "";
        }
        timingLogger->info("periodRes: {}", vectorPeriodRes);
        vectorPeriodRes.clear();
    }

}