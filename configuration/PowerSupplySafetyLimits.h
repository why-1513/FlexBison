#ifndef POWERSUPPLYSAFETYLIMITS_H
#define POWERSUPPLYSAFETYLIMITS_H

#include <vector>
#include <string>

class PowerSupplySafetyLimits {
public:
    std::vector<std::string> minVoltage;
    std::vector<std::string> maxVoltage;
    std::vector<std::string> maxSourceCurrent;
    std::vector<std::string> maxSinkCurrent;
    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string infoMinVol, const std::string infoMaxVol,
                 const std::string infoMaxSourceCurrent, const std::string infoMaxSinkCurrent,
                 const std::vector<std::string> infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // POWERSUPPLYSAFETYLIMITS_H