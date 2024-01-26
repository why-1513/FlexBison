#include <fstream>
#include "ConfigAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {

  const char* configName;

  auto configLogger = LoggerManager::getConfigLogger();

  std::string userInput;
  configLogger->info("Please enter the config file name: ");
  std::cin >> userInput;

  configName = userInput.c_str();
  configLogger->info("Get a file: {}", configName);
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