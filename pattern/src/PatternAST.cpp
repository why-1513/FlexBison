#include "PatternAST.h"

PatternFile::PatternFile() {}

void PatternFile::setFileType(const std::string type) {
    auto patternLogger = LoggerManager::getPatternLogger();
    if (type == "pattern") {
        filetype = type;
        patternLogger->info("Get a pattern file.");
    } else {
        patternLogger->error("Error: File type does not match.");
        exit(1);
    }
}