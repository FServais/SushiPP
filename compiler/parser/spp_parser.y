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
  %empty 		{ syntax_tree = new AbstractSyntaxTree; }
| scope-body	{ syntax_tree = new AbstractSyntaxTree($$); }
;

/* Scope containing sushi++ code */
scope: 
  scope-body 
	{ 
		$$ = new Scope;
		$$->add_child($1); 
	}
;

scope-body:
  program-element 
	{
		$$ = new ScopeBody;
		$$->add_child($1);
	}
| program-element DELIM_EOL
	{
		$$ = new ScopeBody;
		$$->add_child($1);
		$$->add_child(new DelimEol);
	}
| program-element DELIM_EOL scope-body
	{
		$$ = new ScopeBody;
		$$->add_child($1);
		$$->add_child(new DelimEol);
		$$->add_child($3);
	}
| DELIM_EOL scope-body
	{
		$$ = new ScopeBody;
		$$->add_child(new DelimEol);
		$$->add_child($2);
	}
;

program-element:
  statement
	{
		$$ = new ProgramElement;
		$$->add_child($1);
	}
| modifying-expression
	{
		$$ = new ProgramElement;
		$$->add_child($1);
	}
| declaration
	{
		$$ = new ProgramElement;
		$$->add_child($1);
	}
;

/***************/
/* Declaration */
/***************/
declaration:
  KEYWORD_MAKI decl-func
	{
		$$ = new Declaration;
		$$->add_child(new K_Maki);
		$$->add_child($2);
	}
| KEYWORD_MAKI decl-vars
	{
		$$ = new Declaration;
		$$->add_child(new K_Maki);
		$$->add_child($2);
	}
;

/* variable declaration */
decl-vars:
  decl-var
	{
		$$ = new DeclVars;
		$$->add_child($1);
	}
| decl-var ',' decl-vars
	{
		$$ = new DeclVars;
		$$->add_child($1);
		$$->add_child(new Virg);
		$$->add_child($3);
	}
| decl-var ',' DELIM_EOL decl-vars
	{
		$$ = new DeclVars;
		$$->add_child($1);
		$$->add_child(new Virg);
		$$->add_child(new DelimEol);
		$$->add_child($3);
	}
;

decl-var:
  IDENTIFIER
	{
		$$ = new DeclVar;
		$$->add_child(new Identifier(*$1));
		
		// free semantic type of identifier
		delete $1;
	}
| IDENTIFIER '=' expression
	{
		$$ = new DeclVar;
		$$->add_child(new Identifier(*$1));
		$$->add_child(new Op_Assign);
		$$->add_child($3);

		// free semantic type of identifier
		delete $1;
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
		$$ = new DeclFunc;
		$$->add_child(new Identifier(*$1));
		$$->add_child($2);
		$$->add_child(new Op_AssignFunc);
		$$->add_child($4);
		$$->add_child(new DelimEos);

		// free semantic type of identifier
		delete $1;
	}
;

/* function's parameters list */
param-list:
  %empty
	{
		$$ = nullptr;
	}
| param param-list
	{
		$$ = new ParamList;
		$$->add_child($1);
		if($2 != nullptr)
			$$->add_child($2);
	}
;

param:
  IDENTIFIER
	{
		$$ = new Param;
		$$->add_child(new Identifier(*$1));
	}
| IDENTIFIER '<' IDENTIFIER '>'
	{
		$$ = new Param;
		$$->add_child(new Identifier(*$1));
		$$->add_child(new OpenChevr);
		$$->add_child(new Identifier(*$3)); /** Discriminate identifier for type */
		$$->add_child(new CloseChevr);

		// free semantic type of identifier
		delete $1;
		delete $3;
	}
;

/******************/
/* Function calls */
/******************/

func-call:
  IDENTIFIER arg-list
	{
		$$ = new Param;
		$$->add_child(new Identifier(*$1));
		$$->add_child($2);

		// free semantic type of identifier
		delete $1;
	}
