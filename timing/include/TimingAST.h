#ifndef TimingAST_H
#define TimingAST_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "LoggerManager.h"

class TimingFile {
public:
    TimingFile();

    std::string filetype;

    void setFileType(const std::string type);

};

extern std::shared_ptr<TimingFile> timingfile;


#endif // TimingAST_H