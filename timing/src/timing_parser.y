%{
#include <string>
#include "timing_parser.hpp"
#include "TimingAST.h"

extern int yylex();
void yyerror(const char* s)
{
	auto timingLogger = LoggerManager::getTimingLogger();
	timingLogger->error("Error: {}", s);
}
std::shared_ptr<TimingFile> timingfile = std::make_shared<TimingFile>();
std::vector<std::string> pinlist;
auto eqsp = std::make_shared<EquationSpecificationTransfer>();
auto eqnset = std::make_shared<EqnSet>();
auto timingset = std::make_shared<TimingSet>();
auto specset = std::make_shared<SpecSet>();
auto wavetbl = std::make_shared<WaveTBL>();
auto pinset = std::make_shared<PinSet>();
auto logicalwaveform = std::make_shared<LogicalWaveform>();
std::vector<std::string> edges;
std::vector<std::string> actions;

%}

%union
{

	class TimingFile;
	std::string* string;
	int token;
	
}

%token <string> PCLK CLKR BWDS ETDS DCDT TSUX EQSP EQNSET SPECS NOOP hp93000
%token <string> WAVETBL STATEMAP PINS TIMINGSET EQUATIONS CHECKALL SPECSET
%token <string> SPECNAME TACTUAL TMINIMUM TMAXIMUM UNITSCOMMENT
%token <string> TDOUBLE TINTEGER TNEGDOUBLE TNEGINTEGER TIDENTIFIER TLITERAL EXPRESSION
%token <token> TQUOTATION TCOMMA TLPAREN TRPAREN TCOLON TLBRACKET TRBRACKET TEQUAL THASH TAT

%type <string> waveform_set timing_set period period_res ref_period wvf_set break_waveform_index definition_string default_name
%type <string> spec_type eqspart equation_set_number equation_set_description spec_name spec_unit wavetbl_name pin_group
%type <string> physical_waveform_number edge action waveform_name xNMode equationVariable
%type <string> pin_name

%start timing_file
%defines

%%
timing_file: timing_commands NOOP TLITERAL TCOMMA TCOMMA TCOMMA;

timing_commands: timing_commands timing_command
			   | timing_command;

timing_command: hp93000 TCOMMA TIDENTIFIER TCOMMA TDOUBLE{
	timingfile->setFileType(*$3);
}
	| PCLK pclk_parameters
	| CLKR waveform_set TCOMMA ref_period TCOMMA period_res{
		timingfile->clkr->addData(*$2,*$6);
	}
	| BWDS bwds_parameters
	| ETDS etds_parameters
	| DCDT waveform_set TCOMMA default_name{
		timingfile->dcdt->addData(*$2,*$4);
	}
	| TSUX waveform_set TCOMMA timing_set{
		timingfile->tsux->addData(*$2,*$4);
	}
	| EQSP spec_type TCOMMA eqspart TCOMMA THASH TINTEGER eqsp_commands TAT{
		eqsp->setNumber(*$2,*$4);

		eqsp->addEqnSet(eqnset);
		eqnset.reset();
		eqnset = std::make_shared<EqnSet>();

		eqsp->addTimingSet(timingset);
		timingset.reset();
		timingset = std::make_shared<TimingSet>();

		eqsp->addWaveTbl(wavetbl);
		wavetbl.reset();
		wavetbl = std::make_shared<WaveTBL>();

		timingfile->eqsps.push_back(eqsp);
		eqsp.reset();
		eqsp = std::make_shared<EquationSpecificationTransfer>();

	}
	;

pclk_parameters: waveform_set TCOMMA timing_set TCOMMA period TCOMMA TLPAREN pin_names TRPAREN{
	timingfile->pclk->addFixData(*$1,*$3,*$5,pinlist);
}
	| waveform_set TCOMMA timing_set TCOMMA period TCOMMA TLPAREN TAT TRPAREN{
		pinlist = std::vector<std::string>();
		pinlist.push_back("@");
		timingfile->pclk->addFixData(*$1,*$3,*$5,pinlist);
	}
	;

