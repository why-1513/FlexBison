%{
#include <string>
#include "level_parser.hpp"
#include "LevelAST.h"

extern int yylex();
void yyerror(const char* s)
{
	auto levelLogger = LoggerManager::getLevelLogger();
	levelLogger->error("Error: {}", s);
}
std::shared_ptr<LevelFile> levelfile = std::make_shared<LevelFile>();
std::vector<std::string> pinlist;
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
%token <token> TCOMMA TLPAREN TRPAREN TMINUS TLBRACKET TRBRACKET TMUL TEQUAL THASH TAT

%type <string> dps_No dps_set_id voltage source_current sink_current impedance setup_time level_set_no level_set_id
%type <string> logic_0_level logic_1_level term_mode param_1 param_2 param_3 l_range h_range
%type <string> clamp_mode low_clamp_level high_clamp_level lsux_parameter
%type <string> pin_name

%start level_file
%defines

%%
level_file: level_commands NOOP TLITERAL TCOMMA TCOMMA TCOMMA;

level_commands: level_commands level_command
			   | level_command;

level_command: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{
	levelfile->setFileType(*$3);
}
	| PSLV pslv_parameters
	| DRLV drlv_parameters
	| RCLV rclv_parameters
	| TERM term_parameters
	| CLMP clmp_parameters
	| LSUX lsux_parameter{
		levelfile->lsux->setLevelSetNo(*$2);
	}
	;

pslv_parameters: dps_No TCOMMA voltage TCOMMA source_current TCOMMA impedance TCOMMA setup_time TCOMMA TLPAREN pin_names TRPAREN{
	levelfile->pslv->addData(*$1,"unused",*$3,*$5,"unused",*$7,*$9,pinlist);
}
	| dps_set_id TCOMMA voltage TCOMMA source_current TCOMMA impedance TCOMMA setup_time TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->pslv->addData("unused",*$1,*$3,*$5,"unused",*$7,*$9,pinlist);
	}
	| dps_No TCOMMA voltage TCOMMA source_current TCOMMA sink_current TCOMMA impedance TCOMMA setup_time TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->pslv->addData(*$1,"unused",*$3,*$5,*$7,*$9,*$11,pinlist);
	}
	| dps_set_id TCOMMA voltage TCOMMA source_current TCOMMA sink_current TCOMMA impedance TCOMMA setup_time TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->pslv->addData("unused",*$1,*$3,*$5,*$7,*$9,*$11,pinlist);
	}	
	;

dps_No: TIDENTIFIER;
dps_set_id: TINTEGER
	| TDOUBLE
	;
voltage: TINTEGER
	| TDOUBLE
	;
source_current: TINTEGER
	| TDOUBLE
	;
sink_current: TINTEGER
	| TDOUBLE
	;
impedance: TIDENTIFIER;
setup_time: TNEGINTEGER
	| TINTEGER
	;

drlv_parameters: level_set_no TCOMMA logic_0_level TCOMMA logic_1_level TCOMMA TLPAREN pin_names TRPAREN{
	levelfile->drlv->addData(*$1,"unused",*$3,*$5,pinlist);
}
	| level_set_id TCOMMA logic_0_level TCOMMA logic_1_level TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->drlv->addData("unused",*$1,*$3,*$5,pinlist);
	}
	| level_set_no TCOMMA logic_0_level TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->drlv->addData(*$1,"unused",*$3,"unused",pinlist);
	}
	| level_set_id TCOMMA logic_0_level TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->drlv->addData("unused",*$1,*$3,"unused",pinlist);
	}
	| level_set_no TCOMMA TCOMMA logic_1_level TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->drlv->addData(*$1,"unused","unused",*$4,pinlist);
	}
	| level_set_id TCOMMA TCOMMA logic_1_level TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->drlv->addData("unused",*$1,"unused",*$4,pinlist);
	}
	| level_set_no TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->drlv->addData(*$1,"unused","unused","unused",pinlist);
	}
	| level_set_id TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->drlv->addData("unused",*$1,"unused","unused",pinlist);
	}
	;

rclv_parameters: level_set_no TCOMMA logic_0_level TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
	levelfile->rclv->addData(*$1,"unused",*$3,"unused","unused",pinlist);
}
	| level_set_id TCOMMA logic_0_level TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->rclv->addData("unused",*$1,*$3,"unused","unused",pinlist);
	}
	| level_set_no TCOMMA logic_0_level TCOMMA logic_1_level TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->rclv->addData(*$1,"unused","unused",*$3,*$5,pinlist);
	}
	| level_set_id TCOMMA logic_0_level TCOMMA logic_1_level TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->rclv->addData("unused",*$1,"unused",*$3,*$5,pinlist);
	}
	;

