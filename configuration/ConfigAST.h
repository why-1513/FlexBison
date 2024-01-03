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
        if (type == "config") {
            filetype = type;
        } else {
            std::cerr << "Error: File type does not match." << std::endl;
            exit(1);
        }
    }

    class DefinePinName {
    public:
        std::vector<std::string> channelNo;
        std::vector<std::string> pinNo;
        std::vector<std::string> pin;

        void addData(const std::string& infoChannelNo,
         const std::string& infoPinNo, const std::string& infoPin) {
            channelNo.push_back(infoChannelNo);
            pinNo.push_back(infoPinNo);
            pin.push_back(infoPin);
        } 

        void printData() const {
            std::cout << "DefinePinName Data:" << std::endl;
            std::cout << "Channel No: ";
            for (const auto& channel : channelNo) {
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

    std::shared_ptr<DefinePinName> dfpn = std::make_shared<DefinePinName>();

    class DefinePowerSupply {
    public:
        std::vector<std::string> dpsChannel;
        std::vector<std::string> polarity;
        std::vector<std::string> pin;

        void addData(const std::string& infoDpsChannel,
         const std::string& infoPolarity, const std::string& infoPin){
            dpsChannel.push_back(infoDpsChannel);
            polarity.push_back(infoPolarity);
            pin.push_back(infoPin);
        }

        void printData() const {
            std::cout << "DFPS Data:" << std::endl;
            std::cout << "DPS Channel: ";
            for (const auto& channel : dpsChannel) {
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

    std::shared_ptr<DefinePowerSupply> dfps = std::make_shared<DefinePowerSupply>();

    class ParallelSiteEnable {
    public:
        std::string sites;

        void setSites(const std::string& infoSites) {
            sites = infoSites;
        }

        void printData() const {
            std::cout << "PSTE Data:" << std::endl;
            std::cout << "Sites: " << sites << std::endl;
        }
    };

    std::shared_ptr<ParallelSiteEnable> pste = std::make_shared<ParallelSiteEnable>();

    class CONFGuration {
    public:
        std::vector<std::string> context;
        std::vector<std::string> pinType;
        std::vector<std::string> pinOperMode;
        std::vector<std::vector<std::string>> pinlist;

        void addData(const std::string& infoContext, const std::string& infoPinType,
         const std::string& infoPinOperMode, const std::vector<std::string>& infoPinList) {
            context.push_back(infoContext);
            pinType.push_back(infoPinType);
            pinOperMode.push_back(infoPinOperMode);
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

        void printData() const {
            std::cout << "CONF Data:" << std::endl;
            std::cout << "Context: ";
            for (const auto& text : context) {
                std::cout << text << " ";
            }
            std::cout << std::endl;

            std::cout << "PinType: ";
            for (const auto& type : pinType) {
                std::cout << type << " ";
            }
            std::cout << std::endl;

            std::cout << "PinOperMode: ";
            for (const auto& mode : pinOperMode) {
                std::cout << mode << " ";
            }
            std::cout << std::endl;
        }

    };

    std::shared_ptr<CONFGuration> conf = std::make_shared<CONFGuration>();

    class DefineGroup {
    public:
        std::vector<std::string> pinType;
        std::vector<std::string> pinGroup;
        std::vector<std::vector<std::string>> pinlist;

        void addData(const std::string& infoPinType,
         const std::vector<std::string>& infoPinList, const std::string& infoPinGroup) {
            pinType.push_back(infoPinType);
            pinGroup.push_back(infoPinGroup);
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

        void printData() const {
            std::cout << "DFGP Data:" << std::endl;

            std::cout << "PinType: ";
            for (const auto& type : pinType) {
                std::cout << type << " ";
            }
            std::cout << std::endl;

            std::cout << "PinGroup: ";
            for (const auto& group : pinGroup) {
                std::cout << group << " ";
            }
            std::cout << std::endl;
        }
    
    };

    std::shared_ptr<DefineGroup> dfgp = std::make_shared<DefineGroup>();

    class PowerSupplyLoadCapacitance {
    public:
        std::vector<std::string> value;
        std::vector<std::string> DCSValue;
        std::vector<std::vector<std::string>> pinlist;

        void addData(const std::string& infoValue, const std::string& infoDCSValue,
         const std::vector<std::string>& infoPinList) {
            value.push_back(infoValue);
            DCSValue.push_back(infoDCSValue);
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

        void printData() const {
            std::cout << "PSLC Data:" << std::endl;

            std::cout << "Value: ";
            for (const auto& value : value) {
                std::cout << value << " ";
            }
            std::cout << std::endl;

            std::cout << "DCSValue: ";
            for (const auto& value : DCSValue) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
        
    };

    std::shared_ptr<PowerSupplyLoadCapacitance> pslc = std::make_shared<PowerSupplyLoadCapacitance>();

    class PowerSupplySafetyLimits {
    public:
        std::vector<std::string> minVoltage;
        std::vector<std::string> maxVoltage;
        std::vector<std::string> maxSourceCurrent;
        std::vector<std::string> maxSinkCurrent;
        std::vector<std::vector<std::string>> pinlist;

        void addData(const std::string& infoMinVol, const std::string& infoMaxVol,
         const std::string& infoMaxSourceCurrent, const std::string& infoMaxSinkCurrent,
          const std::vector<std::string>& infoPinList) {
            minVoltage.push_back(infoMinVol);
            maxVoltage.push_back(infoMaxVol);
            maxSourceCurrent.push_back(infoMaxSourceCurrent);
            maxSinkCurrent.push_back(infoMaxSinkCurrent);
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

        void printData() const {
            std::cout << "PSSL Data:" << std::endl;

            std::cout << "MinVoltage: ";
            for (const auto& vol : minVoltage) {
                std::cout << vol << " ";
            }
            std::cout << std::endl;

            std::cout << "MaxVoltage: ";
            for (const auto& vol : maxVoltage) {
                std::cout << vol << " ";
            }
            std::cout << std::endl;

            std::cout << "MaxSourceCurrent: ";
            for (const auto& current : maxSourceCurrent) {
                std::cout << current << " ";
            }
            std::cout << std::endl;

            std::cout << "MaxSinkCurrent: ";
            for (const auto& current : maxSinkCurrent) {
                std::cout << current << " ";
            }
            std::cout << std::endl;
        }
        
    };

    std::shared_ptr<PowerSupplySafetyLimits> pssl = std::make_shared<PowerSupplySafetyLimits>();

};

extern std::shared_ptr<ConfigFile> configfile;

#endif // ConfigAST_H