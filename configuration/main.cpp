#include <iostream>
#include <fstream>
#include <memory>
#include "ASTNodes.h"

extern int yyparse();
extern void yyparse_init(const char* filename);
extern void yyparse_cleanup();

int main(int argc, char **argv) {
  
  const char* config_name;
  
  std::cout << "Please enter the config name: ";
  std::string userInput;
  std::cin >> userInput;

  config_name = userInput.c_str();
  yyparse_init(config_name);
  // yyparse_init(*(argv+1));
  yyparse();
  yyparse_cleanup();

  std::cout << configfile->filetype << std::endl;
  std::cout << configfile->dfpn->channel_no[0];
  std::cout << configfile->dfpn->pinNo[0];
  std::cout << configfile->dfpn->pin[0]<< std::endl;
  std::cout << configfile->dfpn->channel_no[1];
  std::cout << configfile->dfpn->pinNo[1];
  std::cout << configfile->dfpn->pin[1]<< std::endl;
  std::cout << configfile->dfps->dps_channel[0];
  std::cout << configfile->dfps->polarity[0];
  std::cout << configfile->dfps->pin[0]<< std::endl;
  std::cout << configfile->pste->sites <<std::endl;
  std::cout << configfile->conf->context[0];
  std::cout << configfile->conf->pin_type[0];
  std::cout << configfile->conf->pin_oper_mode[0]<< std::endl;
  std::cout << configfile->conf->context[1];
  std::cout << configfile->conf->pin_type[1];
  std::cout << configfile->conf->pin_oper_mode[1]<< std::endl;
  configfile->conf->printPinList();
  std::cout << configfile->dfgp->pin_type[0];
  std::cout << configfile->dfgp->pin_group[0]<< std::endl;
  std::cout << configfile->dfgp->pin_type[1];
  std::cout << configfile->dfgp->pin_group[1]<< std::endl;
  configfile->dfgp->printPinList();
  
  return 0;
}