#include <fstream>
#include "ConfigAST.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {
  
  const char* configName;
  
  // 创建文件记录器，将日志保存到文件中
  auto configLogger = spdlog::basic_logger_mt("ConfigLog", "Config.log");
  configLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%L] %v");

  std::string userInput;
  configLogger->info("Please enter the config file name: ");
  std::cin >> userInput;

  configName = userInput.c_str();
  yyparseInit(configName);
  yyparse();
  yyparseCleanup();

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