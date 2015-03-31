%{
	#include <iostream>
	#include <string>
	#include <sstream>

	/** AST includes*/
	#include "../ast/AbstractSyntaxTree.hpp"
	#include "../ast/nodes/ASTNode.hpp"
	#include "../ast/nodes/NodeLocation.hpp"

	#include "../ast/nodes/tokens/Token.hpp"
	#include "../ast/nodes/tokens/Operator.hpp"
	#include "../ast/nodes/tokens/ConstantToken.hpp"
	#include "../ast/nodes/tokens/Delimiter.hpp"
	#include "../ast/nodes/tokens/Keyword.hpp"

	#include "../ast/nodes/nonterminal/NonTerminal.hpp"
	#include "../ast/nodes/nonterminal/NT_Constant.hpp"
	#include "../ast/nodes/nonterminal/NT_Datastructure.hpp"
	#include "../ast/nodes/nonterminal/NT_Declaration.hpp"
	#include "../ast/nodes/nonterminal/NT_Expression.hpp"
	#include "../ast/nodes/nonterminal/NT_FunctionCall.hpp"
	#include "../ast/nodes/nonterminal/NT_Program.hpp"
	#include "../ast/nodes/nonterminal/NT_Statement.hpp"

	using namespace std;
	using namespace ast;

	extern "C" int yylex();

	static void yyerror(const char*);
	static string curr_line_row();

	// will store a pointer to the abstract syntax tree constructed by the parser
	extern AbstractSyntaxTree* syntax_tree;
%}

%define parse.error verbose
%locations