;

arg-list:
  %empty
	{
		$$ = nullptr;
	}
| argument arg-list
	{
		$$ = new ArgList;
		$$->add_child($1);

		if($2 != nullptr)
			$$->add_child($2);
	}
;

argument:
  IDENTIFIER
	{
		$$ = new Argument;
		$$->add_child(new Identifier(*$1));

		// free semantic type of identifier
		delete $1;
	}
| constant
	{
		$$ = new Argument;
		$$->add_child($1);
	}
| '(' expression ')'
	{
		$$ = new Argument;
		$$->add_child(new OpenPar);
		$$->add_child($2);
		$$->add_child(new ClosePar);
	}
| soy-expression
	{
		$$ = new Argument;
		$$->add_child($1);
	}
| datastructure-access
	{
		$$ = new Argument;
		$$->add_child($1);
	}
| braced-func-call
	{
		$$ = new Argument;
		$$->add_child($1);
	}
| error
	{
		/*cerr << " Details : the argument is invalid. It should be either " << endl
			 << "    a constant, a braced expression, an anonymous soy function, " << endl
			 << "    a datastructure access or a variable." << endl; */
		yyclearin;
	}
;

braced-func-call: 
  '(' func-call-eol ')'
	{
		$$ = new BracedFuncCall;
		$$->add_child(new OpenPar);
		$$->add_child($2);
		$$->add_child(new ClosePar);
	}
;

/*
 * The func call eol is introduced to allow programmers to write
 * the arguments on several lines. To prevent ambiguities, this notation
 * is only allowed if the initial function call is braced (braced-func-call).
 */
func-call-eol:
  IDENTIFIER arg-list-eol
	{
		$$ = new FuncCallEol;
		$$->add_child($1);
	}
| soy-expression arg-list-eol
	{
		$$ = new FuncCallEol;
		$$->add_child($1);
		$$->add_child($2);
	}
| error arg-list-eol
	{
		//cerr << " Details : either an identifier or a soy anonymous function was expected" << endl;
		yyclearin;
	}
;

arg-list-eol:
  argument
	{
		$$ = new ArgListEol;
		$$->add_child($1);
	}
| argument arg-list-eol
	{
		$$ = new ArgListEol;
		$$->add_child($1);
		$$->add_child($2);
	}
| argument DELIM_EOL arg-list-eol
	{
		$$ = new ArgListEol;
		$$->add_child($1);
		$$->add_child(new DelimEol);
	}
;

/* Anonymous functions */
soy-expression: 
  '(' soy-func ')'
	{
		$$ = new SoyExpression;
		$$->add_child(new OpenPar);
		$$->add_child($2);
		$$->add_child(new ClosePar);
	}
;

soy-func: 
  KEYWORD_SOY param-list ':' scope
	{
		$$ = new SoyFunc;
		$$->add_child(new K_Soy);
		$$->add_child($2);
		$$->add_child(new Op_AssignFunc);
		$$->add_child($4);
	}
;

/***************/
/* Expressions */
/***************/
expression:
  constant
	{
		$$ = new Expression;
		$$->add_child($1);
	}
| '(' expression ')'
	{
		$$ = new Expression;
		$$->add_child(new OpenPar);
		$$->add_child($2);
		$$->add_child(new ClosePar);
	}
| IDENTIFIER
	{
		$$ = new Expression;
		$$->add_child(new Identifier(*$1));

		delete $1;
	}
| datastructure
	{
		$$ = new Expression;
		$$->add_child($1);
	}
| soy-expression
	{
		$$ = new Expression;
		$$->add_child($1);
	}
| datastructure-access
	{
		$$ = new Expression;
		$$->add_child($1);
	}
| incr-expression
	{
		$$ = new Expression;
		$$->add_child($1);
	}
| assignment
	{
		$$ = new Expression;
		$$->add_child($1);
	}
