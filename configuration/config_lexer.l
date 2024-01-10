%{
#include <string>

#include "config_parser.hpp"
#include "ConfigAST.h"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) ( yylval.token = t)
#define ERRORLOG(t) configLogger->error("Error: Unknown token: {}", t)

auto configLogger = LoggerManager::getConfigLogger();

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
"DFPN"					return TOKEN(DFPN);
"DFPS"					return TOKEN(DFPS);
"PSTE"					return TOKEN(PSTE);
"CONF"					return TOKEN(CONF);
"DFGP"					return TOKEN(DFGP);
"PSLC"					return TOKEN(PSLC);
"PSSL"					return TOKEN(PSSL);
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
.						ERRORLOG(yytext); yyterminate();

%%
