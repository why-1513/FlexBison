#include "LevelSetsUsedExtended.h"

void LevelSetsUsedExtended::setLevelSetNo(const std::string infoLevelSetNo){
    levelSetNo = infoLevelSetNo;
}

void LevelSetsUsedExtended::printData() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("LSUX Data: {}",levelSetNo);
}