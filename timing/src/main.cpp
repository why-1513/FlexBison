#include <fstream>
#include "TimingAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {
  
  const char* timingName;
  
  auto timingLogger = LoggerManager::getTimingLogger();

  std::string userInput;
  timingLogger->info("Please enter the timing file name: ");
  std::cin >> userInput;

  timingName = userInput.c_str();
  timingLogger->info("Get a file: {}", timingName);
  yyparseInit(timingName);
  yyparse();
  yyparseCleanup();

  timingfile->pclk->printData();
  timingfile->pclk->printPinList();
  timingfile->clkr->printData();
  timingfile->bwds->printPinList();
  timingfile->bwds->printData();
  timingfile->etds->printPinList();
  timingfile->etds->printData();
  timingfile->dcdt->printData();
  timingfile->tsux->printData();
  for (const auto& eqsp : timingfile->eqsps) {
    // 访问 eqsp 指向的 EquationSpecificationTransfer 对象，并输出相关信息
    eqsp->printNumber();
    eqsp->printEqnSets();
    eqsp->printTimingSets();
    eqsp->printWaveTbls();
    eqsp->printTimingSets();

}
  return 0;
}