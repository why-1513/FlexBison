#ifndef TIMINGSETSUSEDEXTENDED_H
#define TIMINGSETSUSEDEXTENDED_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class TimingSetsUsedEXtended {
public:
    std::vector<std::string> waveformSet;
    std::vector<std::string> timingSet;

    void addData(const std::string infoWaveformSet, const std::string infoTimingSet);

    void printData() const;
};

#endif // TIMINGSETSUSEDEXTENDED_H