#include "ParallelSiteEnable.h"
#include <iostream>

void ParallelSiteEnable::setSites(const std::string& infoSites) {
    sites = infoSites;
}

void ParallelSiteEnable::printData() const {
    std::cout << "PSTE Data:" << std::endl;
    std::cout << "Sites: " << sites << std::endl;
}