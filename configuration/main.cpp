#include <iostream>
#include <fstream>
#include <memory>
#include "ConfigAST.h"

extern int yyparse();
extern void yyparse_init(const char* filename);
extern void yyparse_cleanup();

int main(int argc, char **argv) {
  
  const char* configName;
  
  std::cout << "Please enter the config file name: ";
  std::string userInput;
  std::cin >> userInput;

  configName = userInput.c_str();
  yyparse_init(configName);
  yyparse();
  yyparse_cleanup();

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