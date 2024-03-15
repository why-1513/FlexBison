#ifndef EQUATIONSPECIFICATIONTRANSFER_H
#define EQUATIONSPECIFICATIONTRANSFER_H

#include <vector>
#include <string>
#include <memory>
#include "LoggerManager.h"

#include "EqnSet.h"
#include "LEVELSET.h"
#include "WaveTBL.h"
#include "TimingSet.h"

class EquationSpecificationTransfer {
public:
    std::string specType;
    std::string eqspart;

    std::vector<std::shared_ptr<EqnSet>> eqnSets;
    std::vector<std::shared_ptr<LevelSet>> levelSets;
    std::vector<std::shared_ptr<WaveTBL>> waveTbls;
    std::vector<std::shared_ptr<TimingSet>> timingSets;

    void setNumber(const std::string infoType, const std::string infoPart);

    void addEqnSet(const std::shared_ptr<EqnSet> eqnSet);
    void addLevelSet(const std::shared_ptr<LevelSet> levelSet);
    void addWaveTbl(const std::shared_ptr<WaveTBL> waveTbl);
    void addTimingSet(const std::shared_ptr<TimingSet> timingSet);

    void printNumber() const;

    void printEqnSets() const;
    void printLevelSets() const;
    void printWaveTbls() const;
    void printTimingSets() const;
  
};

#endif // EQUATIONSPECIFICATIONTRANSFER_H
