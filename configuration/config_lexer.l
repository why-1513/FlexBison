%{
#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include <stdio.h>
#include "config_parser.hpp"

#define SAVE_TOKEN yylval.string = new std::string(yytext)
#define TOKEN(t) ( yylval.token = t)

static FILE* yyparse_file_ptr;

void yyparse_init(const char* filename)
{
    yyparse_file_ptr = fopen(filename, "r");
	yyin = yyparse_file_ptr;
}

void yyparse_cleanup()
{
	fclose(yyparse_file_ptr);
}

%}

%option noyywrap

%%
[ \t\r\n]               ;
"DFPN"                  puts("DFPN"); return TOKEN(DFPN);
"DFPS"                  puts("DFPS"); return TOKEN(DFPS);
"PSTE"                  puts("PSTE"); return TOKEN(PSTE);
"CONF"                  puts("CONF"); return TOKEN(CONF);
"DFGP"                  puts("DFGP"); return TOKEN(DFGP);
"PSLC"                  puts("PSLC"); return TOKEN(PSLC);
"PSSL"                  puts("PSSL"); return TOKEN(PSSL);
"NOOP"                  puts("NOOP"); return TOKEN(NOOP);
"hp93000"               puts("HEADERROW"); return TOKEN(HEADERROW);
\"(.*?)\"               SAVE_TOKEN; puts(yytext); return TOKEN(TLITERAL);
[a-zA-Z][a-zA-Z0-9_]*	SAVE_TOKEN; puts(yytext); return TOKEN(TIDENTIFIER);
[0-9]+\.[0-9]*			SAVE_TOKEN; puts(yytext); return TOKEN(TDOUBLE);
[0-9]+  				SAVE_TOKEN; puts(yytext); return TOKEN(TINTEGER);
"-"                     puts("TMINUS"); return TOKEN(TMINUS);
","                     puts("TCOMMA"); return TOKEN(TCOMMA);
"("                     puts("TLPAREN"); return TOKEN(TLPAREN);
")"                     puts("TRPAREN"); return TOKEN(TRPAREN);
.                       printf("Unknown token:%s\n", yytext); yyterminate();
%%
