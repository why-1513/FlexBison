#include <iostream>
#include <fstream>

extern int yyparse();
extern void yyparse_init(const char* filename);
extern void yyparse_cleanup();

int main(int argc, char **argv) {
  
  yyparse_init("PIN");
  yyparse();
  yyparse_cleanup;
  return 0;
}