#ifndef TIMINGSET_H
#define TIMINGSET_H

#include <vector>
#include <string>
#include "LoggerManager.h"

#include "PinSet.h"

class TimingSet {
public:
    std::string timingSetNumber;
    std::string timingSetDescription;

    std::string period;

    std::vector<std::shared_ptr<PinSet>> pinSets;

    void setNumber(const std::string infoNumber, const std::string infoDescription);
    void setPeriod(const std::string infoPeriod);
    void addPinSet(const std::shared_ptr<PinSet> pinSet);

    void printSetNumber() const;
    void printSets() const;
    void printPeriod() const;
  
};

#endif // TIMINGSET_H