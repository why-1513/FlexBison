#ifndef DEFINEPOWERSUPPLY_H
#define DEFINEPOWERSUPPLY_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class DefinePowerSupply {
public:
    std::vector<std::string> dpsChannel;
    std::vector<std::string> polarity;
    std::vector<std::string> pin;

    void addData(const std::string infoDpsChannel,
                 const std::string infoPolarity, const std::string infoPin);

    void printData() const;
};

#endif // DEFINEPOWERSUPPLY_H