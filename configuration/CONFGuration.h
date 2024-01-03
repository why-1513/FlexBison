#ifndef CONFGURATION_H
#define CONFGURATION_H

#include <vector>
#include <string>

class CONFGuration {
public:
    std::vector<std::string> context;
    std::vector<std::string> pinType;
    std::vector<std::string> pinOperMode;
    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string& infoContext, const std::string& infoPinType,
                 const std::string& infoPinOperMode, const std::vector<std::string>& infoPinList);

    void printPinList() const;

    void printData() const;
};

#endif // CONFGURATION_H