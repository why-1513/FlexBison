%{
#include <string>
#include "timing_parser.hpp"
#include "TimingAST.h"

extern int yylex();
void yyerror(const char* s)
{
	auto timingLogger = LoggerManager::getTimingLogger();
	timingLogger->error("Error: {}", s);
}
std::shared_ptr<TimingFile> timingfile = std::make_shared<TimingFile>();
std::vector<std::string> pinlist;

%}

%union
{

	class TimingFile;
	std::string* string;
	int token;
	
}

%token <string> PCLK CLKR BWDS ETDS DCDT TSUX EQSP EQNSET SPECS NOOP hp93000
%token <string> WAVETBL PINSIN PINSOUT STATEMAP TIMINGSET EQUATIONS CHECKALL SPECSET
%token <string> SPECNAME TACTUAL TMINIMUM TMAXIMUM UNITSCOMMENT
%token <string> TDOUBLE TINTEGER TNEGDOUBLE TNEGINTEGER TIDENTIFIER TLITERAL
%token <token> TCOMMA TLPAREN TRPAREN TMINUS TPLUS TDIV TCLT TCGT TQUESTION TCOLON TLBRACKET TRBRACKET TMUL TEQUAL THASH TAT

%type <string> waveform_set timing_set period period_res ref_period wvf_set break_waveform_index definition_string
%type <string> default_name
%type <string> pin_name

%start timing_file
%defines

%%
timing_file: timing_commands NOOP TLITERAL TCOMMA TCOMMA TCOMMA;

timing_commands: timing_commands timing_command
			   | timing_command;

timing_command: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{
	timingfile->setFileType(*$3);
}
	| PCLK pclk_parameters
	| CLKR waveform_set TCOMMA ref_period TCOMMA period_res{
		timingfile->clkr->addData(*$2,*$6);
	}
	| BWDS bwds_parameters
	| ETDS etds_parameters
	| DCDT waveform_set TCOMMA default_name{
		timingfile->dcdt->addData(*$2,*$4);
	}
	| TSUX waveform_set TCOMMA timing_set{
		timingfile->tsux->addData(*$2,*$4);
	}
	;

pclk_parameters: waveform_set TCOMMA timing_set TCOMMA period TCOMMA TLPAREN pin_names TRPAREN{
	timingfile->pclk->addFixData(*$1,*$3,*$5,pinlist);
}
	| waveform_set TCOMMA timing_set TCOMMA period TCOMMA TLPAREN TAT TRPAREN{
		pinlist = std::vector<std::string>();
		pinlist.push_back("@");
		timingfile->pclk->addFixData(*$1,*$3,*$5,pinlist);
	}
	;

etds_parameters: waveform_set TCOMMA timing_set TCOMMA TCOMMA definition_string TCOMMA TLPAREN pin_names TRPAREN{
	timingfile->etds->addData(*$1,*$3,*$6,pinlist);
}

waveform_set: TINTEGER;
timing_set: TIDENTIFIER
	| TINTEGER
	;
period: TINTEGER
	| TDOUBLE
	;

ref_period: TINTEGER
	| TDOUBLE
	;
period_res: TINTEGER
	| TDOUBLE
	;

bwds_parameters: wvf_set TCOMMA TCOMMA TCOMMA definition_string TCOMMA TLPAREN pin_names TRPAREN{
		timingfile->bwds->addData(*$1,"unused",*$5,pinlist);
	}
	| wvf_set TCOMMA break_waveform_index TCOMMA TCOMMA definition_string TCOMMA TLPAREN pin_names TRPAREN{
		timingfile->bwds->addData(*$1,*$3,*$6,pinlist);
	}
	;
wvf_set: TIDENTIFIER
	| TINTEGER
	;
break_waveform_index: TIDENTIFIER
	| TINTEGER
	;
definition_string: TLITERAL;

default_name: TLITERAL;

pin_names: pin_names TCOMMA pin_name {
	pinlist.push_back(*$3);
}
	| pin_name {
		pinlist = std::vector<std::string>();
		pinlist.push_back(*$1);
	};

pin_name: TIDENTIFIER;

expression: condition TQUESTION  expression TCOLON expression
	| term pmterms
	| term
	;
condition: TLPAREN condition TRPAREN 
	| expression TCGT expression
	| expression TCLT expression
	| expression
	;
term: factor mdfactors
	| factor
	;
pmterms: pmterm pmterm
	| pmterm
	;
mdfactors: TMUL factor
	| TDIV factor
	;
factor: TLPAREN expression TRPAREN
	| TMINUS TLPAREN expression TRPAREN
	| TINTEGER
	| TDOUBLE
	| TPLUS TINTEGER
	| TPLUS TDOUBLE
	| TMINUS TINTEGER
	| TMINUS TDOUBLE
	| TPLUS TIDENTIFIER
	| TMINUS TIDENTIFIER
	;
pmterm: TPLUS term
	| TMINUS term
	;

%%