term_parameters:level_set_no TCOMMA term_mode TCOMMA TCOMMA TCOMMA TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
	levelfile->term->addData(*$1,"unused",*$3,"unused","unused","unused","unused","unused",pinlist);
}
	| level_set_id TCOMMA term_mode TCOMMA TCOMMA TCOMMA TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData("unused",*$1,*$3,"unused","unused","unused","unused","unused",pinlist);
	}
	| level_set_no TCOMMA term_mode TCOMMA param_1 TCOMMA TCOMMA TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData(*$1,"unused",*$3,*$5,"unused","unused","unused","unused",pinlist);
	}
	| level_set_id TCOMMA term_mode TCOMMA param_1 TCOMMA TCOMMA TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData("unused",*$1,*$3,*$5,"unused","unused","unused","unused",pinlist);
	}
	| level_set_no TCOMMA term_mode TCOMMA param_1 TCOMMA param_2 TCOMMA TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData(*$1,"unused",*$3,*$5,*$7,"unused","unused","unused",pinlist);
	}
	| level_set_id TCOMMA term_mode TCOMMA param_1 TCOMMA param_2 TCOMMA TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData("unused",*$1,*$3,*$5,*$7,"unused","unused","unused",pinlist);
	}
	| level_set_no TCOMMA term_mode TCOMMA param_1 TCOMMA param_2 TCOMMA param_3 TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData(*$1,"unused",*$3,*$5,*$7,*$9,"unused","unused",pinlist);
	}
	| level_set_id TCOMMA term_mode TCOMMA param_1 TCOMMA param_2 TCOMMA param_3 TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData("unused",*$1,*$3,*$5,*$7,*$9,"unused","unused",pinlist);
	}
	| level_set_no TCOMMA term_mode TCOMMA param_1 TCOMMA param_2 TCOMMA param_3 TCOMMA l_range TCOMMA h_range TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData(*$1,"unused",*$3,*$5,*$7,*$9,*$11,*$13,pinlist);
	}
	| level_set_id TCOMMA term_mode TCOMMA param_1 TCOMMA param_2 TCOMMA param_3 TCOMMA l_range TCOMMA h_range TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->term->addData("unused",*$1,*$3,*$5,*$7,*$9,*$11,*$13,pinlist);
	}
	;

clmp_parameters: level_set_no TCOMMA TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
	levelfile->clmp->addData(*$1,"unused","unused","unused","unused",pinlist);
}
	| level_set_id TCOMMA TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->clmp->addData("unused",*$1,"unused","unused","unused",pinlist);
	}
	| level_set_no TCOMMA clamp_mode TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->clmp->addData(*$1,"unused",*$3,"unused","unused",pinlist);
	}
	| level_set_id TCOMMA clamp_mode TCOMMA TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->clmp->addData("unused",*$1,*$3,"unused","unused",pinlist);
	}
	| level_set_no TCOMMA clamp_mode TCOMMA low_clamp_level TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->clmp->addData(*$1,"unused",*$3,*$5,"unused",pinlist);
	}
	| level_set_id TCOMMA clamp_mode TCOMMA low_clamp_level TCOMMA TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->clmp->addData("unused",*$1,*$3,*$5,"unused",pinlist);
	}
	| level_set_no TCOMMA clamp_mode TCOMMA low_clamp_level TCOMMA high_clamp_level TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->clmp->addData(*$1,"unused",*$3,*$5,*$7,pinlist);
	}
	| level_set_id TCOMMA clamp_mode TCOMMA low_clamp_level TCOMMA high_clamp_level TCOMMA TLPAREN pin_names TRPAREN{
		levelfile->clmp->addData("unused",*$1,*$3,*$5,*$7,pinlist);
	}
	;

level_set_no: TIDENTIFIER;
level_set_id: TINTEGER
	| TDOUBLE
	;

logic_0_level: TINTEGER
	| TDOUBLE
	;
logic_1_level: TINTEGER;

term_mode: TIDENTIFIER;
param_1: TINTEGER
	| TDOUBLE
	| TIDENTIFIER
	| TNEGDOUBLE
	| TNEGINTEGER
	;
param_2: TINTEGER
	| TDOUBLE
	| TIDENTIFIER
	| TNEGDOUBLE
	| TNEGINTEGER
	;
param_3: TINTEGER
	| TDOUBLE
	| TIDENTIFIER
	| TNEGDOUBLE
	| TNEGINTEGER
	;
l_range: TINTEGER
	| TDOUBLE
	| TNEGDOUBLE
	| TNEGINTEGER
	;
h_range: TINTEGER
	| TDOUBLE
	| TNEGDOUBLE
	| TNEGINTEGER
	;

clamp_mode: TIDENTIFIER;
low_clamp_level: TINTEGER
	| TNEGINTEGER
	;
high_clamp_level: TINTEGER
	| TNEGDOUBLE
	;

lsux_parameter: TINTEGER
	| TIDENTIFIER
	;

pin_names: pin_names TCOMMA pin_name {
	pinlist.push_back(*$3);
}
	| pin_name {
		pinlist = std::vector<std::string>();
		pinlist.push_back(*$1);
	};
pin_name: TIDENTIFIER;

%%