etds_parameters: waveform_set TCOMMA timing_set TCOMMA TCOMMA definition_string TCOMMA TLPAREN pin_names TRPAREN{
	timingfile->etds->addData(*$1,*$3,*$6,pinlist);
}

waveform_set: TINTEGER;
timing_set: TIDENTIFIER
	| TINTEGER
	;
period: TINTEGER
	| TDOUBLE
	;

ref_period: TINTEGER
	| TDOUBLE
	;
period_res: TINTEGER
	| TDOUBLE
	;

bwds_parameters: wvf_set TCOMMA TCOMMA TCOMMA definition_string TCOMMA TLPAREN pin_names TRPAREN{
		timingfile->bwds->addData(*$1,"unused",*$5,pinlist);
	}
	| wvf_set TCOMMA break_waveform_index TCOMMA TCOMMA definition_string TCOMMA TLPAREN pin_names TRPAREN{
		timingfile->bwds->addData(*$1,*$3,*$6,pinlist);
	}
	;
wvf_set: TIDENTIFIER
	| TINTEGER
	;
break_waveform_index: TIDENTIFIER
	| TINTEGER
	;
definition_string: TLITERAL;

default_name: TLITERAL;

pin_names: pin_names TCOMMA pin_name {
	pinlist.push_back(*$3);
}
	| pin_name {
		pinlist = std::vector<std::string>();
		pinlist.push_back(*$1);
	};

eqsp_commands: eqsp_commands eqsp_command
	| eqsp_command
	;

eqsp_command: EQNSET equation_set_number equation_set_description{
	eqnset->setNumber(*$2,*$3);
}
	| WAVETBL wavetbl_name{
		wavetbl->setName(*$2);
	}
	| PINS pin_group waveform_infos{
		logicalwaveform->setGroup(*$2);

		wavetbl->addWaveform(logicalwaveform);
		logicalwaveform.reset();
		logicalwaveform = std::make_shared<LogicalWaveform>();
	}
	| STATEMAP statemap_infos
	| SPECS specs_parameters
	| EQUATIONS equations
	;

spec_type: TIDENTIFIER;
eqspart: TIDENTIFIER;
equation_set_number: TINTEGER;
equation_set_description: TLITERAL;
wavetbl_name: TLITERAL;

waveform_infos: waveform_infos waveform_info
	| waveform_info
	;
waveform_info: physical_waveform_number TQUOTATION edges_actions TQUOTATION waveform_name{
	logicalwaveform->addPinsData(*$1,edges,actions,*$5);
};
edges_actions: edges_actions edge_action
	| edge_action
	;
edge_action: edge TCOLON action{
	edges = std::vector<std::string>();
	actions = std::vector<std::string>();

	edges.push_back(*$1);
	actions.push_back(*$3);
};

edge: TIDENTIFIER;
action: TINTEGER
	| TIDENTIFIER
	;
statemap_infos: statemap_infos statemap_info
	| statemap_info
	;
statemap_info: physical_waveform_number waveform_name xNMode;

pin_group: TIDENTIFIER;
physical_waveform_number: TINTEGER;
waveform_name: TINTEGER
	| TIDENTIFIER
	;
xNMode: TIDENTIFIER;

specs_parameters: specs_parameters specs_parameters
	| specs_parameter
	;
specs_parameter: spec_name TLBRACKET spec_unit TRBRACKET{
	eqnset->addSpecsData(*$1,*$3);
};

spec_name: TIDENTIFIER;
spec_unit: TIDENTIFIER;

pin_name: TIDENTIFIER;

equations: equations equation
	| equation
	;
equation: equationVariable TEQUAL EXPRESSION{
	eqnset->addExpression(*$1,*$3);
};
equationVariable: TIDENTIFIER;

%%