#include "ParallelSiteEnable.h"

void ParallelSiteEnable::setSites(const std::string infoSites) {
    sites = infoSites;
}

void ParallelSiteEnable::printData() const {
    auto configLogger = LoggerManager::getConfigLogger();
    configLogger->info("PSTE Data: Sites: {}", sites);
}