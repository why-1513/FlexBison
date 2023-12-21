config_command: DFPN channel_no TCOMMA pinNo TCOMMA pin
			  | DFPS dps_channel TCOMMA polarity TCOMMA pin
			  | PSTE sites
			  | CONF conf_parameters
			  | DFGP pin_type TCOMMA pinlist TCOMMA pin_group
			  | PSLC pslc_parameters
			  | PSSL min_voltage TCOMMA max_voltage TCOMMA max_source_current TCOMMA max_sink_current TCOMMA pinlist
			  ;


channel_no: TINTEGER;
pinNo: TLITERAL;

dps_channel: TINTEGER;
polarity: TIDENTIFIER;

sites: TINTEGER;

conf_parameters: pin_type TCOMMA pin_oper_mode TCOMMA pinlist
			   | conf_context TCOMMA pin_type TCOMMA pin_oper_mode TCOMMA pinlist
			   ;
conf_context: TLITERAL
pin_type: TIDENTIFIER;
pin_oper_mode: TIDENTIFIER;

pin_group: TLPAREN pin_group_name TRPAREN;
pin_group_name: TIDENTIFIER;

pslc_parameters: pslc_value TCOMMA DCS_value TCOMMA pinlist
			   | TCOMMA DCS_value TCOMMA pinlist
			   | TCOMMA pinlist
			   ;
pslc_value: TDOUBLE;
DCS_value: TINTEGER;

min_voltage: TMINUS TDOUBLE
		   | TMINUS TINTEGER
		   | TIDENTIFIER
		   ;
max_voltage: TDOUBLE
		   | TINTEGER
		   | TIDENTIFIER
		   ;
max_source_current: TDOUBLE
				  | TINTEGER
				  | TIDENTIFIER
				  ;
max_sink_current: TDOUBLE
				| TINTEGER
				| TIDENTIFIER
				;

pinlist: TLPAREN pin_names TRPAREN;
pin: TLPAREN pin_name TRPAREN;
pin_names: pin_name
		 | pin_names TCOMMA pin_name
		 ;
pin_name: TIDENTIFIER;