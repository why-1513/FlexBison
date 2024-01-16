#include "LevelAST.h"

LevelFile::LevelFile() : pslv(std::make_shared<PowerSupplyLevel>()) {}

void LevelFile::setFileType(const std::string type) {
    auto levelLogger = LoggerManager::getLevelLogger();
    if (type == "level") {
        filetype = type;
        levelLogger->info("Get a level file.");
    } else {
        levelLogger->error("Error: File type does not match.");
        exit(1);
    }
}