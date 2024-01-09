#include "ParallelSiteEnable.h"

void ParallelSiteEnable::setSites(const std::string infoSites) {
    sites = infoSites;
}

void ParallelSiteEnable::printData() const {
    auto copnfigLogger = LoggerManager::getConfigLogger();
    copnfigLogger->info("PSTE Data: Sites: {}", sites);
}