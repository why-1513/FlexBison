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
std::shared_ptr<ConfigFile> configfile = std::make_shared<ConfigFile>();

%}
%union
{

	class ConfigFile;
	std::string* string;
	int token;
	
}

%token <string> DFPN DFPS PSTE CONF DFGP PSLC PSSL NOOP hp93000
%token <string> TIDENTIFIER TDOUBLE TINTEGER TLITERAL
%token <token> TCOMMA TLPAREN TRPAREN TMINUS

%type <string> channel_no pinNo pin_name

%start config_file
%defines

%%
config_file: config_commands NOOP TLITERAL TCOMMA TCOMMA TCOMMA;

config_commands: config_commands config_command
			   | config_command
			   ;

config_command: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{
	configfile->setFileType(*$3);
	}
	| DFPN channel_no TCOMMA pinNo TCOMMA TLPAREN pin_name TRPAREN{
		configfile->dfpn->addDFPNData(*$2,*$4,*$7);
	}
	;

channel_no: TINTEGER;
pinNo: TLITERAL;
pin_name: TIDENTIFIER;

%%
