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
	bool vbool;
	int vint;
	double vdouble;
	std::string* vstring;
}

/* Keywords tokens */
%token KEYWORD_MAKI "maki"
%token KEYWORD_TO "to"
%token KEYWORD_SOY "soy"

%token TYPE_INT "int"
%token TYPE_STRING "string"
%token TYPE_ARRAY "array"
%token TYPE_LIST "list"
%token TYPE_TUPLE "tuple"

/* Operators */
%token '='
%token ':'

%token OP_ARITH_INCR "++"
%token OP_ARITH_DECR "--"
%token OP_ARITH_EXPO "**"

%token OP_LOGIC_OR "||"
%token OP_LOGIC_AND "&&"

%token OP_COMP_LEQ "<="
%token OP_COMP_GEQ ">="
%token OP_COMP_EQ  "=="
%token OP_COMP_NEQ "!="

%token OP_RSHIFT ">>"
%token OP_LSHIFT "<<"

%token OP_ASSIGN_PLUS "+="
%token OP_ASSIGN_MINUS "-="
%token OP_ASSIGN_MULT "*="
%token OP_ASSIGN_DIV "/="
%token OP_ASSIGN_EXPO "**="
%token OP_ASSIGN_MOD "%="
%token OP_ASSIGN_OR "|="
%token OP_ASSIGN_AND "&="
%token OP_ASSIGN_XOR "^="
%token OP_ASSIGN_CONCAT ".="

/* Operator precedence */
%right '=' OP_ASSIGN_CONCAT OP_ASSIGN_XOR OP_ASSIGN_AND OP_ASSIGN_OR OP_ASSIGN_MOD OP_ASSIGN_EXPO OP_ASSIGN_DIV OP_ASSIGN_MULT OP_ASSIGN_MINUS OP_ASSIGN_PLUS
%left OP_LOGIC_OR
%left OP_LOGIC_AND
%left '|'
%left '^'
%left '&'
%left OP_COMP_EQ OP_COMP_NEQ
%left '<' '>' OP_COMP_LEQ OP_COMP_GEQ
%left OP_LSHIFT OP_RSHIFT
%left '+' '-'
%left '*' '/' '%'
%precedence '~' '!'
%precedence UNARY_MINUS 
%right OP_ARITH_EXPO '.'
%precedence PREFIX_INCR PREFIX_DECR
%precedence SUFFIX_INCR SUFFIX_DECR

/* Delimiters */
%token DELIM_EOL /* End of line */
%token DELIM_EOS ";;" /* End of scope */
%token DELIM_TUPLE_BEG "#{"
%token DELIM_TUPLE_END "}#"
%token ','
%token '('
%token ')'
%token '['
%token ']'
%token '{'
%token '}'

/* Constant value */
%token <vint>    CONST_INT
%token <vdouble> CONST_FLOAT
%token <vstring> CONST_STRING
%token <vbool>   CONST_BOOL

/* Identifier */
%token <vstring> IDENTIFIER

/**********************/
/* Non-terminal types */
/**********************/
%type <vstring> type
%type <vstring> param
%type <vstring> param-list

%start program

%% 

program:
  %empty
| program_item program
;

program_item:
  declaration
| expression DELIM_EOL
;

/* Declaration */
declaration:
  KEYWORD_MAKI decl-func DELIM_EOL
| KEYWORD_MAKI decl-vars DELIM_EOL
;

/* variable declaration */
decl-vars:
  decl-var
| decl-var ',' decl-vars
| decl-var ',' DELIM_EOL decl-vars
;

decl-var:
  IDENTIFIER '=' expression  { cout << "Assign an expression to the variable " << *$1 << endl; }
;

/************************/
/* function declaration */
/************************/
decl-func:
  IDENTIFIER param-list ':' func-body DELIM_EOS			 { cout << "Declare a function " << (*$1) << " with parameters : " << (*$2) << endl; }
| IDENTIFIER param-list ':' DELIM_EOL func-body DELIM_EOS { cout << "Declare a function " << (*$1) << " (with eol) with parameters : " << (*$2) << endl; }
;

/* function's parameters list */
param-list:
  %empty           { $$ = new string(""); }
| param param-list { $$ = new string((*$1) + string(",") + (*$2)); }
;

param:
  IDENTIFIER 			  				{ $$ = new string(string("'") + (*$1) + string("'")); }
| IDENTIFIER '<' type '>' { $$ = new string(string("'") + (*$1) + string("' of type ") + (*$3));  }
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

/***************/
/* Expressions */
/***************/
expression:
  constant
| braced-expression 
| IDENTIFIER
| datastructure
| soy-expression 
/*| braced-func-call */
| datastructure-access
| expression '+' expression 
| expression '-' expression 
| expression '*' expression
| expression '/' expression
| expression '%' expression
| expression OP_ARITH_EXPO expression
| '-' expression %prec UNARY_MINUS
| expression '|' expression
| expression '&' expression
| expression '^' expression
| '~' expression
| expression OP_LOGIC_OR expression
| expression OP_LOGIC_AND expression
| '!' expression 
| expression '<' expression 
| expression '>' expression
| expression OP_COMP_LEQ expression
| expression OP_COMP_GEQ expression
| expression OP_COMP_EQ  expression
| expression OP_COMP_NEQ expression 
| expression OP_LSHIFT expression
| expression OP_RSHIFT expression 
| expression '.' expression 
| OP_ARITH_INCR assignable-expression %prec PREFIX_INCR
| OP_ARITH_DECR assignable-expression %prec PREFIX_DECR
| assignable-expression OP_ARITH_INCR %prec SUFFIX_INCR
| assignable-expression OP_ARITH_DECR %prec SUFFIX_DECR
| assignable-expression '=' expression
| assignable-expression OP_ASSIGN_PLUS expression
| assignable-expression OP_ASSIGN_MINUS expression
| assignable-expression OP_ASSIGN_MULT expression
| assignable-expression OP_ASSIGN_DIV expression
| assignable-expression OP_ASSIGN_EXPO expression
| assignable-expression OP_ASSIGN_MOD expression
| assignable-expression OP_ASSIGN_AND expression
| assignable-expression OP_ASSIGN_OR expression
| assignable-expression OP_ASSIGN_XOR expression
| assignable-expression OP_ASSIGN_CONCAT expression
;

braced-expression: '(' expression ')';

assignable-expression: IDENTIFIER | datastructure-access;

datastructure-access: IDENTIFIER '[' expression ']';

expression-list: /* comma separeted list of expressions */
  expression
| expression ',' expression-list
;

constant: 
  CONST_INT
| CONST_FLOAT
| CONST_STRING
| CONST_BOOL
; 

/* datastructure */
datastructure: 
  array 
| list 
| tuple 
| make-sequence
;

array: 
  '[' ']' /* empty array */
| '[' expression-list ']'
;

list: 
  '{' '}' /* empty list */
| '{' expression-list '}'
;

tuple:
  DELIM_TUPLE_BEG DELIM_TUPLE_END /* empty tuple */
| DELIM_TUPLE_BEG expression-list DELIM_TUPLE_END
;

/* sequence generator */
make-sequence: make-sequence-list | make-sequence-array;
make-sequence-list: '{' seq-expression '}';
make-sequence-array: '[' seq-expression ']';

seq-expression: expression KEYWORD_TO expression;

/* Soy anonymous functions */
soy-expression: '(' soy-func ')';
soy-func: KEYWORD_SOY param-list ':' func-body; 


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