%union
{
	string* vstring;
	ASTNode* vnode;
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
%token KEYWORD_IF "if"
%token KEYWORD_ELSEIF "elseif"
%token KEYWORD_ELSE "else"

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
%token <vstring> CONST_STRING CONST_INT CONST_FLOAT CONST_BOOL CONST_CHAR

/* Identifier */
%token <vstring> IDENTIFIER

/* Non terminal types */
%type <vnode> program scope-body program-element scope
%type <vnode> declaration decl-vars decl-var decl-func param param-list
%type <vnode> func-call arg-list argument braced-func-call func-call-eol arg-list-eol soy-expression soy-func
%type <vnode> expression incr-expression assignment modifying-expression assignable-expression datastructure-access expression-list
%type <vnode> constant
%type <vnode> datastructure array list tuple make-sequence make-sequence-list make-sequence-array seq-expression
%type <vnode> statement return menu menu-body menu-case menu-def loop roll foreach for for-initializer for-update conditional elseif

%start program

%%

/*************************/
/* Program general rules */
/*************************/
program:
  %empty 		{ syntax_tree = new AbstractSyntaxTree(); }
| scope-body	{ syntax_tree = new AbstractSyntaxTree($$); }
;

/* Scope containing sushi++ code */
scope: 
  scope-body 
	{ 
		$$ = new Scope();
		$$->add_child($1); 
	}
;

scope-body:
  program-element 
	{
		$$ = new ScopeBody();
		$$->add_child($1);
	}
| program-element DELIM_EOL
	{
		$$ = new ScopeBody();
		$$->add_child($1);
		$$->add_child(new DelimEol);
	}
| program-element DELIM_EOL scope-body
	{
		$$ = new ScopeBody();
		$$->add_child($1);
		$$->add_child(new DelimEol);
		$$->add_child($3);
	}
| DELIM_EOL scope-body
	{
		$$ = new ScopeBody();
		$$->add_child(new DelimEol);
		$$->add_child($2);
	}
;

program-element:
  statement
	{
		$$ = new ProgramElement();
		$$->add_child($1);
	}
| modifying-expression
	{
		$$ = new ProgramElement();
		$$->add_child($1);
	}
| declaration
	{
		$$ = new ProgramElement();
		$$->add_child($1);
	}
;

/***************/
/* Declaration */
/***************/
declaration:
  KEYWORD_MAKI decl-func
  	{
  		$$ = new Declaration();
  		$$->add_child(new K_Maki);
  		$$->add_child($2);
  	}
| KEYWORD_MAKI decl-vars
	{
		$$ = new Declaration();
		$$->add_child(new K_Maki);
		$$->add_child($2);
	}
;

/* variable declaration */
decl-vars:
  decl-var
	{
		$$ = new DeclVars();
		$$->add_child($1);
	}
| decl-var ',' decl-vars
	{
		$$ = new DeclVars();
		$$->add_child($1);
		$$->add_child(new Virg);
		$$->add_child($3);
	}
| decl-var ',' DELIM_EOL decl-vars
	{
		$$ = new DeclVars();
		$$->add_child($1);
		$$->add_child(new Virg);
		$$->add_child(new DelimEol);
		$$->add_child($3);
	}
;

decl-var:
  IDENTIFIER
	{
		$$ = new DeclVar();
		$$->add_child(new Identifier($1));
	}
| IDENTIFIER '=' expression
	{
		$$ = new DeclVar();
		$$->add_child(new Identifier($1));
		$$->add_child(new Op_Assign);
		$$->add_child($3);
	}
| error '=' expression
	{
		//cerr << " Details : a valid identifier name was exptected as left-hand-side item." << endl;
		yyerrok;
	}
| IDENTIFIER '=' error
	{
		//cerr << " Details : a valid expression was exptected as right-hand-side item." << endl;
		yyerrok;
	}
;

/* function declaration */
decl-func:
  IDENTIFIER param-list ':' scope DELIM_EOS
	{
		$$ = new DeclFunc();
		$$->add_child(new Identifier($1));
		$$->add_child($2);
		$$->add_child(new Op_AssignFunc);
		$$->add_child($4);
		$$->add_child(new DelimEos);
	}
;

/* function's parameters list */
param-list:
  %empty
| param param-list
	{
		$$ = new DeclFunc();
		$$->add_child(new Identifier($1));
		$$->add_child($2);
		$$->add_child(new Op_AssignFunc);
		$$->add_child($4);
		$$->add_child(new DelimEos);		
	}
;

param:
  IDENTIFIER
| IDENTIFIER '<' IDENTIFIER '>'
;

/******************/
/* Function calls */
/******************/

func-call:
  IDENTIFIER arg-list
;

arg-list:
  %empty
| argument arg-list
;

argument:
  IDENTIFIER
| constant
| '(' expression ')'
| soy-expression
| datastructure-access
| braced-func-call
| error
	{
		/*cerr << " Details : the argument is invalid. It should be either " << endl
			 << "    a constant, a braced expression, an anonymous soy function, " << endl
			 << "    a datastructure access or a variable." << endl; */
		yyclearin;
	}
;

braced-func-call: '(' func-call-eol ')';

/*
 * The func call eol is introduced to allow programmers to write
 * the arguments on several lines. To prevent ambiguities, this notation
 * is only allowed if the initial function call is braced (braced-func-call).
 */
func-call-eol:
  IDENTIFIER arg-list-eol
| soy-expression arg-list-eol
| error arg-list-eol
	{
		//cerr << " Details : either an identifier or a soy anonymous function was expected" << endl;
		yyclearin;
	}
;

arg-list-eol:
  argument
| argument arg-list-eol
| argument DELIM_EOL arg-list-eol
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
  expression
| expression ',' expression-list
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
  DELIM_ARRAY_BEG DELIM_ARRAY_END /* empty array */
| DELIM_ARRAY_BEG expression-list DELIM_ARRAY_END
;

list:
  '{' '}' /* empty list */
| '{' expression-list '}'
;

tuple:
  DELIM_TUPLE_BEG DELIM_TUPLE_END /* empty tuple */
| DELIM_TUPLE_BEG expression-list DELIM_TUPLE_END
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
| conditional
;

/* Return */
return:
  KEYWORD_NORI
| KEYWORD_NORI expression
;

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

/* Conditionnal */
conditional:
  KEYWORD_IF expression DELIM_EOL scope-body DELIM_EOS
| KEYWORD_IF expression DELIM_EOL scope-body KEYWORD_ELSE scope-body DELIM_EOS
| KEYWORD_IF expression DELIM_EOL scope-body elseif DELIM_EOS
| KEYWORD_IF expression DELIM_EOL scope-body elseif KEYWORD_ELSE scope-body DELIM_EOS
;

elseif:
  KEYWORD_ELSEIF expression DELIM_EOL scope-body
| KEYWORD_ELSEIF expression DELIM_EOL scope-body elseif;

%%

static void yyerror(const char *s)
{
	cerr << "[Error] " << s << curr_line_row() << endl;
}

static string curr_line_row()
{
	stringstream ss;
	ss << " at line " << yylloc.first_line << " (column " << yylloc.first_column << ")";
	return ss.str();
}