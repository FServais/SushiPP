%{
	#include <cstdio>
	#include <iostream>
	using namespace std;

	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" FILE* yyin;

	void yyerror(const char*);
%}


%union{
	int vint;
	double vdouble;
	string vstring;
}

/* Keywords tokens */
%token KEYWORD_MAKI "maki"

%token OP_ASSIGN "="
%token DELIM_EOL /* End of line */

/* Constant value */
%token <vint>    CONST_INT
%token <vdouble> CONST_FLOAT
%token <vstring> CONST_STRING

/* Identifier */
%token <vstring> IDENTIFIER

/* Type of the non terminal symbols */
%type <vstring> decl_var

%% 

program:
  %empty
| KEYWORD_MAKI decl_var DELIM_EOL  { cout << "Declare variable : " << $2 << endl;} 

decl_var:
  IDENTIFIER OP_ASSIGN CONST_INT    { cout << "Assign the integer " << $3 << " to the variable " << $1 << endl; $$ = $1; }
| IDENTIFIER OP_ASSIGN CONST_FLOAT  { cout << "Assign the float " << $3 << " to the variable " << $1 << endl; $$ = $1; }
| IDENTIFIER OP_ASSIGN CONST_STRING { cout << "Assign the string " << $3 << " to the variable " << $1 << endl; $$ = $1; };

%%

int main(int, char**) 
{
	// open a file handle to a particular file:
	FILE *myfile = fopen("in.snazzle", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	exit(-1);
}
