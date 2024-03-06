%{
#include <string>

#include "level_parser.hpp"
#include "LevelAST.h"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) ( yylval.token = t)
#define ERRORLOG(t) levelLogger->error("Error: Unknown token: {}", t)

auto levelLogger = LoggerManager::getLevelLogger();

static FILE* yyparseFilePtr;

void yyparseInit(const char* filename)
{
    yyparseFilePtr = fopen(filename, "r");
	yyin = yyparseFilePtr;
}

void yyparseCleanup()
{
	fclose(yyparseFilePtr);
}

%}

%option noyywrap

%%
[ \t\r\n]				;
"PSLV"					return TOKEN(PSLV);
"DRLV"					return TOKEN(DRLV);
"RCLV"					return TOKEN(RCLV);
"TERM"					return TOKEN(TERM);
"CLMP"					return TOKEN(CLMP);
"LSUX"					return TOKEN(LSUX);
"EQSP"					return TOKEN(EQSP);
"EQNSET"				return TOKEN(EQNSET);
"SPECS"					return TOKEN(SPECS);
"DPSPINS"				return TOKEN(DPSPINS);
"LEVELSET"				return TOKEN(LEVELSET);
"PINS IN"				return TOKEN(PINSIN);
"PINS OUT"				return TOKEN(PINSOUT);
"SPECSET"				return TOKEN(SPECSET);
"# SPECNAME"			return TOKEN(SPECNAME);
"*****ACTUAL*****"		return TOKEN(TACTUAL);
"*****MINIMUM****"		return TOKEN(TMINIMUM);
"*****MAXIMUM****"		return TOKEN(TMAXIMUM);
"UNITS COMMENT"			return TOKEN(UNITSCOMMENT);
"NOOP"					return TOKEN(NOOP);
"hp93000"				return TOKEN(hp93000);
[0-9]+\.[0-9]*			SAVE_TOKEN; return TDOUBLE;
[0-9]+  				SAVE_TOKEN; return TINTEGER;
-?[0-9]+\.[0-9]*		SAVE_TOKEN; return TNEGDOUBLE;
-?[0-9]+				SAVE_TOKEN; return TNEGINTEGER;
[a-zA-Z][a-zA-Z0-9_]*	SAVE_TOKEN; return TIDENTIFIER;
\"(.*?)\"				SAVE_TOKEN; return TLITERAL;
"-"						return TOKEN(TMINUS);
","						return TOKEN(TCOMMA);
"("						return TOKEN(TLPAREN);
")"						return TOKEN(TRPAREN);
"["						return TOKEN(TLBRACKET);
"]"						return TOKEN(TRBRACKET);
"*"						return TOKEN(TMUL);
"="						return TOKEN(TEQUAL);
"#"						return TOKEN(THASH);
"@"						return TOKEN(TAT);
.						ERRORLOG(yytext); yyterminate();

%%
