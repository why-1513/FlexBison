#ifndef PARALLELSITEENABLE_H
#define PARALLELSITEENABLE_H

#include <string>

class ParallelSiteEnable {
public:
    std::string sites;

    void setSites(const std::string& infoSites);

    void printData() const;
};

#endif // PARALLELSITEENABLE_H