| braced-func-call
	{
		$$ = new Expression;
		$$->add_child($1);
	}
| expression '+' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_Plus);
		$$->add_child($3);
	}
| expression '-' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_Minus);
		$$->add_child($3);
	}
| expression '*' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_Mult);
		$$->add_child($3);
	}
| expression '/' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_Div);
		$$->add_child($3);
	}
| expression '%' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_Modulo);
		$$->add_child($3);
	}
| expression OP_ARITH_EXPO expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_Exponentiation);
		$$->add_child($3);
	}
| '-' expression %prec UNARY_MINUS
	{
		$$ = new Expression;
		$$->add_child(new Op_UnaryMinus);
		$$->add_child($2);
	}
| expression '|' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_BitwiseOr);
		$$->add_child($3);
	}
| expression '&' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_BitwiseAnd);
		$$->add_child($3);
	}
| expression '^' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_BitwiseXor);
		$$->add_child($3);
	}
| '~' expression
	{
		$$ = new Expression;
		$$->add_child(new Op_BitwiseNot);
		$$->add_child($2);
	}
| expression OP_LOGIC_OR expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_LogicalOr);
		$$->add_child($3);
	}
| expression OP_LOGIC_AND expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_LogicalAnd);
		$$->add_child($3);
	}
| '!' expression
	{
		$$ = new Expression;
		$$->add_child(new Op_LogicalNot);
		$$->add_child($2);
	}
| expression '<' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_CompLessThan);
		$$->add_child($3);
	}
| expression '>' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_CompGreaterThan);
		$$->add_child($3);
	}
| expression OP_COMP_LEQ expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_CompLessEqual);
		$$->add_child($3);
	}
| expression OP_COMP_GEQ expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_CompGreaterEqual);
		$$->add_child($3);
	}
| expression OP_COMP_EQ  expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_CompEqual);
		$$->add_child($3);
	}
| expression OP_COMP_NEQ expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_CompNotEqual);
		$$->add_child($3);
	}
| expression OP_LSHIFT expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_RightShift);
		$$->add_child($3);
	}
| expression OP_RSHIFT expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_LeftShift);
		$$->add_child($3);
	}
| expression '.' expression
	{
		$$ = new Expression;
		$$->add_child($1);
		$$->add_child(new Op_StringConcat);
		$$->add_child($3);
	}
;

incr-expression:
  OP_ARITH_INCR assignable-expression %prec PREFIX_INCR
	{
		$$ = new IncrExpression;
		$$->add_child(new Op_PrefixIncrement);
		$$->add_child($2);
	}
| OP_ARITH_DECR assignable-expression %prec PREFIX_DECR
	{
		$$ = new IncrExpression;
		$$->add_child(new Op_PrefixDecrement);
		$$->add_child($2);
	}
| assignable-expression OP_ARITH_INCR %prec SUFFIX_INCR
	{
		$$ = new IncrExpression;
		$$->add_child($1);
		$$->add_child(new Op_PostfixIncrement);
	}
| assignable-expression OP_ARITH_DECR %prec SUFFIX_DECR
	{
		$$ = new IncrExpression;
		$$->add_child($1);
		$$->add_child(new Op_PostfixDecrement);
	}
;

assignment:
  assignable-expression '=' expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_Assignment);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_PLUS expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignPlus);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_MINUS expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignMinus);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_MULT expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignMult);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_DIV expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignDiv);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_EXPO expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignExpo);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_MOD expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignMod);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_AND expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignAnd);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_OR expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignOr);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_XOR expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignXor);
		$$->add_child($3);
	}
| assignable-expression OP_ASSIGN_CONCAT expression
	{
		$$ = new Assignment;
		$$->add_child($1);
		$$->add_child(new Op_AssignConcat);
		$$->add_child($3);
	}
;

/* A modifying expression is an expression that could bring about
 * a state modification (global variable, IO,...). These are the only
 * expressions that can be as such in a program (see program-element rule)
 */
