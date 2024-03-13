#include "BreakWaveformDefinitionString.h"

void BreakWaveformDefinitionString::addData(const std::string infoWvfSetSet, const std::string infoBreakWaveformIndex,
                 const std::string infoDefinitionString, const std::vector<std::string> infoPinList){
    wvfSet.push_back(infoWvfSetSet);
    breakWaveformIndex.push_back(infoBreakWaveformIndex);
    definitionString.push_back(infoDefinitionString);
    pinlist.push_back(infoPinList);
}

void BreakWaveformDefinitionString::printPinList() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("BWDS Pinlist:");

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

void BreakWaveformDefinitionString::printData() const {
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("BWDS Data:");

    std::string vectorWvfSet;
    std::string vectorBreakWaveformIndex;
    std::string vectorDefinitionString;

    if(!wvfSet.empty()){
        for (const auto set : wvfSet) {
            vectorWvfSet += set + "";
        }
        timingLogger->info("wvfSet: {}", vectorWvfSet);
        vectorWvfSet.clear();
    }

    if(!breakWaveformIndex.empty()){
        for (const auto index : breakWaveformIndex) {
            vectorBreakWaveformIndex += index + "";
        }
        timingLogger->info("breakWaveformIndex: {}", vectorBreakWaveformIndex);
        vectorBreakWaveformIndex.clear();
    }

    if(!definitionString.empty()){
        for (const auto strings : definitionString) {
            vectorDefinitionString += strings + "";
        }
        timingLogger->info("definitionString: {}", vectorDefinitionString);
        vectorDefinitionString.clear();
    }

}