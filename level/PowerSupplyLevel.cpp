#include "PowerSupplyLevel.h"

void PowerSupplyLevel::addData(const std::string infoDpsNo, const std::string infoDpsSetId,
                 const std::string infoVoltage, const std::string infoSourceCurrent,
                 const std::string infoSinkCurrent, const std::string infoImpedance,
                 const std::string infoSetupTime, const std::vector<std::string> infoPinList) {
    dpsNo.push_back(infoDpsNo);
    dpsSetId.push_back(infoDpsSetId);
    voltage.push_back(infoVoltage);
    sourceCurrent.push_back(infoSourceCurrent);
    sinkCurrent.push_back(infoSinkCurrent);
    impedance.push_back(infoImpedance);
    setupTime.push_back(infoSetupTime);
    pinlist.push_back(infoPinList);
}

void PowerSupplyLevel::printPinList() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("PSLV Pinlist:");

    if(!pinlist.empty()){
        for (const auto pinGroup : pinlist) {
            std::string vectorContents;
            for (const auto pin : pinGroup) {
                vectorContents += pin + " ";
            }
            levelLogger->info(vectorContents);
            vectorContents.clear();
        }
    }
}

void PowerSupplyLevel::printData() const {
    auto levelLogger = LoggerManager::getLevelLogger();
    levelLogger->info("PSLV Data:");

    std::string vectorDpsNo;
    std::string vectorDpsSetId;
    std::string vectorVoltage;
    std::string vectorSourceCurrent;
    std::string vectorSinkCurrent;
    std::string vectorImpedance;
    std::string vectorSetupTime;

    if(!dpsNo.empty()){
        for (const auto dpsno : dpsNo) {
            vectorDpsNo += dpsno + " ";
        }
        levelLogger->info("DpsNo: {}", vectorDpsNo);
        vectorDpsNo.clear();
    }

    if(!dpsSetId.empty()){
        for (const auto id : dpsSetId) {
            vectorDpsSetId += id + " ";
        }
        levelLogger->info("DpsSetId: {}", vectorDpsSetId);
        vectorDpsSetId.clear();
    }

    if(!voltage.empty()){
        for (const auto vol : voltage) {
            vectorVoltage += vol + " ";
        }
        levelLogger->info("Voltage: {}", vectorVoltage);
        vectorVoltage.clear();
    }

    if(!sourceCurrent.empty()){
        for (const auto current : sourceCurrent){
            vectorSourceCurrent += current + " ";
        }
        levelLogger->info("SourceCurrent: {}", vectorSourceCurrent);
        vectorSourceCurrent.clear();
    }

    if(!sinkCurrent.empty()){
        for (const auto current : sinkCurrent){
            vectorSinkCurrent += current + " ";
        }
        levelLogger->info("SinkCurrent: {}", vectorSinkCurrent);
        vectorSinkCurrent.clear();
    }

    if(!impedance.empty()){
        for (const auto imp : impedance){
            vectorImpedance += imp + " ";
        }
        levelLogger->info("Impedance: {}", vectorImpedance);
        vectorImpedance.clear();
    }

    if(!setupTime.empty()){
        for (const auto setime : setupTime){
            vectorSetupTime += setime + " ";
        }
        levelLogger->info("SetupTime: {}", vectorSetupTime );
        vectorSetupTime .clear();
    }
}