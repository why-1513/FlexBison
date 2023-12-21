%{
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cstring>
#include "config_parser.hpp"
#include "ASTNodes.h"

extern int yylex();
void yyerror(const char* s)
{
	printf("Error: %s\n", s);
}
std::shared_ptr<FileHeader> configheader = std::make_shared<FileHeader>();

%}
%union
{
	class FileHeader* fileheader;
	std::string* string;
	int token;
	
}

%token <string> DFPN DFPS PSTE CONF DFGP PSLC PSSL NOOP hp93000
%token <string> TIDENTIFIER TDOUBLE TINTEGER TLITERAL
%token <token> TCOMMA TLPAREN TRPAREN TMINUS

%type <fileheader> configuration
%type <string> config

%start configuration
%defines

%%
configuration: hp93000 TCOMMA config TCOMMA TDOUBLE{
    std::cout << "hello" << std::endl;
	std::cout << $3 << std::endl;
	std::cout << "hihi" << std::endl;
	std::string aaaa;
	std::cout << "xxxxxxx" << std::endl;
	aaaa = *$3;
	std::cout << "hohohoho" << std::endl;
	std::cout << aaaa << std::endl;
	std::cout << "aaaaaaaaaaaaa" << std::endl;
};
config:TIDENTIFIER{
	$$ = $1;
};
%%
