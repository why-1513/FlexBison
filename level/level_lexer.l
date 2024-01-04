%{
#include <string>

#include "level_parser.hpp"
#include "LevelAST.h"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) ( yylval.token = t)

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
"PSLV"					puts("PSLV"); return TOKEN(PSLV);
"DRLV"					puts("DRLV"); return TOKEN(DRLV);
"RCLV"					puts("RCLV"); return TOKEN(RCLV);
"TERM"					puts("TERM"); return TOKEN(TERM);
"CLMP"					puts("CLMP"); return TOKEN(CLMP);
"LSUX"					puts("LSUX"); return TOKEN(LSUX);
"EQSP"					puts("EQSP"); return TOKEN(EQSP);
"EQNSET"				puts("EQNSET"); return TOKEN(EQNSET);
"SPECS"					puts("SPECS"); return TOKEN(SPECS);
"DPSPINS"				puts("DPSPINS"); return TOKEN(DPSPINS);
"LEVELSET"				puts("LEVELSET"); return TOKEN(LEVELSET);
"PINS IN"				puts("PINS IN"); return TOKEN(PINSIN);
"PINS OUT"				puts("PINS OUT"); return TOKEN(PINSOUT);
"SPECSET"				puts("SPECSET"); return TOKEN(SPECSET);
"# SPECNAME"			puts("# SPECNAME"); return TOKEN(SPECNAME);
"*****ACTUAL*****"		puts("*****ACTUAL*****"); return TOKEN(TACTUAL);
"*****MINIMUM****"		puts("*****MINIMUM****"); return TOKEN(TMINIMUM);
"*****MAXIMUM****"		puts("*****MAXIMUM****"); return TOKEN(TMAXIMUM);
"UNITS COMMENT"			puts("UNITS COMMENT"); return TOKEN(UNITSCOMMENT);
"NOOP"					puts("NOOP"); return TOKEN(NOOP);
"hp93000"				puts("hp93000"); return TOKEN(hp93000);
[0-9]+\.[0-9]*			SAVE_TOKEN; puts(yytext); return TDOUBLE;
[0-9]+  				SAVE_TOKEN; puts(yytext); return TINTEGER;
-?[0-9]+\.[0-9]*		SAVE_TOKEN; puts(yytext); return TNEGDOUBLE;
-?[0-9]+				SAVE_TOKEN; puts(yytext); return TNEGINTEGER;
[a-zA-Z][a-zA-Z0-9_]*	SAVE_TOKEN; puts(yytext); return TIDENTIFIER;
\"(.*?)\"				SAVE_TOKEN; puts(yytext); return TLITERAL;
"-"						puts("TMINUS"); return TOKEN(TMINUS);
","						puts("TCOMMA"); return TOKEN(TCOMMA);
"("						puts("TLPAREN"); return TOKEN(TLPAREN);
")"						puts("TRPAREN"); return TOKEN(TRPAREN);
"["						puts("TLBRACKET"); return TOKEN(TLBRACKET);
"]"						puts("TRBRACKET"); return TOKEN(TRBRACKET);
"*"						puts("TMUL"); return TOKEN(TMUL);
"="						puts("TEQUAL"); return TOKEN(TEQUAL);
"#"						puts("THASH"); return TOKEN(THASH);
"@"						puts("TAT"); return TOKEN(TAT);
.						printf("Unknown token:%s\n", yytext); yyterminate();

%%
