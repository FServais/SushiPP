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

%token TYPE_INT "int"
%token TYPE_STRING "string"
%token TYPE_ARRAY "array"
%token TYPE_LIST "list"
%token TYPE_TUPLE "tuple"

/* Operators */
%token OP_ASSIGN "="
%token OP_ASSIGN_FUNC ":"

%token OP_COMP_LT '<'
%token OP_COMP_GT '>'

/* Delimiters */
%token DELIM_EOL /* End of line */
%token DELIM_EOS ";;" /* End of scope */
%token DELIM_COMMA ',' 


/* Constant value */
%token <vint>    CONST_INT
%token <vdouble> CONST_FLOAT
%token <vstring> CONST_STRING

/* Identifier */
%token <vstring> IDENTIFIER

/**********************/
/* Non-terminal types */
/**********************/
%type <vstring> type
%type <vstring> param
%type <vstring> param-list

%% 

program:
  %empty
| program_item program
;

program_item:
  declaration
;

/* Declaration */
declaration:
  KEYWORD_MAKI decl-func DELIM_EOL
| KEYWORD_MAKI decl-vars DELIM_EOL
;

/* variable declaration */
decl-vars:
  decl-var
| decl-var DELIM_COMMA decl-vars
| decl-var DELIM_COMMA DELIM_EOL decl-vars
;

decl-var:
  IDENTIFIER OP_ASSIGN CONST_INT    { cout << "Assign the integer " << $3 << " to the variable " << *$1 << endl; }
| IDENTIFIER OP_ASSIGN CONST_FLOAT  { cout << "Assign the float " << $3 << " to the variable " << *$1 << endl; }
| IDENTIFIER OP_ASSIGN CONST_STRING { cout << "Assign the string " << *$3 << " to the variable " << *$1 << endl; };
;

/************************/
/* function declaration */
/************************/
decl-func:
  IDENTIFIER param-list OP_ASSIGN_FUNC func-body DELIM_EOS			 { cout << "Declare a function " << (*$1) << " with parameters : " << (*$2) << endl; }
| IDENTIFIER param-list OP_ASSIGN_FUNC DELIM_EOL func-body DELIM_EOS { cout << "Declare a function " << (*$1) << " (with eol) with parameters : " << (*$2) << endl; }
;

/* function's parameters list */
param-list:
  %empty           { $$ = new string(""); }
| param param-list { $$ = new string((*$1) + string(",") + (*$2)); }
;

param:
  IDENTIFIER 			  				{ $$ = new string(string("'") + (*$1) + string("'")); }
| IDENTIFIER OP_COMP_LT type OP_COMP_GT { $$ = new string(string("'") + (*$1) + string("' of type ") + (*$3));  }
;

func-body:
	program_item program
;

/* types */
type: 
  TYPE_TUPLE  { $$ = new string("tuple"); }
| TYPE_LIST   { $$ = new string("list"); }
| TYPE_ARRAY  { $$ = new string("array"); }
| TYPE_INT    { $$ = new string("integer"); }
| TYPE_STRING { $$ = new string("string"); }
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
