%{
#include <iostream>
#include <string>
#include <memory>
#include "config_parser.hpp"
#include "ConfigAST.h"

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
%token <string> TNEGINTEGER TNEGDOUBLE TIDENTIFIER TDOUBLE TINTEGER TLITERAL
%token <token> TCOMMA TLPAREN TRPAREN TMINUS

%type <string> channel_no pinNo dps_channel polarity sites pin_type pin_oper_mode conf_context pin_group
%type <string> pslc_value DCS_value min_voltage max_voltage max_source_current max_sink_current
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
	| DFGP pin_type TCOMMA TLPAREN pin_names TRPAREN TCOMMA TLPAREN pin_group TRPAREN{
		configfile->dfgp->addDFGPData(*$2,*pinlist,*$9);
	}
	| PSLC pslc_parameters
	| PSSL min_voltage TCOMMA max_voltage TCOMMA max_source_current TCOMMA max_sink_current TCOMMA TLPAREN pin_names TRPAREN{
		configfile->pssl->addPSSLData(*$2,*$4,*$6,*$8,*pinlist);
	}
	;

conf_parameters: pin_type TCOMMA pin_oper_mode TCOMMA TLPAREN pin_names TRPAREN{
	configfile->conf->addCONFData("default",*$1,*$3,*pinlist);
	}
	| conf_context TCOMMA pin_type TCOMMA pin_oper_mode TCOMMA TLPAREN pin_names TRPAREN{
		configfile->conf->addCONFData(*$1,*$3,*$5,*pinlist);
		};

pslc_parameters: pslc_value TCOMMA DCS_value TCOMMA TLPAREN pin_names TRPAREN{
	configfile->pslc->addPSLCData(*$1,*$3,*pinlist);
	}
	| TCOMMA DCS_value TCOMMA TLPAREN pin_names TRPAREN{
		configfile->pslc->addPSLCData("unused",*$2,*pinlist);
		}
	| TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		configfile->pslc->addPSLCData("unused","unused",*pinlist);
		};

channel_no: TINTEGER;
pinNo: TLITERAL;
dps_channel: TINTEGER;
polarity: TIDENTIFIER;
sites: TINTEGER;
conf_context: TLITERAL
pin_type: TIDENTIFIER;
pin_oper_mode: TIDENTIFIER;
pin_group:TIDENTIFIER;
pslc_value: TDOUBLE
	| TIDENTIFIER
	| TINTEGER
	;
DCS_value: TDOUBLE
	| TIDENTIFIER
	| TINTEGER
	;
min_voltage: TNEGDOUBLE
	| TNEGINTEGER
	| TIDENTIFIER
	;
max_voltage: TDOUBLE
	| TINTEGER
	| TIDENTIFIER
	;
max_source_current: TDOUBLE
	| TINTEGER
	| TIDENTIFIER
	;
max_sink_current: TDOUBLE
	| TINTEGER
	| TIDENTIFIER
	;

pin_names: pin_names TCOMMA pin_name {
	pinlist->push_back(*$3);
}
	| pin_name {
		pinlist = new std::vector<std::string>();
		pinlist->push_back(*$1);
	};
pin_name: TIDENTIFIER;

%%
