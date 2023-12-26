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

        void addDFPNData(const std::string& infoChannelNo, const std::string& infoPinNo, const std::string& infoPin) {
            channel_no.push_back(infoChannelNo);
            pinNo.push_back(infoPinNo);
            pin.push_back(infoPin);
        } 
    };

    std::shared_ptr<DFPN> dfpn = std::make_shared<DFPN>();

    class DFPS {
    public:
        std::vector<std::string> dps_channel;
        std::vector<std::string> polarity;
        std::vector<std::string> pin;

        void addDFPSData(const std::string& infoDpsChannel, const std::string& infoPolarity, const std::string& infoPin){
            dps_channel.push_back(infoDpsChannel);
            polarity.push_back(infoPolarity);
            pin.push_back(infoPin);
        }
    };

    std::shared_ptr<DFPS> dfps = std::make_shared<DFPS>();

    class PSTE {
    public:
        std::string sites;

        void setSites(const std::string& infoSites) {
            sites = infoSites;
        }
    };

    std::shared_ptr<PSTE> pste = std::make_shared<PSTE>();

    class CONF {
    public:
        std::vector<std::string> context;
        std::vector<std::string> pin_type;
        std::vector<std::string> pin_oper_mode;
        std::vector<std::vector<std::string>> pinlist;

        void addCONFData(const std::string& infoContext, const std::string& infoPinType, const std::string& infoPinOperMode, const std::vector<std::string>& infoPinList) {
            context.push_back(infoContext);
            pin_type.push_back(infoPinType);
            pin_oper_mode.push_back(infoPinOperMode);
            pinlist.push_back(infoPinList);
        }

        void printPinList() const {
            for (const auto& pinGroup : pinlist) {
                for (const auto& pin : pinGroup) {
                    std::cout << pin << " ";
                }
                std::cout << std::endl;
            }
        }

    };

    std::shared_ptr<CONF> conf = std::make_shared<CONF>();

    class DFGP {
    public:
        std::vector<std::string> pin_type;
        std::vector<std::string> pin_group;
        std::vector<std::vector<std::string>> pinlist;

        void addDFGPData(const std::string& infoPinType, const std::vector<std::string>& infoPinList, const std::string& infoPinGroup) {
            pin_type.push_back(infoPinType);
            pin_group.push_back(infoPinGroup);
            pinlist.push_back(infoPinList);
        }

        void printPinList() const {
            for (const auto& pinGroup : pinlist) {
                for (const auto& pin : pinGroup) {
                    std::cout << pin << " ";
                }
                std::cout << std::endl;
            }
        }
    
    };

    std::shared_ptr<DFGP> dfgp = std::make_shared<DFGP>();

};

extern std::shared_ptr<ConfigFile> configfile;

#endif // ASTNODES_H