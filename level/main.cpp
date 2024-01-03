#include <iostream>
#include <fstream>
#include <memory>
#include "LevelAST.h"

extern int yyparse();
extern void yyparse_init(const char* filename);
extern void yyparse_cleanup();

int main(int argc, char **argv) {
  
  const char* level_name;
  
  std::cout << "Please enter the level file name: ";
  std::string userInput;
  std::cin >> userInput;

  level_name = userInput.c_str();
  yyparse_init(level_name);
  // yyparse_init(*(argv+1));
  yyparse();
  yyparse_cleanup();
  
  return 0;
}