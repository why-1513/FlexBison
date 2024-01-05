#include <fstream>
#include "ConfigAST.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

extern int yyparse();
extern void yyparseInit(const char* filename);
extern void yyparseCleanup();

int main(int argc, char **argv) {
  
  const char* configName;
  
  // 创建文件记录器，将日志保存到文件中
  auto fileLogger = spdlog::basic_logger_mt("ConfigLog", "Config.log");
  fileLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%L] %v");

  // 创建控制台记录器，将日志同时输出到控制台
  auto consoleLogger = spdlog::stdout_color_mt("ConfigConsoleLog");
  consoleLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%L] %v");

  std::string userInput;
  consoleLogger->info("Please enter the config file name: ");
  fileLogger->info("Please enter the config file name: ");
  std::cin >> userInput;
  fileLogger->info("Get file input end.");

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

  spdlog::drop_all();
  
  return 0;
}