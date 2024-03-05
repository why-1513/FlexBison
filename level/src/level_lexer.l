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
"EQSP"					puts("eqsp"); return TOKEN(EQSP);
"EQNSET"				puts("eqnset"); return TOKEN(EQNSET);
"SPECS"					return TOKEN(SPECS);
"DPSPINS"				return TOKEN(DPSPINS);
"LEVELSET"				return TOKEN(LEVELSET);
"PINS IN"				return TOKEN(PINSIN);
"PINS OUT"				return TOKEN(PINSOUT);
"SPECSET"				puts("specset");return TOKEN(SPECSET);
"# SPECNAME"			puts("specname");return TOKEN(SPECNAME);
"*****ACTUAL*****"		puts("actual");return TOKEN(TACTUAL);
"*****MINIMUM****"		puts("minimum");return TOKEN(TMINIMUM);
"*****MAXIMUM****"		puts("maximum");return TOKEN(TMAXIMUM);
"UNITS COMMENT"			puts("units");return TOKEN(UNITSCOMMENT);
"NOOP"					return TOKEN(NOOP);
"hp93000"				return TOKEN(hp93000);
[0-9]+\.[0-9]*			SAVE_TOKEN; puts(yytext);return TDOUBLE;
[0-9]+  				SAVE_TOKEN; puts(yytext);return TINTEGER;
-?[0-9]+\.[0-9]*		SAVE_TOKEN; puts(yytext);return TNEGDOUBLE;
-?[0-9]+				SAVE_TOKEN; puts(yytext);return TNEGINTEGER;
[a-zA-Z][a-zA-Z0-9_]*	SAVE_TOKEN; puts(yytext);return TIDENTIFIER;
\"(.*?)\"				SAVE_TOKEN; puts(yytext);return TLITERAL;
"-"						return TOKEN(TMINUS);
","						return TOKEN(TCOMMA);
"("						return TOKEN(TLPAREN);
")"						return TOKEN(TRPAREN);
"["						puts("[");return TOKEN(TLBRACKET);
"]"						puts("]");return TOKEN(TRBRACKET);
"*"						return TOKEN(TMUL);
"="						return TOKEN(TEQUAL);
"#"						return TOKEN(THASH);
"@"						return TOKEN(TAT);
.						ERRORLOG(yytext); yyterminate();

%%
