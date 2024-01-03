#ifndef ConfigAST_H
#define ConfigAST_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "DefinePinName.h"
#include "DefinePowerSupply.h"
#include "ParallelSiteEnable.h"
#include "CONFGuration.h"
#include "DefineGroup.h"
#include "PowerSupplyLoadCapacitance.h"
#include "PowerSupplySafetyLimits.h"


class ConfigFile {
public:
    ConfigFile();
    
    std::string filetype;

    void setFileType(const std::string& type);

    std::shared_ptr<DefinePinName> dfpn;
    std::shared_ptr<DefinePowerSupply> dfps;
    std::shared_ptr<ParallelSiteEnable> pste;
    std::shared_ptr<CONFGuration> conf;
    std::shared_ptr<DefineGroup> dfgp;
    std::shared_ptr<PowerSupplyLoadCapacitance> pslc;
    std::shared_ptr<PowerSupplySafetyLimits> pssl;

};

extern std::shared_ptr<ConfigFile> configfile;

#endif // ConfigAST_H