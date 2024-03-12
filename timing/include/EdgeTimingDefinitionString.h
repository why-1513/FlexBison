#ifndef EDGETIMINGDEFINITIONSTRING_H
#define EDGETIMINGDEFINITIONSTRING_H

#include <vector>
#include <string>
#include "LoggerManager.h"

class EdgeTimingDefinitionString {
public:
    std::vector<std::string> waveformSet;

    std::vector<std::string> specSetId;
    std::vector<std::string> multiportSpec;

    std::vector<std::string> timingSet;
    std::vector<std::string> etdsMode;
    std::vector<std::string> definitionString;

    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string infoWaveformSet, const std::string infoTimingSet,
                 const std::string infoDefinitionString, const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // EDGETIMINGDEFINITIONSTRING_H