#ifndef PINSET_H
#define PINSET_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class PinSet {
public:
    std::string pinlistGroup;

    std::vector<std::string> pinEdge;
    std::vector<std::string> pinValue;

    void setGroup(const std::string infoGroup);

    void addPinsData(const std::string infoPinEdge, const std::string infoPinValue);
                    
    void printGroup() const;

    void printPinsData() const;
  
};

#endif // PINSET_H