#ifndef ASTNODES_H
#define ASTNODES_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Forward declaration of classes
class Instruction;
class DFPN;

class ConfigFile {
public:
    ConfigFile(){}
    std::string filetype;
    
    std::vector<std::string> DFPN_channel_no;
    std::vector<std::string> DFPN_pinNo;
    std::vector<std::string> DFPN_pin;
    };

extern std::shared_ptr<ConfigFile> configfile;

#endif // ASTNODES_H