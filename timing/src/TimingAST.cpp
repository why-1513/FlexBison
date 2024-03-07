#include "TimingAST.h"

TimingFile::TimingFile() {}

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