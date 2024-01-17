#ifndef LEVELSETSUSEDEXTENDED_H
#define LEVELSETSUSEDEXTENDED_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class LevelSetsUsedExtended {
public:
    std::string levelSetNo;

    void setLevelSetNo(const std::string infoLevelSetNo);

    void printData() const;
};

#endif // LEVELSETSUSEDEXTENDED_H