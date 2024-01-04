#include "DefinePinName.h"

void DefinePinName::addData(const std::string infoChannelNo,
         const std::string infoPinNo, const std::string infoPin) {
            channelNo.push_back(infoChannelNo);
            pinNo.push_back(infoPinNo);
            pin.push_back(infoPin);
        }

void DefinePinName::printData() const {
            std::cout << "DefinePinName Data:" << std::endl;
            std::cout << "Channel No: ";
            for (const auto channel : channelNo) {
                std::cout << channel << " ";
            }
            std::cout << std::endl;

            std::cout << "Pin No: ";
            for (const auto pinNo : pinNo) {
                std::cout << pinNo << " ";
            }
            std::cout << std::endl;

            std::cout << "Pin: ";
            for (const auto pin : pin) {
                std::cout << pin << " ";
            }
            std::cout << std::endl;
        }