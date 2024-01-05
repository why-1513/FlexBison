#include "ConfigAST.h"

ConfigFile::ConfigFile() : dfpn(std::make_shared<DefinePinName>()),
                           dfps(std::make_shared<DefinePowerSupply>()),
                           pste(std::make_shared<ParallelSiteEnable>()),
                           conf(std::make_shared<CONFGuration>()),
                           dfgp(std::make_shared<DefineGroup>()),
                           pslc(std::make_shared<PowerSupplyLoadCapacitance>()),
                           pssl(std::make_shared<PowerSupplySafetyLimits>()) {}

void ConfigFile::setFileType(const std::string type) {
    auto logger = LoggerManager::getLogger();
    if (type == "config") {
        filetype = type;
        logger->info("Get a config file.");
    } else {
        logger->error("Error: File type does not match.");
        exit(1);
    }
}