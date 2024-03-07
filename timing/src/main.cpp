#include <fstream>
#include "TimingAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {
  
  const char* timingName;
  
  auto timingLogger = LoggerManager::getTimingLogger();

  std::string userInput;
  timingLogger->info("Please enter the timing file name: ");
  std::cin >> userInput;

  timingName = userInput.c_str();
  timingLogger->info("Get a file: {}", timingName);
  yyparseInit(timingName);
  yyparse();
  yyparseCleanup();
  
  return 0;
}