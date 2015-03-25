%{
	#include <iostream>
	#include "../parser/sushipp.tab.h"
	using namespace std;
	#define YY_DECL extern "C" int yylex()

	void yyerror(const char*);
%}


%%

=                      { cout << "t : =" << endl; return OP_ASSIGN; }
maki                   { cout << "t : maki" << endl; yylval.vstring = new string(yytext); return KEYWORD_MAKI; }
[a-zA-Z][-a-zA-Z0-9_]* { cout << "t : id(" << yytext << ")" << endl; yylval.vstring = new string(yytext); return IDENTIFIER; }
[+-]?[0-9]+			   { cout << "t : int(" << yytext << ")" << endl; yylval.vint = strtol(yytext, NULL, 10); return CONST_INT; }
[+-]?[0-9]+\,[0-9]+    { cout << "t : float(" << yytext << ")" << endl; yylval.vdouble = strtof(yytext, NULL); return CONST_FLOAT; }
\"(\\.|[^"])*\"		   { cout << "t : string(" << yytext << ")" << endl; yylval.vstring = new string(yytext); return CONST_STRING; }
(\r|\n|\r\n)+          { cout << "t : eol" << endl; return DELIM_EOL; }
\\. 				   { yyerror("Unrecognized pattern\n"); }

%%
