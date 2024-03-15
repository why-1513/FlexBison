#include "PinSet.h"

void PinSet::setGroup(const std::string infoGroup){
    pinlistGroup = infoGroup;
}

void PinSet::addPinsData(const std::string infoPinEdge, const std::string infoPinValue){
    pinEdge.push_back(infoPinEdge);
    pinValue.push_back(infoPinValue);
}

void PinSet::printGroup() const{
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("PinSet Name: {}", pinlistGroup);
}

void PinSet::printPinsData() const{
    auto timingLogger = LoggerManager::getTimingLogger();

    if(!pinEdge.empty()){
        for(size_t num = 0; num < pinEdge.size(); num++){
            timingLogger->info("{} = {}", pinEdge[num], pinValue[num]);
        }
    }

}
