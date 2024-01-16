#ifndef LevelAST_H
#define LevelAST_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "PowerSupplyLevel.h"
#include "LoggerManager.h"


class LevelFile {
public:
    LevelFile();

    std::string filetype;

    void setFileType(const std::string type);

    std::shared_ptr<PowerSupplyLevel> pslv;
    
};

extern std::shared_ptr<LevelFile> levelfile;


#endif // LevelAST_H