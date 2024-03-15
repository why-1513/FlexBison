#ifndef WAVETBL_H
#define WAVETBL_H

#include <vector>
#include <string>
#include <memory>
#include "LoggerManager.h"

#include "LogicalWaveform.h"
#include "SpecSet.h"

class WaveTBL {
public:
    std::string wavetblName;

    std::vector<std::shared_ptr<LogicalWaveform>> waveforms;

    std::vector<std::shared_ptr<SpecSet>> specSets;

    void setName(const std::string infoWavetblName);
    void addWaveform(const std::shared_ptr<LogicalWaveform> waveform);
    void addSpecSet(const std::shared_ptr<SpecSet> specSet);

    void printWaveName() const;
    void printWaveform() const;
    void printSpecSets() const;
  
};

#endif // WAVETBL_H