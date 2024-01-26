#include <fstream>
#include "LevelAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {
  
  const char* levelName;
  
  auto levelLogger = LoggerManager::getLevelLogger();

  std::string userInput;
  levelLogger->info("Please enter the level file name: ");
  std::cin >> userInput;

  levelName = userInput.c_str();
  levelLogger->info("Get a file: {}", levelName);
  yyparseInit(levelName);
  yyparse();
  yyparseCleanup();
  
  levelfile->term->printData();
  levelfile->term->printPinList();
  
  return 0;
}