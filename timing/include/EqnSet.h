#ifndef EQNSET_H
#define EQNSET_H

#include <vector>
#include <string>
#include <memory>
#include "LoggerManager.h"

#include "SpecSet.h"

class EqnSet {
public:
    std::string equationSetNumber;
    std::string equationSetDescription;

    std::vector<std::string> specNames;
    std::vector<std::string> specUnits;

    std::vector<std::string> dpsPinNames;
    std::vector<std::string> dpsPinValues;

    std::vector<std::string> equationVariable;
    std::vector<std::string> expression;

    std::vector<std::shared_ptr<SpecSet>> specSets;

    void setNumber(const std::string infoNumber, const std::string infoDescription);

    void addSpecsData(const std::string infoSpceName, const std::string infoSpecUnit);
    void addDpsPinsData(const std::string infoDpsPinName, const std::string infoDpsPinValue);
    void addExpression(const std::string infoEquationVariable, const std::string infoExpression);

    void addSpecSet(const std::shared_ptr<SpecSet> specSet);

    void printSetNumber() const;
    void printSetData() const;
    void printSpecSets() const;
    void printExpression() const;
  
};

#endif // EQNSET_H