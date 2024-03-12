#ifndef PINCLOCK_H
#define PINCLOCK_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class PinClock {
public:
    std::vector<std::string> waveformSet;
    std::vector<std::string> fixedTimingSet;
    std::vector<std::string> fixPeriod;

    // 不知道该怎么去区分 Fixed timing 和 Equation-based timing

    std::vector<std::string> specsetId;
    std::vector<std::string> multiportSpec;
    std::vector<std::string> equationTimingSet;
    std::vector<std::string> equationPeriod;


    std::vector<std::vector<std::string>> pinlist;

    void addFixData(const std::string infoWaveFormSet, const std::string infoTimingSet,
                 const std::string infoPeriod, const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // PINCLOCK_H