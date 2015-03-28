%{
	#include <iostream>
	#include "../parser/sushipp.tab.h"
	using namespace std;
	#define YY_DECL extern "C" int yylex()

	void yyerror(const char*);
	
	/**
	 * @brief Count the number of newline characters in the given string
	 * @param[in] char* str The string 
	 * @param[in] size_t length The length 
	 * @retval The number of newline characters
	 * @note Take into account the variation of newline characters among various OSes
	 * @note Every other characters are skipped
	 */
	int count_ln(char* str, size_t length);

	int line = 0;
%}


EOL        (\r|\n|\r\n)
DIGIT      [0-9]
WORD	   [0-9A-Za-z_]
WORD_HYPH  [-0-9A-Za-z_]
ALPHA      [a-zA-Z]

%%

\[					    { cout /*<< "l." << line*/ << "[ "; return '['; }
\]					    { cout /*<< "l." << line*/ << "] "; return ']'; }
\{					    { cout /*<< "l." << line*/ << "{ "; return '{'; }
\}					    { cout /*<< "l." << line*/ << "} "; return '}'; }
#\{					    { cout /*<< "l." << line*/ << "#{ "; return DELIM_TUPLE_BEG; } 
\}#					    { cout /*<< "l." << line*/ << "}# "; return DELIM_TUPLE_END; } 
#\[					    { cout /*<< "l." << line*/ << "#[ "; return DELIM_ARRAY_BEG; }
\]#					    { cout /*<< "l." << line*/ << "]# "; return DELIM_ARRAY_END; }
\(					    { cout /*<< "l." << line*/ << "( "; return '('; }
\)					    { cout /*<< "l." << line*/ << ") "; return ')'; }
\:					    { cout /*<< "l." << line*/ << "':' "; return ':'; }
, 					    { cout /*<< "l." << line*/ << ", "; return ','; }
;;					    { cout /*<< "l." << line*/ << ";; "; return DELIM_EOS; }
=                       { cout /*<< "l." << line*/ << "= "; return '='; }
\<					    { cout /*<< "l." << line*/ << "< "; return '<'; }
\>					    { cout /*<< "l." << line*/ << "> "; return '>'; }
\.					    { cout /*<< "l." << line*/ << ". "; return '.'; }
\|					    { cout /*<< "l." << line*/ << "| "; return '|'; }
& 					    { cout /*<< "l." << line*/ << "& "; return '&'; }
\^					    { cout /*<< "l." << line*/ << "^ "; return '^'; }
\+					    { cout /*<< "l." << line*/ << "+ "; return '+'; }
-					    { cout /*<< "l." << line*/ << "- "; return '-'; }
\*					    { cout /*<< "l." << line*/ << "* "; return '*'; }
\/					    { cout /*<< "l." << line*/ << "/ "; return '/'; }
%					    { cout /*<< "l." << line*/ << "% "; return '%'; }
~					    { cout /*<< "l." << line*/ << "~ "; return '~'; }
! 					    { cout /*<< "l." << line*/ << "! "; return '!'; }
_						{ cout /*<< "l." << line*/ << "_ "; return '_'; }
-\>						{ cout /*<< "l." << line*/ << "-> "; return DELIM_ARROW; }
\+\+				    { cout /*<< "l." << line*/ << "++ "; return OP_ARITH_INCR; }
\-\-				    { cout /*<< "l." << line*/ << "-- "; return OP_ARITH_DECR; }
\*\*				    { cout /*<< "l." << line*/ << "** "; return OP_ARITH_EXPO; }
\|\|				    { cout /*<< "l." << line*/ << "|| "; return OP_LOGIC_OR; }
&& 					    { cout /*<< "l." << line*/ << "&& "; return OP_LOGIC_AND; }
\<= 				    { cout /*<< "l." << line*/ << "<= "; return OP_COMP_LEQ; }
\>=					    { cout /*<< "l." << line*/ << ">= "; return OP_COMP_GEQ; }
== 					    { cout /*<< "l." << line*/ << "== "; return OP_COMP_EQ; }
!=					    { cout /*<< "l." << line*/ << "!= "; return OP_COMP_NEQ; }
\<\<				    { cout /*<< "l." << line*/ << "<< "; return OP_RSHIFT; }
\>\>				    { cout /*<< "l." << line*/ << ">> "; return OP_LSHIFT; }
\+= 				    { cout /*<< "l." << line*/ << "+= "; return OP_ASSIGN_PLUS; }
-= 					    { cout /*<< "l." << line*/ << "-= "; return OP_ASSIGN_MINUS; }
\*= 				    { cout /*<< "l." << line*/ << "*= "; return OP_ASSIGN_MULT; }
\/= 				    { cout /*<< "l." << line*/ << "/= "; return OP_ASSIGN_DIV; }
\*\*=				    { cout /*<< "l." << line*/ << "**= "; return OP_ASSIGN_EXPO; }
%= 					    { cout /*<< "l." << line*/ << "%= "; return OP_ASSIGN_MOD; }
\|=					    { cout /*<< "l." << line*/ << "|= "; return OP_ASSIGN_OR; }
\&=					    { cout /*<< "l." << line*/ << "&= "; return OP_ASSIGN_AND; }
\^=					    { cout /*<< "l." << line*/ << "^= "; return OP_ASSIGN_XOR; }
\.=					    { cout /*<< "l." << line*/ << ".= "; return OP_ASSIGN_CONCAT; }
to					    { cout /*<< "l." << line*/ << "to "; return KEYWORD_TO; }
maki                    { cout /*<< "l." << line*/ << "maki "; return KEYWORD_MAKI; }
soy 				    { cout /*<< "l." << line*/ << "soy "; return KEYWORD_SOY; }
nori					{ cout /*<< "l." << line*/ << "nori "; return KEYWORD_NORI; }
menu					{ cout /*<< "l." << line*/ << "menu "; return KEYWORD_MENU; }
break					{ cout /*<< "l." << line*/ << "break"; return KEYWORD_BREAK; }
continue				{ cout /*<< "l." << line*/ << "continue"; return KEYWORD_CONTINUE; }
roll					{ cout /*<< "l." << line*/ << "roll"; return KEYWORD_ROLL; }
for 					{ cout /*<< "l." << line*/ << "for"; return KEYWORD_FOR; }
foreach					{ cout /*<< "l." << line*/ << "foreach"; return KEYWORD_FOREACH; }
as 						{ cout /*<< "l." << line*/ << "as"; return KEYWORD_AS; }
char 					{ cout /*<< "l." << line*/ << "type(char) "; return IDENTIFIER; }
int    				    { cout /*<< "l." << line*/ << "type(int) "; return IDENTIFIER; }
float            	    { cout /*<< "l." << line*/ << "type(float) "; return IDENTIFIER; }
bool 					{ cout /*<< "l." << line*/ << "type(bool) "; return IDENTIFIER; }
string 				    { cout /*<< "l." << line*/ << "type(string) "; return IDENTIFIER; }
array  				    { cout /*<< "l." << line*/ << "type(array) "; return IDENTIFIER; }
list   				    { cout /*<< "l." << line*/ << "type(list) "; return IDENTIFIER; }
tuple  				    { cout /*<< "l." << line*/ << "type(tuple) "; return IDENTIFIER; }
(false|FALSE) 	        { cout /*<< "l." << line*/ << "bool(false) "; yylval.vbool = false; return CONST_BOOL; }
(true|TRUE) 	        { cout /*<< "l." << line*/ << "bool(true) "; yylval.vbool = true; return CONST_BOOL; }
{ALPHA}{WORD_HYPH}*     { cout /*<< "l." << line*/ << "id(" << yytext << ") "; yylval.vstring = new string(yytext); return IDENTIFIER; }
[+-]?{DIGIT}+			{ cout /*<< "l." << line*/ << "int(" << yytext << ") "; yylval.vint = strtol(yytext, NULL, 10); return CONST_INT; }
[+-]?{DIGIT}+\,{DIGIT}+ { cout /*<< "l." << line*/ << "float(" << yytext << ") "; yylval.vdouble = strtof(yytext, NULL); return CONST_FLOAT; }
\"(\\.|[^"])*\"	        { cout /*<< "l." << line*/ << "string(" << yytext << ") "; yylval.vstring = new string(yytext); return CONST_STRING; }
'(\\.|[^'])'	  		{ cout /*<< "l." << line*/ << "char(" << yytext << ") "; yylval.vchar = yytext[1]; return CONST_CHAR; }
({EOL}|\$.*{EOL})+		{ cout /*<< "l." << line*/ << "eol" << endl; line += count_ln(yytext, yyleng); return DELIM_EOL; }
\\. 				    { yyerror("Unrecognized pattern\n"); }

%%

int count_ln(char* str, size_t length)
{
	size_t cnt_lf = 0, cnt_cr = 0, i;

	for(i = 0; i < length; ++i)
		switch(str[i])
		{
			case '\n': 
				cnt_lf++; break;
			case '\r':
				cnt_cr++; break;
			default: continue; 
		}

	if(cnt_lf != 0 && cnt_cr != 0) // windows-link
		return cnt_lf;
	else if(cnt_cr != 0) // mac before version 9
		return cnt_cr;
	else // MAC OS X, Unix
		return cnt_lf;
}