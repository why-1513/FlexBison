#include <iostream>
#include <fstream>

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
  yyparse();
  yyparse_cleanup();
  return 0;
}