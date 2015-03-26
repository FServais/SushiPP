%{
	#include <iostream>
	#include "../parser/sushipp.tab.h"
	using namespace std;
	#define YY_DECL extern "C" int yylex()

	void yyerror(const char*);
%}


EOL    (\r|\n|\r\n)
DIGIT      [0-9]
WORD	   [0-9A-Za-z_]
WORD_HYPH  [-0-9A-Za-z_]
ALPHA      [a-zA-Z]

%%

\$.+{EOL}		    	{ cout << "comment" << endl; return DELIM_EOL; }
\[					    { cout << "[ "; return '['; }
\]					    { cout << "] "; return ']'; }
\{					    { cout << "{ "; return '{'; }
\}					    { cout << "} "; return '}'; }
#\{					    { cout << "#{ "; return DELIM_TUPLE_BEG; } 
\}#					    { cout << "}# "; return DELIM_TUPLE_END; } 
#\[					    { cout << "#[ "; return DELIM_ARRAY_BEG; }
\]#					    { cout << "]# "; return DELIM_ARRAY_END; }
\(					    { cout << "( "; return '('; }
\)					    { cout << ") "; return ')'; }
\:					    { cout << "':' "; return ':'; }
, 					    { cout << ", "; return ','; }
;;					    { cout << ";; "; return DELIM_EOS; }
=                       { cout << "= "; return '='; }
\<					    { cout << "< "; return '<'; }
\>					    { cout << "> "; return '>'; }
\.					    { cout << ". "; return '.'; }
\|					    { cout << "| "; return '|'; }
& 					    { cout << "& "; return '&'; }
\^					    { cout << "^ "; return '^'; }
\+					    { cout << "+ "; return '+'; }
-					    { cout << "- "; return '-'; }
\*					    { cout << "* "; return '*'; }
\/					    { cout << "/ "; return '/'; }
%					    { cout << "% "; return '%'; }
~					    { cout << "~ "; return '~'; }
! 					    { cout << "! "; return '!'; }
\+\+				    { cout << "++ "; return OP_ARITH_INCR; }
\-\-				    { cout << "-- "; return OP_ARITH_DECR; }
\*\*				    { cout << "** "; return OP_ARITH_EXPO; }
\|\|				    { cout << "|| "; return OP_LOGIC_OR; }
&& 					    { cout << "&& "; return OP_LOGIC_AND; }
\<= 				    { cout << "<= "; return OP_COMP_LEQ; }
\>=					    { cout << ">= "; return OP_COMP_GEQ; }
== 					    { cout << "== "; return OP_COMP_EQ; }
!=					    { cout << "!= "; return OP_COMP_NEQ; }
\<\<				    { cout << "<< "; return OP_RSHIFT; }
\>\>				    { cout << ">> "; return OP_LSHIFT; }
\+= 				    { cout << "+= "; return OP_ASSIGN_PLUS; }
-= 					    { cout << "-= "; return OP_ASSIGN_MINUS; }
\*= 				    { cout << "*= "; return OP_ASSIGN_MULT; }
\/= 				    { cout << "/= "; return OP_ASSIGN_DIV; }
\*\*=				    { cout << "**= "; return OP_ASSIGN_EXPO; }
%= 					    { cout << "%= "; return OP_ASSIGN_MOD; }
\|=					    { cout << "|= "; return OP_ASSIGN_OR; }
\&=					    { cout << "&= "; return OP_ASSIGN_AND; }
\^=					    { cout << "^= "; return OP_ASSIGN_XOR; }
\.=					    { cout << ".= "; return OP_ASSIGN_CONCAT; }
to					    { cout << "to "; return KEYWORD_TO; }
maki                    { cout << "maki "; return KEYWORD_MAKI; }
soy 				    { cout << "soy "; return KEYWORD_SOY; }
char 					{ cout << "type(char) "; return IDENTIFIER; }
int    				    { cout << "type(int) "; return IDENTIFIER; }
float            	    { cout << "type(float) "; return IDENTIFIER; }
bool 					{ cout << "type(bool) "; return IDENTIFIER; }
string 				    { cout << "type(string) "; return IDENTIFIER; }
array  				    { cout << "type(array) "; return IDENTIFIER; }
list   				    { cout << "type(list) "; return IDENTIFIER; }
tuple  				    { cout << "type(tuple) "; return IDENTIFIER; }
(false|FALSE) 	        { cout << "bool(false) "; yylval.vbool = false; return CONST_BOOL; }
(true|TRUE) 	        { cout << "bool(true) "; yylval.vbool = true; return CONST_BOOL; }
{ALPHA}{WORD_HYPH}*     { cout << "id(" << yytext << ") "; yylval.vstring = new string(yytext); return IDENTIFIER; }
[+-]?{DIGIT}+			{ cout << "int(" << yytext << ") "; yylval.vint = strtol(yytext, NULL, 10); return CONST_INT; }
[+-]?{DIGIT}+\,{DIGIT}+ { cout << "float(" << yytext << ") "; yylval.vdouble = strtof(yytext, NULL); return CONST_FLOAT; }
\"(\\.|[^"])*\"	        { cout << "string(" << yytext << ") "; yylval.vstring = new string(yytext); return CONST_STRING; }
{EOL}+              	{ cout << "eol" << endl; return DELIM_EOL; }
\\. 				    { yyerror("Unrecognized pattern\n"); }

%%
