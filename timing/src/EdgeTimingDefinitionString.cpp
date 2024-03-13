#include "EdgeTimingDefinitionString.h"

void EdgeTimingDefinitionString::addData(const std::string infoWaveformSet, const std::string infoTimingSet,
                 const std::string infoDefinitionString, const std::vector<std::string> infoPinList){
    waveformSet.push_back(infoWaveformSet);
    timingSet.push_back(infoTimingSet);
    definitionString.push_back(infoDefinitionString);
    pinlist.push_back(infoPinList);
}

void EdgeTimingDefinitionString::printPinList() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("ETDS Pinlist:");

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

void EdgeTimingDefinitionString::printData() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("ETDS Data:");

    std::string vectorWaveformSet;
    std::string vectorTimingSet;
    std::string vectorDefinitionString;

    if(!waveformSet.empty()){
        for (const auto set : waveformSet) {
            vectorWaveformSet += set + "";
        }
        timingLogger->info("waveformSet: {}", vectorWaveformSet);
        vectorWaveformSet.clear();
    }

    if(!timingSet.empty()){
        for (const auto index : timingSet) {
            vectorTimingSet += index + "";
        }
        timingLogger->info("timingSet: {}", vectorTimingSet);
        vectorTimingSet.clear();
    }

    if(!definitionString.empty()){
        for (const auto period : definitionString) {
            vectorDefinitionString += period + "";
        }
        timingLogger->info("definitionString: {}", vectorDefinitionString);
        vectorDefinitionString.clear();
    }

}