#ifndef DEFINEPINNAME_H
#define DEFINEPINNAME_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class DefinePinName {
public:
    std::vector<std::string> channelNo;
    std::vector<std::string> pinNo;
    std::vector<std::string> pin;

    void addData(const std::string infoChannelNo,
                 const std::string infoPinNo, const std::string infoPin);

    void printData() const;
};

#endif // DEFINEPINNAME_H