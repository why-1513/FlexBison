%{
#include <string>

#include "pattern_parser.hpp"
#include "PatternAST.h"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) ( yylval.token = t)
#define ERRORLOG(t) patternLogger->error("Error: Unknown token: {}", t)

auto patternLogger = LoggerManager::getPatternLogger();

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

"NOOP"					puts("NOOP"); return TOKEN(NOOP);
"hp93000"				puts("hp93000"); return TOKEN(hp93000);
[0-9]+\.[0-9]*			SAVE_TOKEN; puts(yytext); return TDOUBLE;
[0-9]+  				SAVE_TOKEN; puts(yytext); return TINTEGER;
-?[0-9]+\.[0-9]*		SAVE_TOKEN; puts(yytext); return TNEGDOUBLE;
-?[0-9]+				SAVE_TOKEN; puts(yytext); return TNEGINTEGER;
[a-zA-Z][a-zA-Z0-9_]*	SAVE_TOKEN; puts(yytext); return TIDENTIFIER;
[a-zA-Z0-9_]*[\+\-\*\/]+[\+\-\*\/a-zA-Z0-9_]*	SAVE_TOKEN; puts(yytext); return EXPRESSION;
\"([^\": ]*)\"			SAVE_TOKEN; puts(yytext); return TLITERAL;
\"						puts("TQUOTATION"); return TOKEN(TQUOTATION);
","						puts("TCOMMA"); return TOKEN(TCOMMA);
"("						puts("TLPAREN"); return TOKEN(TLPAREN);
")"						puts("TRPAREN"); return TOKEN(TRPAREN);
"["						puts("TLBRACKET"); return TOKEN(TLBRACKET);
"]"						puts("TRBRACKET"); return TOKEN(TRBRACKET);
":"						puts("TCOLON"); return TOKEN(TCOLON);
"="						puts("TEQUAL"); return TOKEN(TEQUAL);
"#"						puts("THASH"); return TOKEN(THASH);
"@"						puts("TAT"); return TOKEN(TAT);
.						ERRORLOG(yytext); yyterminate();

%%
