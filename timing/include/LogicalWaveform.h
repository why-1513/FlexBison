#ifndef LOGICALWAVEFORM_H
#define LOGICALWAVEFORM_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class LogicalWaveform {
public:
    std::string pinlistGroup;

    std::vector<std::string> physicalWaveformNumber;
    std::vector<std::vector<std::string>> pinEdge;
    std::vector<std::vector<std::string>> pinAction;
    std::vector<std::string> waveformName;

    void setGroup(const std::string infoGroup);

    void addPinsData(const std::string infoPhysicalWaveformNumber, const std::vector<std::string> infoPinEdge,
                    const std::vector<std::string> infoPinAction, const std::string infoWaveformName);
                    
    void printGroup() const;

    void printWaveformData() const;
  
};

#endif // LOGICALWAVEFORM_H