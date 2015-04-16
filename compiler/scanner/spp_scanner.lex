%{
	#include <iostream>
	#include <sstream>
	#include "../parser/sushipp.tab.h"
	using namespace std;
	#define YY_DECL extern "C" int yylex()

	extern void yyerror(const char*);
	extern bool error_occurred;
	#define YY_USER_ACTION update_yylloc();

	/**
	 * @brief Count the number of newline characters in the given string
	 * @param[in] char* str The string
	 * @param[in] size_t length The length
	 * @retval The number of newline characters
	 * @note Take into account the variation of newline characters among various OSes
	 * @note Every other characters are skipped
	 */
	int count_ln(const char* str, size_t length);

	/**
	 * @brief Compute the end column for the given token starting at the column first_col
	 * @param[in] int 		  first_col The column at which starts the column
	 * @param[in] const char* token 	The token string
	 * @param[in] size_t      token_len The length of the token string
	 * @retval int Return the number of the column one past the end the last element
	 */
	int compute_end_column(int first_col, const char* token, size_t token_len);

	void update_yylloc();
%}

%option noyywrap

EOL        (\r|\n|\r\n)
DIGIT      [0-9]
WORD	   [0-9A-Za-z_]
WORD_HYPH  [-0-9A-Za-z_]
ALPHA      [a-zA-Z]

%%

\[                      { return '['; }
\]                      { return ']'; }
\{                      { return '{'; }
\}                      { return '}'; }
#\[                     { return DELIM_ARRAY_BEG; }
\]#                     { return DELIM_ARRAY_END; }
\(                      { return '('; }
\)                      { return ')'; }
\:                      { return ':'; }
,                       { return ','; }
;;                      { return DELIM_EOS; }
=                       { return '='; }
\<                      { return '<'; }
\>                      { return '>'; }
\.                      { return '.'; }
\|                      { return '|'; }
&                       { return '&'; }
\^                      { return '^'; }
\+                      { return '+'; }
-                       { return '-'; }
\*                      { return '*'; }
\/                      { return '/'; }
%                       { return '%'; }
~                       { return '~'; }
!                       { return '!'; }
_                       { return '_'; }
-\>                     { return DELIM_ARROW; }
\+\+                    { return OP_ARITH_INCR; }
\-\-                    { return OP_ARITH_DECR; }
\*\*                    { return OP_ARITH_EXPO; }
\|\|                    { return OP_LOGIC_OR; }
&&                      { return OP_LOGIC_AND; }
\<=                     { return OP_COMP_LEQ; }
\>=                     { return OP_COMP_GEQ; }
==                      { return OP_COMP_EQ; }
!=                      { return OP_COMP_NEQ; }
\<\<                    { return OP_RSHIFT; }
\>\>                    { return OP_LSHIFT; }
\+=                     { return OP_ASSIGN_PLUS; }
-=                      { return OP_ASSIGN_MINUS; }
\*=                     { return OP_ASSIGN_MULT; }
\/=                     { return OP_ASSIGN_DIV; }
\*\*=                   { return OP_ASSIGN_EXPO; }
%=                      { return OP_ASSIGN_MOD; }
\|=                     { return OP_ASSIGN_OR; }
\&=                     { return OP_ASSIGN_AND; }
\^=                     { return OP_ASSIGN_XOR; }
\.=                     { return OP_ASSIGN_CONCAT; }
to                      { return KEYWORD_TO; }
maki                    { return KEYWORD_MAKI; }
soy                     { return KEYWORD_SOY; }
nori                    { return KEYWORD_NORI; }
menu                    { return KEYWORD_MENU; }
break                   { return KEYWORD_BREAK; }
continue				{ return KEYWORD_CONTINUE; }
roll                    { return KEYWORD_ROLL; }
for                     { return KEYWORD_FOR; }
foreach                 { return KEYWORD_FOREACH; }
as                      { return KEYWORD_AS; }
if                      { return KEYWORD_IF; }
elseif                  { return KEYWORD_ELSEIF; }
else                    { return KEYWORD_ELSE; }
char                    { yylval.vstring = new string(yytext, yyleng); return IDENTIFIER; }
int                     { yylval.vstring = new string(yytext, yyleng); return IDENTIFIER; }
float                   { yylval.vstring = new string(yytext, yyleng); return IDENTIFIER; }
bool                    { yylval.vstring = new string(yytext, yyleng); return IDENTIFIER; }
string                  { yylval.vstring = new string(yytext, yyleng); return IDENTIFIER; }
array                   { yylval.vstring = new string(yytext, yyleng); return IDENTIFIER; }
list                    { yylval.vstring = new string(yytext, yyleng); return IDENTIFIER; }
(false|FALSE|true|TRUE) { yylval.vstring = new string(yytext, yyleng); return CONST_BOOL; }
{ALPHA}{WORD_HYPH}*     { yylval.vstring = new string(yytext, yyleng); return IDENTIFIER; }
[+-]?{DIGIT}+           { yylval.vstring = new string(yytext, yyleng); return CONST_INT; }
[+-]?{DIGIT}+\.{DIGIT}+ { yylval.vstring = new string(yytext, yyleng); return CONST_FLOAT; }
\"[^"]*\"               { yylval.vstring = new string(yytext, yyleng); return CONST_STRING; }
'[^']'                  { yylval.vstring = new string(yytext, yyleng); return CONST_CHAR; }
({EOL}+|\$.*{EOL})      { yylineno += count_ln(yytext, yyleng); return DELIM_EOL; }
[ \t]+                  { }
.                       {
							cerr << "[Error] lexical error, unrecognized sequence '" << yytext << "' at line "
								 << yylloc.first_line << " (column " << yylloc.first_column
								 << ")" << endl;
							error_occurred = true; 
						}

%%

int count_ln(const char* str, size_t length)
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

int compute_end_column(int first_col, const char* token, size_t token_len)
{
	int col = first_col + 1;

	for(size_t i = 0; i < token_len; ++i)
		switch(count_ln(token + i, i < token_len ? 2 : 1)) // count only one char if the end of the string is reached
		{
			case 0: col++; break;
			case 2: ++i; // skip the two newline
			case 1: col = 1; // reset the column number to 0 as a newline is met
							// ok if the newline is at the second position because col will be reset anyway
		}

	return col;
}

void update_yylloc()
{
	yylloc.first_line = yylineno;  // line at which the token begins
	yylloc.last_line = yylineno + count_ln(yytext, yyleng);  // line at which the token ends
	yylloc.first_column = yylloc.last_column;  // column at which the token begins
	yylloc.last_column = compute_end_column(yylloc.first_column, yytext, yyleng);
}