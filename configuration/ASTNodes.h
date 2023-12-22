#ifndef ASTNODES_H
#define ASTNODES_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>



class ConfigFile {
public:
    ConfigFile() {}
    std::string filetype;

    void setFileType(const std::string& type) {
        filetype = type;
    }

    class DFPN {
    public:
        std::vector<std::string> channel_no;
        std::vector<std::string> pinNo;
        std::vector<std::string> pin;

        void addDFPNData(const std::string& info_channel, const std::string& info_pinNo, const std::string& info_pin) {
            channel_no.push_back(info_channel);
            pinNo.push_back(info_pinNo);
            pin.push_back(info_pin);
    } 
    };

    std::shared_ptr<DFPN> dfpn = std::make_shared<DFPN>();

};

extern std::shared_ptr<ConfigFile> configfile;

#endif // ASTNODES_H