modifying-expression:
  assignment
  	{
		$$ = new ModifyingExpression;
		$$->add_child($1);
	}
| incr-expression
  	{
		$$ = new ModifyingExpression;
		$$->add_child($1);
	}
| braced-func-call
  	{
		$$ = new ModifyingExpression;
		$$->add_child($1);
	}
| func-call
  	{
		$$ = new ModifyingExpression;
		$$->add_child($1);
	}
;

/* An assignable expression is an expression that represents a
 * memory storage that can thus be assigned a new value
 */
assignable-expression:
  IDENTIFIER
    {
		$$ = new AssignableExpression;
		$$->add_child(new Identifier(*$1));

		delete $1;
	}
| datastructure-access
  	{
		$$ = new AssignableExpression;
		$$->add_child($1);
	}
;

datastructure-access: 
  IDENTIFIER '[' expression ']'
    {
		$$ = new DatastructureAccess;
		$$->add_child(new Identifier(*$1));
		$$->add_child(new OpenBrace);
		$$->add_child($3);
		$$->add_child(new ClosingBrace);

		delete $1;
	}
;

/* Comma-separated expression list */
expression-list:
  expression
	{
		$$ = new ExpressionList;
		$$->add_child($1);
	}
| expression ',' expression-list
	{
		$$ = new ExpressionList;
		$$->add_child($1);
		$$->add_child(new Virg);
		$$->add_child($3);
	}
;

/*************/
/* Constants */
/*************/
constant:
  CONST_INT
    {
		$$ = new Constant;
		$$->add_child(new Integer(*$1));
		
		delete $1;
	}
| CONST_FLOAT
    {
		$$ = new Constant;
		$$->add_child(new Float(*$1));
		
		delete $1;
	}
| CONST_STRING
    {
		$$ = new Constant;
		$$->add_child(new String(*$1));
		
		delete $1;
	}
| CONST_BOOL
    {
		$$ = new Constant;
		$$->add_child(new Bool(*$1));
		
		delete $1;
	}
| CONST_CHAR
    {
		$$ = new Constant;
		$$->add_child(new Character(*$1));
		
		delete $1;
	}
;

/******************/
/* Datastructures */
/******************/
datastructure:
  array
    {
		$$ = new Datastructure;
		$$->add_child($1);
	}
| list
    {
		$$ = new Datastructure;
		$$->add_child($1);
	}
| tuple
    {
		$$ = new Datastructure;
		$$->add_child($1);
	}
| make-sequence
    {
		$$ = new Datastructure;
		$$->add_child($1);
	}
;

array:
  DELIM_ARRAY_BEG DELIM_ARRAY_END /* empty array */
    {
		$$ = new Array;
		$$->add_child(new ArrayBeg);
		$$->add_child(new ArrayClose);
	}
| DELIM_ARRAY_BEG expression-list DELIM_ARRAY_END
    {
		$$ = new Array;
		$$->add_child(new ArrayBeg);
		$$->add_child($2);
		$$->add_child(new ArrayClose);
	}
;

list:
  '{' '}' /* empty list */
    {
		$$ = new Array;
		$$->add_child(new OpenAcc);
		$$->add_child(new ClosingAcc);
	}
| '{' expression-list '}'
    {
		$$ = new Array;
		$$->add_child(new OpenAcc);
		$$->add_child($2);
		$$->add_child(new ClosingAcc);
	}
;

tuple:
  DELIM_TUPLE_BEG DELIM_TUPLE_END /* empty tuple */
    {
		$$ = new Tuple;
		$$->add_child(new TupleBeg);
		$$->add_child(new TupleClosing);
	}
| DELIM_TUPLE_BEG expression-list DELIM_TUPLE_END
    {
		$$ = new Tuple;
		$$->add_child(new TupleBeg);
		$$->add_child($2);
		$$->add_child(new TupleClosing);
	}
