%{
#include <string>
#include "pattern_parser.hpp"
#include "PatternAST.h"

extern int yylex();
void yyerror(const char* s)
{
	auto patternLogger = LoggerManager::getPatternLogger();
	patternLogger->error("Error: {}", s);
}
std::shared_ptr<PatternFile> patternfile = std::make_shared<PatternFile>();
std::vector<std::string> pinlist;

%}

%union
{

	class PatternFile;
	std::string* string;
	int token;
	
}

%token <string> NOOP hp93000
%token <string> TDOUBLE TINTEGER TNEGDOUBLE TNEGINTEGER TIDENTIFIER TLITERAL EXPRESSION
%token <token> TQUOTATION TCOMMA TLPAREN TRPAREN TCOLON TLBRACKET TRBRACKET TEQUAL THASH TAT

%type <string> pin_name

%start pattern_file
%defines

%%
pattern_file: pattern_commands NOOP TLITERAL TCOMMA TCOMMA TCOMMA;

pattern_commands: pattern_commands pattern_command
			   | pattern_command;

pattern_command: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{
	patternfile->setFileType(*$3);
}
	;
%%