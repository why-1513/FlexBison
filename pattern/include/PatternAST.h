#ifndef PatternAST_H
#define PatternAST_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "LoggerManager.h"

class PatternFile {
public:
    PatternFile();

    std::string filetype;

    void setFileType(const std::string type);
    
};

extern std::shared_ptr<PatternFile> patternfile;


#endif // PatternAST_H