#include "TimingAST.h"

TimingFile::TimingFile() : pclk(std::make_shared<PinClock>()),
                           clkr(std::make_shared<ClockResolution>()),
                           bwds(std::make_shared<BreakWaveformDefinitionString>()),
                           etds(std::make_shared<EdgeTimingDefinitionString>()),
                           dcdt(std::make_shared<DeviceCycleDefault>()),
                           tsux(std::make_shared<TimingSetsUsedEXtended>()) {}

void TimingFile::setFileType(const std::string type) {
    auto timingLogger = LoggerManager::getTimingLogger();
    if (type == "timing") {
        filetype = type;
        timingLogger->info("Get a timing file.");
    } else {
        timingLogger->error("Error: File type does not match.");
        exit(1);
    }
}