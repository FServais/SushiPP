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
	char vchar;
}

/* Keywords tokens */
%token KEYWORD_MAKI "maki"
%token KEYWORD_TO "to"
%token KEYWORD_SOY "soy"
%token KEYWORD_NORI "nori"
%token KEYWORD_MENU "menu"
%token KEYWORD_FOR "for"
%token KEYWORD_ROLL "roll"
%token KEYWORD_BREAK "break"
%token KEYWORD_CONTINUE "continue"
%token KEYWORD_FOREACH "foreach"
%token KEYWORD_AS "as"

%token TYPE_INT "int"
%token TYPE_FLOAT "float"
%token TYPE_BOOL "bool"
%token TYPE_CHAR "char"
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
%token DELIM_ARRAY_BEG "#["
%token DELIM_ARRAY_END "]#"
%token DELIM_ARROW "->"
%token ','
%token '('
%token ')'
%token '['
%token ']'
%token '{'
%token '}'
%token '_'

/* Constant value */
%token <vint>    CONST_INT
%token <vdouble> CONST_FLOAT
%token <vstring> CONST_STRING
%token <vbool>   CONST_BOOL
%token <vchar>   CONST_CHAR

/* Identifier */
%token <vstring> IDENTIFIER

/**********************/
/* Non-terminal types */
/**********************/
%type <vstring> param
%type <vstring> param-list
%type <vint>    arg-list
%type <vint>    arg-list-eol
%type <vint>    expression-list

%start program

%% 

/*************************/
/* Program general rules */
/*************************/
program:
  %empty
| scope-body
;

/* Scope containing sushi++ code */ 
scope: scope-body ;;

scope-body:
  program-element 
| program-element DELIM_EOL
| program-element DELIM_EOL scope-body
| DELIM_EOL scope-body
;

program-element:
  statement
| modifying-expression
| declaration
;

/***************/
/* Declaration */
/***************/
declaration:
  KEYWORD_MAKI decl-func
| KEYWORD_MAKI decl-vars
;

/* variable declaration */
decl-vars:
  decl-var
| decl-var ',' decl-vars
| decl-var ',' DELIM_EOL decl-vars
;

decl-var:
  IDENTIFIER 				 { cout << endl << "Declare the variable " << *$1 << endl; } 
| IDENTIFIER '=' expression  { cout << endl << "Assign an expression to the variable " << *$1 << endl; }
;

/* function declaration */
decl-func:
  IDENTIFIER param-list ':' scope DELIM_EOS	{ cout << endl << "Declare a function " << (*$1) << " with parameters : " << (*$2) << endl; }
;

/* function's parameters list */
param-list:
  %empty           { $$ = new string(""); }
| param param-list { $$ = new string((*$1) + string(",") + (*$2)); }
;

param:
  IDENTIFIER 			  		{ $$ = new string(string("'") + (*$1) + string("'")); }
| IDENTIFIER '<' IDENTIFIER '>' { $$ = new string(string("'") + (*$1) + string("' of type ") + (*$3)); }
;

/******************/
/* Function calls */
/******************/

func-call: 
  IDENTIFIER arg-list { cout << endl << "Function call of '" << (*$1) << "' with " << $2 << " parameter(s)" << endl;; }
;

arg-list: 
  %empty 			 { $$ = 0; }
| argument arg-list  { $$ = $2 + 1; }
;

argument: 
  IDENTIFIER 
| constant 
| '(' expression ')' 
| soy-expression 
| datastructure-access 
| braced-func-call;

braced-func-call: '(' func-call-eol ')';

/* 
 * The func call eol is introduced to allow programmers to write 
 * the arguments on several lines. To prevent ambiguities, this notation 
 * is only allowed if the initial function call is braced (braced-func-call).
 */
func-call-eol: 
  IDENTIFIER arg-list-eol { cout << endl << "Braced function call of '" << (*$1) << "' with " << $2 << " parameter(s)" << endl; };
| soy-expression arg-list-eol
;

arg-list-eol:
  argument { $$ = 1; }
| argument arg-list-eol { $$ = 1 + $2; }
| argument DELIM_EOL arg-list-eol { $$ = 1 + $3; }
;

/* Anonymous functions */
soy-expression: '(' soy-func ')';
soy-func: KEYWORD_SOY param-list ':' scope; 

/***************/
/* Expressions */
/***************/
expression:
  constant
| '(' expression ')'
| IDENTIFIER
| datastructure
| soy-expression 
| datastructure-access
| incr-expression 
| assignment
| braced-func-call
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
;