;

/* The make sequence list allows to create datastructures
 * filled with increasing values (lists or arrays)
 */
make-sequence: 
	make-sequence-list
	{
		$$ = new MakeSequence();
		$$->add_child($1);
	}
 | 	make-sequence-array
	 {
	 	$$ = new MakeSequence();
		$$->add_child($1);
	 }
 ;
make-sequence-list: 
'{' seq-expression '}'
	{
		$$ = new MakeSequenceList();
		$$->add_child(new OpenAcc());
		$$->add_child($1);
		$$->add_child(new ClosingAcc());

	}
;

make-sequence-array: 
	DELIM_ARRAY_BEG seq-expression DELIM_ARRAY_END
		{
			$$ = new MakeSequenceArray();
			$$->add_child(new ArrayBeg());
			$$->add_child($1);
			$$->add_child(new ArrayEnd());

		}
	;

seq-expression: 
	expression KEYWORD_TO expression
		{
			$$ = new SeqExpression();
			$$->add_child($1);
			$$->add_child(new K_To());
			$$->add_child($2);
		}
	;

/**************/
/* Statements */
/**************/
statement:
  return
  	{
  		$$ = new Statement();
  		$$->add_child($1);
  	}
| menu
	{
		$$ = new Statement();
  		$$->add_child($1);
	}
| loop
	{
		$$ = new Statement();
  		$$->add_child($1);
	}
| KEYWORD_CONTINUE
	{
		$$ = new Statement();
  		$$->add_child(new K_Continue);
	}
| KEYWORD_BREAK
	{
		$$ = new Statement();
  		$$->add_child(K_Break);
	}
| conditional
	{
		$$ = new Statement();
  		$$->add_child($1);
	}
;

/* Return */
return:
  KEYWORD_NORI
  	{
  		$$ = new Return();
  		$$->add_child(K_Nori);
  	}
| KEYWORD_NORI expression
	{
		$$ = new Return();
  		$$->add_child(K_Nori);
  		$$->add_child($1);
	}
;

/* Switch */
menu: 
	KEYWORD_MENU expression DELIM_EOL menu-body DELIM_EOS
		{
			$$ = new Menu();
			$$->add_child(new K_Menu);
			$$->add_child($1);
			$$->add_child(DelimEol);
			$$->add_child($2);
			$$->add_child(new DelimEos);
		}
	;

menu-body:
  menu-def DELIM_EOL
  {
  	$$ = new MenuBody();
  	$$->add_child($1);
  	$$->add_child(DelimEol);
  }
| menu-case DELIM_EOL
	{
		$$ = new MenuBody();
  		$$->add_child($1);
  		$$->add_child(DelimEol);
	}
| menu-case DELIM_EOL menu-body
{
	$$ = new MenuBody();
	$$->add_child($1);
	$$->add_child(DelimEol);
	$$->add_child($2);
}
	
;

menu-case: 
	expression DELIM_ARROW scope DELIM_EOS
		{
			$$ = new MenuCase();
			$$->add_child($1);
			$$->add_child(new Arrow());
			$$->add_child($2);
 			$$->add_child(new DelimEos);

		}
;

menu-def:
 '_' DELIM_ARROW scope DELIM_EOS
 {
 	$$ = new MenuDef();
 	$$->add_child(new Underscore());
 	$$->add_child(new Arrow());
 	$$->add_child($1);
 	$$->add_child(new DelimEos);
 }
;

/* Loop */
loop :
  foreach
  	{
  		$$ = new Loop();
  		$$->add_child($1);
  	}
| for
	{
		$$ = new Loop();
  		$$->add_child($1);
	}
| roll
	{
		$$ = new Loop();
  		$$->add_child($1);
	}
 ;

/* The roll loop is actually a while loop
 * The expression should be interpretable as a boolean value
 */
