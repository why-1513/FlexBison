#include "LogicalWaveform.h"

void LogicalWaveform::setGroup(const std::string infoGroup){
    pinlistGroup = infoGroup;
}

void LogicalWaveform::addPinsData(const std::string infoPhysicalWaveformNumber, const std::vector<std::string> infoPinEdge,
                    const std::vector<std::string> infoPinAction, const std::string infoWaveformName){
    physicalWaveformNumber.push_back(infoPhysicalWaveformNumber);
    pinEdge.push_back(infoPinEdge);
    pinAction.push_back(infoPinAction);
    waveformName.push_back(infoWaveformName);
}
                    
void LogicalWaveform::printGroup() const{
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("pinlist Name: {}", pinlistGroup);
}

void LogicalWaveform::printWaveformData() const{
    auto timingLogger = LoggerManager::getTimingLogger();

    std::string EdgeAndAction;

    if(!physicalWaveformNumber.empty()){
        timingLogger->info("Waveform info:");

        for(size_t num = 0; num < physicalWaveformNumber.size(); num++){

            if(num < pinEdge.size() && num < pinAction.size()){

                for(size_t i = 0; i < pinEdge[num].size() && i < pinAction[num].size(); i++){
                    EdgeAndAction = pinEdge[num][i] + ":" + pinAction[num][i] + " "; 
                }
            }

            timingLogger->info("{} {} {}", physicalWaveformNumber[num], EdgeAndAction, waveformName);
            EdgeAndAction.clear();

        }

    }
}