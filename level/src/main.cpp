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
  
  for (const auto& eqsp : levelfile->eqsps) {
    // 访问 eqsp 指向的 EquationSpecificationTransfer 对象，并输出相关信息
    eqsp->printNumber();
    eqsp->printEqnSets();

}
  
  return 0;
}