#include "DefinePinName.h"

void DefinePinName::addData(const std::string infoChannelNo,
         const std::string infoPinNo, const std::string infoPin) {
            channelNo.push_back(infoChannelNo);
            pinNo.push_back(infoPinNo);
            pin.push_back(infoPin);
        }

void DefinePinName::printData() const {
    auto configLogger = LoggerManager::getConfigLogger();
    configLogger->info("DefinePinName Data:");

    std::string vectorChannelNo;
    std::string vectorPinNo;
    std::string vectorPin;

    if(!channelNo.empty()){
        for (const auto channel : channelNo) {
            vectorChannelNo += channel + " ";
        }
        configLogger->info("Channel No: {}", vectorChannelNo);
        vectorChannelNo.clear();
    }

    if(!pinNo.empty()){
        for (const auto pinNo : pinNo) {
            vectorPinNo += pinNo + " ";
        }
        configLogger->info("Pin No: {}", vectorPinNo);
        vectorPinNo.clear();
    }

    if(!pin.empty()){
        for (const auto pin : pin) {
            vectorPin += pin + " ";
        }
        configLogger->info("Pin: {}", vectorPin);
        vectorPin.clear();
    }
}