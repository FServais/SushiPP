%{
	int numLines = 0;
%}
%%
maki 				 { printf("<T_KEYWORD_MAKI, %d> ", numLines); }
nori 				 { printf("<T_KEYWORD_NORI, %d> ", numLines); }
for 				 { printf("<T_KEYWORD_FOR, %d> ", numLines); }
roll 				 { printf("<T_KEYWORD_ROLL, %d> ", numLines); }
mat  				 { printf("<T_KEYWORD_MAT, %d> ", numLines); }
if 					 { printf("<T_KEYWORD_IF, %d> ", numLines); }
elseif 				 { printf("<T_KEYWORD_ELSEIF, %d> ", numLines); }
else 				 { printf("<T_KEYWORD_ELSE, %d> ", numLines); }
to 					 { printf("<T_KEYWORD_TO, %d> ", numLines); }
soy 				 { printf("<T_KEYWORD_SOY, %d> ", numLines); }			
menu 				 { printf("<T_KEYWORD_MENU, %d> ", numLines); }			
int 				 { printf("<T_KEYWORD_INT, %d> ", numLines); }			
float 				 { printf("<T_KEYWORD_FLOAT, %d> ", numLines); }			
tuple 				 { printf("<T_KEYWORD_TUPLE, %d> ", numLines); }			
array 				 { printf("<T_KEYWORD_ARRAY, %d> ", numLines); }			
list 				 { printf("<T_KEYWORD_LIST, %d> ", numLines); }			
str 				 { printf("<T_KEYWORD_STR, %d> ", numLines); }			
continue 			 { printf("<T_KEYWORD_CONTINUE, %d> ", numLines); }
break 				 { printf("<T_KEYWORD_BREAK, %d> ", numLines); }
default 			 { printf("<T_KEYWORD_DEFAULT, %d> ", numLines); }
[a-zA-Z]][a-zA-Z-_]* { printf("<T_IDENTIFIER, %s, %d> ", yytext, numLines); }
[+-]?\d+			 { printf("<T_CONST_INT, %s, %d> ", yytext, numLines); }
[+-]?\d+\,\d+		 { printf("<T_CONST_FLOAT, %s, %d> ", yytext, numLines); }
(\|\|?|&&?|\^)		 { printf("<T_OPERATOR_LOGIC, %s, %d> ", yytext, numLines); }
(<=?|>=?|==)		 { printf("<T_OPERATR_COMP, %s, %d> ", yytext, numLines); }
\+\+				 { printf("<T_OPERATOR_INCR, %d> ", numLines); }
--					 { printf("<T_OPERATOR_DECR, %d> ", numLines); }
!					 { printf("<T_OPERATOR_NEG, %d> ", numLines); }
\.					 { printf("<T_OPERATOR_CONCAT, %d> ", numLines ); }
,					 { printf("<T_DELIM_COMMA, %d> ", numLines); }
(\r|\n|\r\n)+		 { printf("<T_DELIM_EOL, %d> \n", numLines); numLines += count_ln(yytext, yyleng); }
;;					 { printf("<T_DELIM_EOS, %d> ", numLines); }
:					 { printf("<T_OPERATOR_ASSIGN_FUNC, %d> ", numLines); }
= 					 { printf("<T_OPERATOR_ASSIGN_VAR, %d> ", numLines); }
\(					 { printf("<T_DELIM_PAREN_BEG, %d> ", numLines); }
\) 					 { printf("<T_DELIM_PAREN_END, %d> ", numLines); }
\ {					 { printf("<T_DELIM_BRACE_BEG, %d> ", numLines); }
\}					 { printf("<T_DELIM_BRACE_END, %d> ", numLines); }
\[					 { printf("<T_DELIM_BRACK_BEG, %d> ", numLines); }
\]					 { printf("<T_DELIM_BRACK_END, %d> ", numLines); }
-\>					 { printf("<T_DELIM_ARROW, %d> ", numLines); }
\"[^\"]\"			 { printf("<T_CONST_STRING, %s> ", yytext); }
\s+ 				 { printf(" "); }

%%

int main()
{
	yylex();
}

int count_ln(char* s, int length)
{
	int cnt_lf = 0, cnt_cr = 0;

	for(int i = 0; i < length; ++i)
		switch(s[i])
		{
			case '\n': 
				cnt_lf++; break;
			case '\r':
				cnt_cr++; break;
		}

	if(cnt_lf != 0 && cnt_cr != 0) // windows-link
		return cnt_lf;
	else if(cnt_cr != 0) // mac before version 9
		return cnt_cr;
	else // MAC OS X, Unix
		return cnt_lf;
}