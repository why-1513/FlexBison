#ifndef LevelAST_H
#define LevelAST_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>


class LevelFile {
public:
    LevelFile(){}

    std::string filetype;

    void setFileType(const std::string& type) {
        if (type == "level") {
            filetype = type;
        } else {
            std::cerr << "Error: File type does not match." << std::endl;
            exit(1);
        }
    }
};

extern std::shared_ptr<LevelFile> levelfile;


#endif // LevelAST_H