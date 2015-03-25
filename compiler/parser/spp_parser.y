%{
	#include <cstdio>
	#include <iostream>
	#include <string>
	using namespace std;

	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" FILE* yyin;

	void yyerror(const char*);
%}


%union{
	int vint;
	double vdouble;
	std::string* vstring;
}

/* Keywords tokens */
%token KEYWORD_MAKI "maki"

/* Operators */
%token OP_ASSIGN "="

/* Delimiters */
%token DELIM_EOL /* End of line */

/* Constant value */
%token <vint>    CONST_INT
%token <vdouble> CONST_FLOAT
%token <vstring> CONST_STRING

/* Identifier */
%token <vstring> IDENTIFIER

%% 

program:
  %empty
| line program
;

line:
  DELIM_EOL
| KEYWORD_MAKI decl_var DELIM_EOL 
;

decl_var:
  IDENTIFIER OP_ASSIGN CONST_INT    { cout << "Assign the integer " << $3 << " to the variable " << *$1 << endl; }
| IDENTIFIER OP_ASSIGN CONST_FLOAT  { cout << "Assign the float " << $3 << " to the variable " << *$1 << endl; }
| IDENTIFIER OP_ASSIGN CONST_STRING { cout << "Assign the string " << *$3 << " to the variable " << *$1 << endl; };
;
%%

int main(int, char**) 
{
	// // open a file handle to a particular file:
	// FILE *myfile = fopen("in.snazzle", "r");
	// // make sure it is valid:
	// if (!myfile) {
	// 	cout << "I can't open a.snazzle.file!" << endl;
	// 	return -1;
	// }
	// // set flex to read from it instead of defaulting to STDIN:
	// yyin = myfile;
	
	// // parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cerr << "Error : " << s << endl;
	exit(-1);
}
