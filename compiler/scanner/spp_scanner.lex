%{
	#include <iostream>
	#include "spp_parser.tab.h"
	using namespace std;
	#define YY_DECL extern "C" int yylex()

	void yyerror(const char*);
%}

%%
=                      { return OP_ASSIGN; }
maki                   { yyval.vstring = string(yytext); return KEYWORD_MAKI; }
[a-zA-Z][-a-zA-Z0-9_]* { yyval.vstring = string(yytext); return IDENTIFIER; }
[+-]?\d+			   { yyval.vint = strtol(yytext, NULL, 10); return CONST_INT; }
[+-]?\d+\,\d+          { yyval.vdouble = strtof(yytext, NULL); return CONST_FLOAT; }
\"[^\"]\"              { yyval.vstring = string(yytext); return CONST_STRING; }
(\r|\n|\r\n)+          { return DELIM_EOL; }
.                      { yyerror("Unrecognized sequence"); }

%%
