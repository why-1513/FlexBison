#include "LevelAST.h"

LevelFile::LevelFile() : pslv(std::make_shared<PowerSupplyLevel>()),
                         drlv(std::make_shared<DriveLevel>()),
                         rclv(std::make_shared<ReceiveLevel>()),
                         term(std::make_shared<TERMinationMode>()),
                         clmp(std::make_shared<ClampLevel>()),
                         lsux(std::make_shared<LevelSetsUsedExtended>()) {}

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