%{
#include <iostream>
#include <string>
#include <memory>

#include "level_parser.hpp"
#include "LevelAST.h"

extern int yylex();
void yyerror(const char* s)
{
	printf("Error: %s\n", s);
}
std::shared_ptr<LevelFile> levelfile = std::make_shared<LevelFile>();
std::vector<std::string>* pinlist;

%}
%union
{

	class LevelFile;
	std::string* string;
	int token;
	
}

%token <string> PSLV DRLV RCLV TERM CLMP LSUX EQSP EQNSET SPECS DPSPINS NOOP hp93000
%token <string> LEVELSET PINSIN PINSOUT SPECSET SPECNAME TACTUAL TMINIMUM TMAXIMUM UNITSCOMMENT
%token <string> TDOUBLE TINTEGER TNEGDOUBLE TNEGINTEGER TIDENTIFIER TLITERAL
%token <token> TCOMMA TLPAREN TRPAREN TMINUS TLBRACKET TRBRACKET

%start level_file
%defines

%%
level_file: level_commands NOOP TLITERAL TCOMMA TCOMMA TCOMMA;

level_commands: level_commands level_command
			   | level_command;

level_command: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{

};

%%
