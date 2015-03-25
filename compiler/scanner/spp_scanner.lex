%{
	#include <iostream>
	#include "../parser/sushipp.tab.h"
	using namespace std;
	#define YY_DECL extern "C" int yylex()

	void yyerror(const char*);
%}


%%

\[					   { cout << "t : [" << endl; return '['; }
\]					   { cout << "t : ]" << endl; return ']'; }
\:					   { cout << "t : ':'" << endl; return ':'; }
, 					   { cout << "t : ," << endl; return ','; }
;;					   { cout << "t : ;;" << endl; return DELIM_EOS; }
=                      { cout << "t : =" << endl; return '='; }
\<					   { cout << "t : <" << endl; return '<'; }
\>					   { cout << "t : >" << endl; return '>'; }
\.					   { cout << "t : ." << endl; return '.'; }
\|					   { cout << "t : |" << endl; return '|'; }
& 					   { cout << "t : &" << endl; return '&'; }
\^					   { cout << "t : ^" << endl; return '^'; }
\+					   { cout << "t : +" << endl; return '+'; }
-					   { cout << "t : -" << endl; return '-'; }
\*					   { cout << "t : *" << endl; return '*'; }
\/					   { cout << "t : /" << endl; return '/'; }
%					   { cout << "t : %" << endl; return '%'; }
~					   { cout << "t : ~" << endl; return '~'; }
! 					   { cout << "t : !" << endl; return '!'; }
\+\+				   { cout << "t : ++" << endl; return OP_ARITH_INCR; }
\-\-				   { cout << "t : --" << endl; return OP_ARITH_DECR; }
\*\*				   { cout << "t : **" << endl; return OP_ARITH_EXPO; }
\|\|				   { cout << "t : ||" << endl; return OP_LOGIC_OR; }
&& 					   { cout << "t : &&" << endl; return OP_LOGIC_AND; }
\<= 				   { cout << "t : <=" << endl; return OP_COMP_LEQ; }
\>=					   { cout << "t : >=" << endl; return OP_COMP_GEQ; }
== 					   { cout << "t : ==" << endl; return OP_COMP_EQ; }
!=					   { cout << "t : !=" << endl; return OP_COMP_NEQ; }
\<\<				   { cout << "t : <<" << endl; return OP_RSHIFT; }
\>\>				   { cout << "t : >>" << endl; return OP_LSHIFT; }
\+= 				   { cout << "t : +=" << endl; return OP_ASSIGN_PLUS; }
-= 					   { cout << "t : -=" << endl; return OP_ASSIGN_MINUS; }
\*= 				   { cout << "t : *=" << endl; return OP_ASSIGN_MULT; }
\/= 				   { cout << "t : /=" << endl; return OP_ASSIGN_DIV; }
\*\*=				   { cout << "t : **=" << endl; return OP_ASSIGN_EXPO; }
%= 					   { cout << "t : %=" << endl; return OP_ASSIGN_MOD; }
\|=					   { cout << "t : |=" << endl; return OP_ASSIGN_OR; }
\&=					   { cout << "t : &=" << endl; return OP_ASSIGN_AND; }
\^=					   { cout << "t : ^=" << endl; return OP_ASSIGN_XOR; }
\.=					   { cout << "t : .=" << endl; return OP_ASSIGN_CONCAT; }
maki                   { cout << "t : maki" << endl; yylval.vstring = new string(yytext); return KEYWORD_MAKI; }
int    				   { cout << "t : type 'int'" << endl; return TYPE_INT; }
string 				   { cout << "t : type 'string'" << endl; return TYPE_STRING; }
array  				   { cout << "t : type 'array'" << endl; return TYPE_ARRAY; }
list   				   { cout << "t : type 'list'" << endl; return TYPE_LIST; }
tuple  				   { cout << "t : type 'tuple'" << endl; return TYPE_TUPLE; }
[a-zA-Z][-a-zA-Z0-9_]* { cout << "t : id(" << yytext << ")" << endl; yylval.vstring = new string(yytext); return IDENTIFIER; }
[+-]?[0-9]+			   { cout << "t : int(" << yytext << ")" << endl; yylval.vint = strtol(yytext, NULL, 10); return CONST_INT; }
[+-]?[0-9]+\,[0-9]+    { cout << "t : float(" << yytext << ")" << endl; yylval.vdouble = strtof(yytext, NULL); return CONST_FLOAT; }
\"(\\.|[^"])*\"		   { cout << "t : string(" << yytext << ")" << endl; yylval.vstring = new string(yytext); return CONST_STRING; }
(\r|\n|\r\n)+          { cout << "t : eol" << endl; return DELIM_EOL; }
\\. 				   { yyerror("Unrecognized pattern\n"); }

%%
