#include <fstream>
#include "LevelAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {
  
  const char* levelName;
  
  std::cout << "Please enter the level file name: ";
  std::string userInput;
  std::cin >> userInput;

  levelName = userInput.c_str();
  yyparseInit(levelName);
  yyparse();
  yyparseCleanup();
  
  return 0;
}