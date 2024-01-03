#include <iostream>
#include <fstream>
#include <memory>
#include "ConfigAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {
  
  const char* configName;
  
  std::cout << "Please enter the config file name: ";
  std::string userInput;
  std::cin >> userInput;

  configName = userInput.c_str();
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
  
  return 0;
}