incr-expression:
  OP_ARITH_INCR assignable-expression %prec PREFIX_INCR
| OP_ARITH_DECR assignable-expression %prec PREFIX_DECR
| assignable-expression OP_ARITH_INCR %prec SUFFIX_INCR
| assignable-expression OP_ARITH_DECR %prec SUFFIX_DECR
;

assignment:
  assignable-expression '=' expression
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

/* A modifying expression is an expression that could bring about
 * a state modification (global variable, IO,...). These are the only 
 * expressions that can be as such in a program (see program-element rule)
 */
modifying-expression: 
  assignment 
| incr-expression 
| braced-func-call
| func-call
;

/* An assignable expression is an expression that represents a 
 * memory storage that can thus be assigned a new value
 */
assignable-expression: 
  IDENTIFIER 
| datastructure-access;

datastructure-access: IDENTIFIER '[' expression ']';

/* Comma-separated expression list */
expression-list: 
  expression { $$ = 1; }
| expression ',' expression-list { $$ = 1 + $3; }
;

/*************/
/* Constants */
/*************/
constant: 
  CONST_INT
| CONST_FLOAT
| CONST_STRING
| CONST_BOOL
| CONST_CHAR
;

/******************/
/* Datastructures */
/******************/
datastructure: 
  array 
| list 
| tuple 
| make-sequence
;

array: 
  DELIM_ARRAY_BEG DELIM_ARRAY_END { cout << "Empty array" << endl; } /* empty array */ 
| DELIM_ARRAY_BEG expression-list DELIM_ARRAY_END { cout << "Array of " << $2 << " element(s)" << endl; }
;

list: 
  '{' '}' { cout << "Empty list" << endl; } /* empty list */
| '{' expression-list '}'  { cout << "List of " << $2 << " element(s)" << endl; }
;

tuple:
  DELIM_TUPLE_BEG DELIM_TUPLE_END { cout << "Empty tuple" << endl; } /* empty tuple */ 
| DELIM_TUPLE_BEG expression-list DELIM_TUPLE_END	{ cout << "Tuple of " << $2 << " element(s)" << endl; }
;

/* The make sequence list allows to create datastructures
 * filled with increasing values (lists or arrays)
 */
make-sequence: make-sequence-list | make-sequence-array;
make-sequence-list: '{' seq-expression '}';
make-sequence-array: DELIM_ARRAY_BEG seq-expression DELIM_ARRAY_END;

seq-expression: expression KEYWORD_TO expression;

/**************/
/* Statements */
/**************/
statement: 
  return 
| menu
| loop 
| KEYWORD_CONTINUE
| KEYWORD_BREAK
;

/* Return */
return: KEYWORD_NORI expression ;

/* Switch */
menu: KEYWORD_MENU expression DELIM_EOL menu-body DELIM_EOS;
menu-body: 
  menu-def DELIM_EOL 
| menu-case DELIM_EOL 
| menu-case DELIM_EOL menu-body
;

menu-case: expression DELIM_ARROW scope DELIM_EOS;
menu-def: '_' DELIM_ARROW scope DELIM_EOS;

/* Loop */
loop : 
  foreach 
| for
| roll ;

/* The roll loop is actually a while loop
 * The expression should be interpretable as a boolean value
 */
roll : KEYWORD_ROLL expression DELIM_EOL scope DELIM_EOS ;

/* The foreach loop iterates over a list/array expression (so the expression part should be 
 * interpretable as a list/array)
 */
foreach: KEYWORD_FOREACH expression KEYWORD_AS IDENTIFIER DELIM_EOL scope DELIM_EOS;

/* The for loop iterates until a condition becomes false
 * The initializer part can be empty or contain an assignment (if the variable does not exist
 * it is created).
 * The expression part shoulb be interpretable as a boolean.
 * The modifying-expression part should contain any update code  for updating some variables used
 * for iterating (or contain nothing)
 */
for: KEYWORD_FOR for-initializer ',' expression ',' for-update DELIM_EOL scope DELIM_EOS;

for-initializer: 
  %empty
| assignment
;

for-update:
  %empty
| modifying-expression
;

%%

int main(int, char**) 
{
	// // open a file handle to a particular file:
	// FILE *myfile = fopen("in.snazzle", "r");
	// // make sure it is valid:
	// if (!myfile) {
	// 	cout << endl << "I can't open a.snazzle.file!" << endl;
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
