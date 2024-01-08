#include "ParallelSiteEnable.h"

void ParallelSiteEnable::setSites(const std::string infoSites) {
    sites = infoSites;
}

void ParallelSiteEnable::printData() const {
    auto logger = LoggerManager::getLogger();
    logger->info("PSTE Data: Sites: {}", sites);
}