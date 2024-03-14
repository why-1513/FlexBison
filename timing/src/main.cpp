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

  return 0;
}