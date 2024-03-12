#ifndef BREAKWAVEFORMDEFINITIONSTRING_H
#define BREAKWAVEFORMDEFINITIONSTRING_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class BreakWaveformDefinitionString {
public:
    std::vector<std::string> wvfSet;
    std::vector<std::string> breakWaveformIndex;
    std::vector<std::string> bwdsMode;
    std::vector<std::string> definitionString;

    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string infoWvfSet, const std::string infoBreakWaveformIndex,
                 const std::string infoDefinitionString, const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // BREAKWAVEFORMDEFINITIONSTRING_H