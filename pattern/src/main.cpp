#include <fstream>
#include "PatternAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {
  
  const char* patternName;
  
  auto patternLogger = LoggerManager::getPatternLogger();

  std::string userInput;
  patternLogger->info("Please enter the pattern file name: ");
  std::cin >> userInput;

  patternName = userInput.c_str();
  patternLogger->info("Get a file: {}", patternName);
  yyparseInit(patternName);
  yyparse();
  yyparseCleanup();

  return 0;
}