#ifndef TimingAST_H
#define TimingAST_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "PinClock.h"
#include "ClockResolution.h"
#include "BreakWaveformDefinitionString.h"
#include "EdgeTimingDefinitionString.h"
#include "DeviceCycleDefault.h"
#include "TimingSetsUsedEXtended.h"
#include "LoggerManager.h"

#include "EquationSpecificationTransfer.h"

class TimingFile {
public:
    TimingFile();

    std::string filetype;

    void setFileType(const std::string type);


    std::shared_ptr<PinClock> pclk;
    std::shared_ptr<ClockResolution> clkr;
    std::shared_ptr<BreakWaveformDefinitionString> bwds;
    std::shared_ptr<EdgeTimingDefinitionString> etds;
    std::shared_ptr<DeviceCycleDefault> dcdt;
    std::shared_ptr<TimingSetsUsedEXtended> tsux;

    std::vector<std::shared_ptr<EquationSpecificationTransfer>> eqsps;
    
};

extern std::shared_ptr<TimingFile> timingfile;


#endif // TimingAST_H