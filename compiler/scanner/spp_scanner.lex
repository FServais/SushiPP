%{
	#include <iostream>
	#include "../parser/sushipp.tab.h"
	using namespace std;
	#define YY_DECL extern "C" int yylex()

	void yyerror(const char*);
%}

%%
=                      { return OP_ASSIGN; }
maki                   { yylval.vstring = new string(yytext); return KEYWORD_MAKI; }
[a-zA-Z][-a-zA-Z0-9_]* { yylval.vstring = new string(yytext); return IDENTIFIER; }
[+-]?\d+			   { yylval.vint = strtol(yytext, NULL, 10); return CONST_INT; }
[+-]?\d+\,\d+          { yylval.vdouble = strtof(yytext, NULL); return CONST_FLOAT; }
\"[^\"]\"              { yylval.vstring = new string(yytext); return CONST_STRING; }
(\r|\n|\r\n)+          { return DELIM_EOL; }
.                      { yyerror("Unrecognized sequence"); }

%%
