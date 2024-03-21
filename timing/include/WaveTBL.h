#ifndef WAVETBL_H
#define WAVETBL_H

#include <vector>
#include <string>
#include <memory>
#include "LoggerManager.h"

#include "LogicalWaveform.h"

class WaveTBL {
public:
    std::string wavetblName;

    std::vector<std::shared_ptr<LogicalWaveform>> waveforms;

    void setName(const std::string infoWavetblName);
    void addWaveform(const std::shared_ptr<LogicalWaveform> waveform);

    void printWaveName() const;
    void printWaveform() const;
  
};

#endif // WAVETBL_H