#ifndef LevelAST_H
#define LevelAST_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "PowerSupplyLevel.h"
#include "DriveLevel.h"
#include "ReceiveLevel.h"
#include "TERMinationMode.h"
#include "ClampLevel.h"
#include "LevelSetsUsedExtended.h"
#include "LoggerManager.h"


class LevelFile {
public:
    LevelFile();

    std::string filetype;

    void setFileType(const std::string type);

    std::shared_ptr<PowerSupplyLevel> pslv;
    std::shared_ptr<DriveLevel> drlv;
    std::shared_ptr<ReceiveLevel> rclv;
    std::shared_ptr<TERMinationMode> term;
    std::shared_ptr<ClampLevel> clmp;
    std::shared_ptr<LevelSetsUsedExtended> lsux;
    
};

extern std::shared_ptr<LevelFile> levelfile;


#endif // LevelAST_H