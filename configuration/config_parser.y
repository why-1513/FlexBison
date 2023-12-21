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

%start configuration
%defines

%%
configuration: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{
    std::string aaaa;
	aaaa = *$1;
	std::cout<<aaaa;
};

%%
