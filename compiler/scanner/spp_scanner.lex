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
\[					    { cout << "[ " << endl; return '['; }
\]					    { cout << "] " << endl; return ']'; }
\{					    { cout << "{ " << endl; return '{'; }
\}					    { cout << "} " << endl; return '}'; }
#\{					    { cout << "#{ " << endl; return DELIM_TUPLE_BEG; } 
\}#					    { cout << "}# " << endl; return DELIM_TUPLE_END; } 
#\[					    { cout << "#[ " << endl; return DELIM_ARRAY_BEG; }
\]#					    { cout << "]# " << endl; return DELIM_ARRAY_BEG; }
\(					    { cout << "( " << endl; return '('; }
\)					    { cout << ") " << endl; return ')'; }
\:					    { cout << "':' " << endl; return ':'; }
, 					    { cout << ", " << endl; return ','; }
;;					    { cout << ";; " << endl; return DELIM_EOS; }
=                       { cout << "= " << endl; return '='; }
\<					    { cout << "< " << endl; return '<'; }
\>					    { cout << "> " << endl; return '>'; }
\.					    { cout << ". " << endl; return '.'; }
\|					    { cout << "| " << endl; return '|'; }
& 					    { cout << "& " << endl; return '&'; }
\^					    { cout << "^ " << endl; return '^'; }
\+					    { cout << "+ " << endl; return '+'; }
-					    { cout << "- " << endl; return '-'; }
\*					    { cout << "* " << endl; return '*'; }
\/					    { cout << "/ " << endl; return '/'; }
%					    { cout << "% " << endl; return '%'; }
~					    { cout << "~ " << endl; return '~'; }
! 					    { cout << "! " << endl; return '!'; }
\+\+				    { cout << "++ " << endl; return OP_ARITH_INCR; }
\-\-				    { cout << "-- " << endl; return OP_ARITH_DECR; }
\*\*				    { cout << "** " << endl; return OP_ARITH_EXPO; }
\|\|				    { cout << "|| " << endl; return OP_LOGIC_OR; }
&& 					    { cout << "&& " << endl; return OP_LOGIC_AND; }
\<= 				    { cout << "<= " << endl; return OP_COMP_LEQ; }
\>=					    { cout << ">= " << endl; return OP_COMP_GEQ; }
== 					    { cout << "== " << endl; return OP_COMP_EQ; }
!=					    { cout << "!= " << endl; return OP_COMP_NEQ; }
\<\<				    { cout << "<< " << endl; return OP_RSHIFT; }
\>\>				    { cout << ">> " << endl; return OP_LSHIFT; }
\+= 				    { cout << "+= " << endl; return OP_ASSIGN_PLUS; }
-= 					    { cout << "-= " << endl; return OP_ASSIGN_MINUS; }
\*= 				    { cout << "*= " << endl; return OP_ASSIGN_MULT; }
\/= 				    { cout << "/= " << endl; return OP_ASSIGN_DIV; }
\*\*=				    { cout << "**= " << endl; return OP_ASSIGN_EXPO; }
%= 					    { cout << "%= " << endl; return OP_ASSIGN_MOD; }
\|=					    { cout << "|= " << endl; return OP_ASSIGN_OR; }
\&=					    { cout << "&= " << endl; return OP_ASSIGN_AND; }
\^=					    { cout << "^= " << endl; return OP_ASSIGN_XOR; }
\.=					    { cout << ".= " << endl; return OP_ASSIGN_CONCAT; }
to					    { cout << "to " << endl; return KEYWORD_TO; }
maki                    { cout << "maki " << endl; return KEYWORD_MAKI; }
soy 				    { cout << "soy " << endl; return KEYWORD_SOY; }
char 					{ cout << "type(char) " << endl; return IDENTIFIER; }
int    				    { cout << "type(int) " << endl; return IDENTIFIER; }
float            	    { cout << "type(float) " << endl; return IDENTIFIER; }
bool 					{ cout << "type(bool) " << endl; return IDENTIFIER; }
string 				    { cout << "type(string) " << endl; return IDENTIFIER; }
array  				    { cout << "type(array) " << endl; return IDENTIFIER; }
list   				    { cout << "type(list) " << endl; return IDENTIFIER; }
tuple  				    { cout << "type(tuple) " << endl; return IDENTIFIER; }
(false|FALSE) 	        { cout << "bool(false) " << endl; yylval.vbool = false; return CONST_BOOL; }
(true|TRUE) 	        { cout << "bool(true) " << endl; yylval.vbool = true; return CONST_BOOL; }
{ALPHA}{WORD_HYPH}*     { cout << "id(" << yytext << ") " << endl; yylval.vstring = new string(yytext); return IDENTIFIER; }
[+-]?{DIGIT}+			{ cout << "int(" << yytext << ") " << endl; yylval.vint = strtol(yytext, NULL, 10); return CONST_INT; }
[+-]?{DIGIT}+\,{DIGIT}+ { cout << "float(" << yytext << ") " << endl; yylval.vdouble = strtof(yytext, NULL); return CONST_FLOAT; }
\"(\\.|[^"])*\"	        { cout << "string(" << yytext << ") " << endl; yylval.vstring = new string(yytext); return CONST_STRING; }
{EOL}+              	{ cout << "eol" << endl; return DELIM_EOL; }
\\. 				    { yyerror("Unrecognized pattern\n"); }

%%
