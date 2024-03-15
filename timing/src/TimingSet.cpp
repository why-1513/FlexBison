#include "TimingSet.h"

void TimingSet::setNumber(const std::string infoNumber, const std::string infoDescription){
    timingSetNumber = infoNumber;
    timingSetDescription = infoDescription;
}

void TimingSet::addPinSet(const std::shared_ptr<PinSet> pinSet){
    pinSets.push_back(pinSet);
}

void TimingSet::printSetNumber() const{
    auto timingLogger = LoggerManager::getTimingLogger();
    timingLogger->info("TimingSet Number: {}", timingSetNumber);
    timingLogger->info("TimingSet Description: {}", timingSetDescription);
}

void TimingSet::printSets() const {

    if(!pinSets.empty()){
        for(const auto set : pinSets){
            set->printGroup();
            set->printPinsData();
        }
    }
}