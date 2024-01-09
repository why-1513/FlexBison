#include <fstream>
#include "ConfigAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {

  const char* configName;

  auto copnfigLogger = LoggerManager::getConfigLogger();

  std::string userInput;
  copnfigLogger->info("Please enter the config file name: ");
  std::cin >> userInput;

  configName = userInput.c_str();
  copnfigLogger->info("Get a file: {}", configName);
  yyparseInit(configName);
  yyparse();
  yyparseCleanup();

  configfile->dfpn->printData();
  configfile->dfps->printData();
  configfile->pste->printData();
  configfile->conf->printData();
  configfile->conf->printPinList();
  configfile->dfgp->printData();
  configfile->dfgp->printPinList();
  configfile->pslc->printData();
  configfile->pslc->printPinList();
  configfile->pssl->printData();
  configfile->pssl->printPinList();

  spdlog::drop_all();

  return 0;
}