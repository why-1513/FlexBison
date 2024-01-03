#ifndef DEFINEGROUP_H
#define DEFINEGROUP_H

#include <vector>
#include <string>

class DefineGroup {
public:
    std::vector<std::string> pinType;
    std::vector<std::string> pinGroup;
    std::vector<std::vector<std::string>> pinlist;

    void addData(const std::string& infoPinType,
                 const std::vector<std::string>& infoPinList, const std::string& infoPinGroup);

    void printPinList() const;

    void printData() const;
};

#endif // DEFINEGROUP_H