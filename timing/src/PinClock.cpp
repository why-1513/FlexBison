#include "PinClock.h"

void PinClock::addFixData(const std::string infoWaveformSet, const std::string infoTimingSet,
                 const std::string infoPeriod, const std::vector<std::string> infoPinList){
    waveformSet.push_back(infoWaveformSet);
    fixedTimingSet.push_back(infoTimingSet);
    fixPeriod.push_back(infoPeriod);
    pinlist.push_back(infoPinList);
}

void PinClock::printPinList() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("CLMP Pinlist:");

    if(!pinlist.empty()){
        for (const auto pinGroup : pinlist) {
            std::string vectorContents;
            for (const auto pin : pinGroup) {
                vectorContents += pin + " ";
            }
            timingLogger->info(vectorContents);
            vectorContents.clear();
        }
    }
}

void PinClock::printData() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("PCLK Data:");

    std::string vectorWaveformSet;
    std::string vectorTimingSet;
    std::string vectorPeriod;

    if(!waveformSet.empty()){
        for (const auto set : waveformSet) {
            vectorWaveformSet += set + "";
        }
        timingLogger->info("waveformSet: {}", vectorWaveformSet);
        vectorWaveformSet.clear();
    }

    if(!fixedTimingSet.empty()){
        for (const auto set : fixedTimingSet) {
            vectorTimingSet += set + "";
        }
        timingLogger->info("fixedTimingSet: {}", vectorTimingSet);
        vectorTimingSet.clear();
    }

    if(!fixPeriod.empty()){
        for (const auto period : fixPeriod) {
            vectorPeriod += period + "";
        }
        timingLogger->info("fixperiod: {}", vectorPeriod);
        vectorPeriod.clear();
    }

}