%{
#include <string>

#include "timing_parser.hpp"
#include "TimingAST.h"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) ( yylval.token = t)
#define ERRORLOG(t) timingLogger->error("Error: Unknown token: {}", t)

auto timingLogger = LoggerManager::getTimingLogger();

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

"PCLK"					puts("PCLK"); return TOKEN(PCLK);
"CLKR"					puts("CLKR"); return TOKEN(CLKR);
"BWDS"					puts("BWDS"); return TOKEN(BWDS);
"ETDS"					puts("ETDS"); return TOKEN(ETDS);
"DCDT"					puts("DCDT"); return TOKEN(DCDT);
"TSUX"					puts("TSUX"); return TOKEN(TSUX);
"WAVETBL"				puts("WAVETBL"); return TOKEN(WAVETBL);
"STATEMAP"				puts("STATEMAP"); return TOKEN(STATEMAP);
"EQSP"					puts("EQSP"); return TOKEN(EQSP);
"EQNSET"				puts("EQNSET"); return TOKEN(EQNSET);
"SPECS"					puts("SPECS"): return TOKEN(SPECS);
"TIMINGSET"				puts("TIMINGSET"): return TOKEN(TIMINGSET);
"PINS IN"				puts("PINS IN"); return TOKEN(PINSIN);
"PINS OUT"				puts("PINS OUT"); return TOKEN(PINSOUT);
"EQUATIONS"				puts("EQUATIONS"); return TOKEN(EQUATIONS);
"CHECK all"				puts("CHECK all"); return TOKEN(CHECKALL);
"SPECSET"				puts("SPECSET"); return TOKEN(SPECSET);
"# SPECNAME"			puts("SPECNAME"); return TOKEN(SPECNAME);
"*****ACTUAL*****"		puts("TACTUAL"); return TOKEN(TACTUAL);
"*****MINIMUM****"		puts("TMINIMUM"); return TOKEN(TMINIMUM);
"*****MAXIMUM****"		puts("TMAXIMUM"); return TOKEN(TMAXIMUM);
"UNITS COMMENT"			puts("UNITSCOMMENT"); return TOKEN(UNITSCOMMENT);
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
.						ERRORLOG(yytext); yyterminate();

%%
