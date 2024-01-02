#ifndef ConfigAST_H
#define ConfigAST_H
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

        void addDFPNData(const std::string& infoChannelNo,
         const std::string& infoPinNo, const std::string& infoPin) {
            channel_no.push_back(infoChannelNo);
            pinNo.push_back(infoPinNo);
            pin.push_back(infoPin);
        } 

        void printDFPNData() const {
            std::cout << "DFPN Data:" << std::endl;
            std::cout << "Channel No: ";
            for (const auto& channel : channel_no) {
                std::cout << channel << " ";
            }
            std::cout << std::endl;

            std::cout << "Pin No: ";
            for (const auto& pinNo : pinNo) {
                std::cout << pinNo << " ";
            }
            std::cout << std::endl;

            std::cout << "Pin: ";
            for (const auto& pin : pin) {
                std::cout << pin << " ";
            }
            std::cout << std::endl;
        }
    };

    std::shared_ptr<DFPN> dfpn = std::make_shared<DFPN>();

    class DFPS {
    public:
        std::vector<std::string> dps_channel;
        std::vector<std::string> polarity;
        std::vector<std::string> pin;

        void addDFPSData(const std::string& infoDpsChannel,
         const std::string& infoPolarity, const std::string& infoPin){
            dps_channel.push_back(infoDpsChannel);
            polarity.push_back(infoPolarity);
            pin.push_back(infoPin);
        }

        void printDFPSData() const {
            std::cout << "DFPS Data:" << std::endl;
            std::cout << "DPS Channel: ";
            for (const auto& channel : dps_channel) {
                std::cout << channel << " ";
            }
            std::cout << std::endl;

            std::cout << "Polarity: ";
            for (const auto& polarity : polarity) {
                std::cout << polarity << " ";
            }
            std::cout << std::endl;

            std::cout << "Pin: ";
            for (const auto& pin : pin) {
                std::cout << pin << " ";
            }
            std::cout << std::endl;
        }
    };

    std::shared_ptr<DFPS> dfps = std::make_shared<DFPS>();

    class PSTE {
    public:
        std::string sites;

        void setSites(const std::string& infoSites) {
            sites = infoSites;
        }

        void printPSTEData() const {
            std::cout << "PSTE Data:" << std::endl;
            std::cout << "Sites: " << sites << std::endl;
        }
    };

    std::shared_ptr<PSTE> pste = std::make_shared<PSTE>();

    class CONF {
    public:
        std::vector<std::string> context;
        std::vector<std::string> pin_type;
        std::vector<std::string> pin_oper_mode;
        std::vector<std::vector<std::string>> pinlist;

        void addCONFData(const std::string& infoContext, const std::string& infoPinType,
         const std::string& infoPinOperMode, const std::vector<std::string>& infoPinList) {
            context.push_back(infoContext);
            pin_type.push_back(infoPinType);
            pin_oper_mode.push_back(infoPinOperMode);
            pinlist.push_back(infoPinList);
        }

        void printPinList() const {
            std::cout << "CONF Pinlist:" << std::endl;
            for (const auto& pinGroup : pinlist) {
                for (const auto& pin : pinGroup) {
                    std::cout << pin << " ";
                }
                std::cout << std::endl;
            }
        }

        void printCONFData() const {
            std::cout << "CONF Data:" << std::endl;
            std::cout << "Context: ";
            for (const auto& text : context) {
                std::cout << text << " ";
            }
            std::cout << std::endl;

            std::cout << "PinType: ";
            for (const auto& type : pin_type) {
                std::cout << type << " ";
            }
            std::cout << std::endl;

            std::cout << "PinOperMode: ";
            for (const auto& mode : pin_oper_mode) {
                std::cout << mode << " ";
            }
            std::cout << std::endl;
        }

    };

    std::shared_ptr<CONF> conf = std::make_shared<CONF>();

    class DFGP {
    public:
        std::vector<std::string> pin_type;
        std::vector<std::string> pin_group;
        std::vector<std::vector<std::string>> pinlist;

        void addDFGPData(const std::string& infoPinType,
         const std::vector<std::string>& infoPinList, const std::string& infoPinGroup) {
            pin_type.push_back(infoPinType);
            pin_group.push_back(infoPinGroup);
            pinlist.push_back(infoPinList);
        }

        void printPinList() const {
            std::cout << "DFGP Pinlist:" << std::endl;
            for (const auto& pinGroup : pinlist) {
                for (const auto& pin : pinGroup) {
                    std::cout << pin << " ";
                }
                std::cout << std::endl;
            }
        }

        void printDFGPData() const {
            std::cout << "CONF Data:" << std::endl;

            std::cout << "PinType: ";
            for (const auto& type : pin_type) {
                std::cout << type << " ";
            }
            std::cout << std::endl;

            std::cout << "PinGroup: ";
            for (const auto& group : pin_group) {
                std::cout << group << " ";
            }
            std::cout << std::endl;
        }
    
    };

    std::shared_ptr<DFGP> dfgp = std::make_shared<DFGP>();

    class PSLC {
    public:
        std::vector<std::string> value;
        std::vector<std::string> DCS_value;
        std::vector<std::vector<std::string>> pinlist;

        void addPSLCData(const std::string& infoValue, const std::string& infoDCSValue,
         const std::vector<std::string>& infoPinList) {
            value.push_back(infoValue);
            DCS_value.push_back(infoDCSValue);
            pinlist.push_back(infoPinList);
        }

        void printPinList() const {
            std::cout << "PSLC Pinlist:" << std::endl;
            for (const auto& pinGroup : pinlist) {
                for (const auto& pin : pinGroup) {
                    std::cout << pin << " ";
                }
                std::cout << std::endl;
            }
        }

        void printPSLCData() const {
            std::cout << "PSLC Data:" << std::endl;

            std::cout << "Value: ";
            for (const auto& value : value) {
                std::cout << value << " ";
            }
            std::cout << std::endl;

            std::cout << "DCSValue: ";
            for (const auto& value : DCS_value) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
        
    };

    std::shared_ptr<PSLC> pslc = std::make_shared<PSLC>();

    class PSSL {
    public:
        std::vector<std::string> min_voltage;
        std::vector<std::string> max_voltage;
        std::vector<std::string> max_source_current;
        std::vector<std::string> max_sink_current;
        std::vector<std::vector<std::string>> pinlist;

        void addPSSLData(const std::string& infoMinVol, const std::string& infoMaxVol,
         const std::string& infoMaxSourceCurrent, const std::string& infoMaxSinkCurrent,
          const std::vector<std::string>& infoPinList) {
            min_voltage.push_back(infoMinVol);
            max_voltage.push_back(infoMaxVol);
            max_source_current.push_back(infoMaxSourceCurrent);
            max_sink_current.push_back(infoMaxSinkCurrent);
            pinlist.push_back(infoPinList);
        }

        void printPinList() const {
            std::cout << "PSSL Pinlist:" << std::endl;
            for (const auto& pinGroup : pinlist) {
                for (const auto& pin : pinGroup) {
                    std::cout << pin << " ";
                }
                std::cout << std::endl;
            }
        }

        void printPSSLData() const {
            std::cout << "PSSL Data:" << std::endl;

            std::cout << "MinVoltage: ";
            for (const auto& vol : min_voltage) {
                std::cout << vol << " ";
            }
            std::cout << std::endl;

            std::cout << "MaxVoltage: ";
            for (const auto& vol : max_voltage) {
                std::cout << vol << " ";
            }
            std::cout << std::endl;

            std::cout << "MaxSourceCurrent: ";
            for (const auto& current : max_source_current) {
                std::cout << current << " ";
            }
            std::cout << std::endl;

            std::cout << "MaxSinkCurrent: ";
            for (const auto& current : max_sink_current) {
                std::cout << current << " ";
            }
            std::cout << std::endl;
        }
        
    };

    std::shared_ptr<PSSL> pssl = std::make_shared<PSSL>();

};

extern std::shared_ptr<ConfigFile> configfile;

#endif // ConfigAST_H