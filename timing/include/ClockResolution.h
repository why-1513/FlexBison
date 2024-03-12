#ifndef CLOCKRESOLUTION_H
#define CLOCKRESOLUTION_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class ClockResolution {
public:
    std::vector<std::string> waveformSet;

    std::vector<std::string> specSetId;
    std::vector<std::string> multiportSpec;

    std::vector<std::string> refPeriod;
    std::vector<std::string> periodRes;

    void addData(const std::string infoWaveformSet, const std::string infoPeriodRes);
    
    void printPinList() const;

    void printData() const;
};

#endif // CLOCKRESOLUTION_H