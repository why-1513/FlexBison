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
  std::cout << configfile->DFPN_channel_no[0];
  std::cout << configfile->DFPN_pinNo[0];
  std::cout << configfile->DFPN_pin[0]<< std::endl;
  std::cout << configfile->DFPN_channel_no[1];
  std::cout << configfile->DFPN_pinNo[1];
  std::cout << configfile->DFPN_pin[1]<< std::endl;
  return 0;
}