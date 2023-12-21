#ifndef ASTNODES_H
#define ASTNODES_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Forward declaration of classes
class Instruction;


class FileHeader {
public:
    FileHeader(){}
    std::vector<std::string> filetype;
    std::vector<std::shared_ptr<Instruction>> children;

    void connect(std::shared_ptr<Instruction> instruction) {
        children.push_back(instruction);
    }
};

extern std::shared_ptr<FileHeader> configheader;

class Instruction {
public:
    // Add parameters as member variables
    std::vector<std::string> parameters;
};

class DFPN : public Instruction {
public:

    std::vector<std::string> channel_no;
    std::vector<std::string> pinNo;
    std::vector<std::string> pin;
};

class DFPS : public Instruction {
public:
    std::vector<std::string> dps_channel;
    std::vector<std::string> polarity;
    std::vector<std::string> pin;
};

#endif // ASTNODES_H