roll : 
	KEYWORD_ROLL expression DELIM_EOL scope DELIM_EOS 
		{
			$$ = new Roll();
			$$->add_child(new K_Roll);
			$$->add_child($1);
			$$->add_child(new DelimEol);
			$$->add_child($2);
			$$->add_child(new DelimEos);

		}
	;

/* The foreach loop iterates over a list/array expression (so the expression part should be
 * interpretable as a list/array)
 */
foreach: 
	KEYWORD_FOREACH expression KEYWORD_AS IDENTIFIER DELIM_EOL scope DELIM_EOS
		{
			$$ = new Foreach();
			$$->add_child(new K_Foreach);
			$$->add_child($1);
			$$->add_child(new K_As);
			$$->add_child(new Identifier(*$2));
			$$->add_child(new DelimEol);
			$$->add_child($3);
			$$->add_child(new DelimEos);
			delete $2;

		}
	;


/* The for loop iterates until a condition becomes false
 * The initializer part can be empty or contain an assignment (if the variable does not exist
 * it is created).
 * The expression part shoulb be interpretable as a boolean.
 * The modifying-expression part should contain any update code  for updating some variables used
 * for iterating (or contain nothing)
 */
for: 
	KEYWORD_FOR for-initializer ',' expression ',' for-update DELIM_EOL scope DELIM_EOS
		{
			$$ = new For();
			$$->add_child(new K_For);
			$$->add_child($1);
			$$->add_child(new Virg);
			$$->add_child($2);
			$$->add_child(new Virg);
			$$->add_child($3);
			$$->add_child(new DelimEol);
			$$->add_child($4);
			$$->add_child(DelimEos);
		}
	;

for-initializer:
  %empty
| assignment
	{
		$$ = new ForInitializer();
		$$->add_child($1);
	}
;

for-update:
  %empty
| modifying-expression
	{
		$$ = new ForUpdate();
		$$->add_child($1);
	}
;

/* Conditionnal */
conditional:
  KEYWORD_IF expression DELIM_EOL scope-body DELIM_EOS
  	{
  		$$ = new Conditional();
  		$$->add_child(new K_If);
  		$$->add_child($1);
  		$$->add_child(new DelimEol);
  		$$->add_child($2);
  		$$->add_child(new DelimEos);
  	}
| KEYWORD_IF expression DELIM_EOL scope-body KEYWORD_ELSE scope-body DELIM_EOS
	{
		$$ = new Conditional();
		$$->add_child(new K_If);
  		$$->add_child($1);
  		$$->add_child(new DelimEol);
  		$$->add_child($2);
  		$$->add_child(new K_Else);
  		$$->add_child($3);
  		$$->add_child(new DelimEos);
	}
| KEYWORD_IF expression DELIM_EOL scope-body elseif DELIM_EOS
	{
		$$ = new Conditional();
		$$->add_child(new K_If);
  		$$->add_child($1);
  		$$->add_child(new DelimEol);
  		$$->add_child($2);
  		$$->add_child($3);
  		$$->add_child(new DelimEos);
	}
| KEYWORD_IF expression DELIM_EOL scope-body elseif KEYWORD_ELSE scope-body DELIM_EOS
	{
		$$ = new Conditional();
		$$->add_child(new K_If);
  		$$->add_child($1);
  		$$->add_child(new DelimEol);
  		$$->add_child($2);
  		$$->add_child($3);
  		$$->add_child(new K_Else);
  		$$->add_child($4);
  		$$->add_child(new DelimEos);
	}
;

elseif:

  KEYWORD_ELSEIF expression DELIM_EOL scope-body
  	{
  		$$ = new K_Elseif();
  		$$->add_child($1);
  		$$->add_child(new DelimEol);
  		$$->add_child($2);
  	}
| KEYWORD_ELSEIF expression DELIM_EOL scope-body elseif
	{
		$$ = new K_Elseif();
  		$$->add_child($1);
  		$$->add_child(new DelimEol);
  		$$->add_child($2);
  		$$->add_child($3);
	}

;

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