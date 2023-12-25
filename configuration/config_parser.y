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
std::vector<std::string>* pinlist;

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

%type <string> channel_no pinNo dps_channel polarity sites pin_type pin_oper_mode conf_context
%type <string> pin_name 

%start config_file
%defines

%%
config_file: config_commands NOOP TLITERAL TCOMMA TCOMMA TCOMMA;

config_commands: config_commands config_command
			   | config_command;

config_command: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{
	configfile->setFileType(*$3);
	}
	| DFPN channel_no TCOMMA pinNo TCOMMA TLPAREN pin_name TRPAREN{
		configfile->dfpn->addDFPNData(*$2,*$4,*$7);
	}
	| DFPS dps_channel TCOMMA polarity TCOMMA TLPAREN pin_name TRPAREN{
		configfile->dfps->addDFPSData(*$2,*$4,*$7);
	}
	| PSTE sites{
		configfile->pste->setSites(*$2);
	}
	| CONF conf_parameters
	;

conf_parameters: pin_type TCOMMA pin_oper_mode TCOMMA TLPAREN pin_names TRPAREN{
	configfile->conf->addCONFData("default",*$1,*$3,*pinlist);
}
	| conf_context TCOMMA pin_type TCOMMA pin_oper_mode TCOMMA TLPAREN pin_names TRPAREN{
		configfile->conf->addCONFData(*$1,*$3,*$5,*pinlist);
		};
channel_no: TINTEGER;
pinNo: TLITERAL;
dps_channel: TINTEGER;
polarity: TIDENTIFIER;
sites: TINTEGER;
conf_context: TLITERAL
pin_type: TIDENTIFIER;
pin_oper_mode: TIDENTIFIER;

pin_names: pin_names TCOMMA pin_name {
	pinlist->push_back(*$3);
}
	| pin_name {
		pinlist = new std::vector<std::string>();
		pinlist->push_back(*$1);
	};
pin_name: TIDENTIFIER;

%%
