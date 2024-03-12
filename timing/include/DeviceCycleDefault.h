#ifndef DEVICECYCLEDEFAULT_H
#define DEVICECYCLEDEFAULT_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class DeviceCycleDefault {
public:
    std::vector<std::string> waveformSet;
    std::vector<std::string> defaultName;

    void addData(const std::string infoWaveformSet, const std::string infoDefaultName);
    
    void printPinList() const;

    void printData() const;
};

#endif // DEVICECYCLEDEFAULT_H