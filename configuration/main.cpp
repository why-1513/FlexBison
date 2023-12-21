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
  std::cout<< "No filetype found 1." <<std::endl;
  yyparse_init(config_name);
  // yyparse_init(*(argv+1));
  std::cout<< "No filetype found 2." <<std::endl;
  yyparse();
  std::cout<< "No filetype found 3" <<std::endl;
  yyparse_cleanup();

  // if (configheader != nullptr && ! configheader->filetype.empty()) {
  //       std::cout << configheader->filetype[0] << std::endl;
  //   } else {
  //       std::cout << "No filetype found." << std::endl;
  //   }
  // std::cout<< "No filetype found 4" <<std::endl;
  return 0;
}