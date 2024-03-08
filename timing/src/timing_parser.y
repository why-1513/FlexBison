%{
#include <string>
#include "timing_parser.hpp"
#include "TimingAST.h"

extern int yylex();
void yyerror(const char* s)
{
	auto timingLogger = LoggerManager::getLevelLogger();
	timingLogger->error("Error: {}", s);
}
std::shared_ptr<LevelFile> timingfile = std::make_shared<TimingFile>();

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
%token <token> TCOMMA TLPAREN TRPAREN TMINUS TLBRACKET TRBRACKET TMUL TEQUAL THASH TAT

%type <string> dps_No dps_set_id

%start timing_file
%defines

%%
timing_file: timing_commands NOOP TLITERAL TCOMMA TCOMMA TCOMMA;

timing_commands: timing_commands timing_command
			   | timing_command;

timing_command: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{
	timingfile->setFileType(*$3);
}
	| PCLK
	;