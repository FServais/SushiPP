%{
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <cstddef>
	#include <list>
	#include <utility>

	/** Compiler and AST includes */
	#include "../SppCompiler.hpp"
	#include "../errors/ErrorHandler.hpp"
	#include "../ast/AbstractSyntaxTree.hpp"

	#include "../ast/nodes/ASTNode.hpp"
	#include "../ast/nodes/NodeLocation.hpp"
	#include "../ast/nodes/ErrorNode.hpp"

	#include "../ast/nodes/tokens/Token.hpp"
	#include "../ast/nodes/tokens/Operator.hpp"
	#include "../ast/nodes/tokens/ConstantToken.hpp"
	#include "../ast/nodes/tokens/Keyword.hpp"

	#include "../ast/nodes/nonterminal/NonTerminal.hpp"
	#include "../ast/nodes/nonterminal/Constant.hpp"
	#include "../ast/nodes/nonterminal/NT_Datastructure.hpp"
	#include "../ast/nodes/nonterminal/NT_Declaration.hpp"
	#include "../ast/nodes/nonterminal/NT_Expression.hpp"
	#include "../ast/nodes/nonterminal/NT_FunctionCall.hpp"
	#include "../ast/nodes/nonterminal/NT_Program.hpp"
	#include "../ast/nodes/nonterminal/NT_Statement.hpp"

	/* Macro for getting the children of a ast::ASTNode* of type void* */
	#define children(node) ((ast::ASTNode*)node)->delete_children();

	extern "C" int yylex();

	static void yyerror(const char*);

	/** print the current location data */
	static std::string curr_line_row();
	/** Return a pointer to the type node for the given string and node location */
	static ast::Type* get_type_node(const std::string&, const ast::NodeLocation&);

	typedef std::pair<ast::Expression*, ast::Expression*> ExpressionPair;

	// pointer to the compiler object
	extern compiler::SppCompiler* g_compiler;
	// true if an error occurred -> used for exiting yyparse with correct code if the parser
	// reaches the end of file after error recovery
	bool error_occurred;

	struct YYLTYPE;
	/**
	 * @brief Return the location of the node of which the leftmost and rightmost children are given
	 * @param const yyltype& A location object
	 * @retval The node location resulting from the given YYLLOC location
	 */
	static ast::NodeLocation location(struct YYLTYPE);
	static ast::NodeLocation location2(struct YYLTYPE, struct YYLTYPE);
%}

%define parse.error verbose
%locations

%initial-action
{
	error_occurred = false;
}

%union
{
	std::string* vstring;
	void* vnode;
}

%destructor { delete $$; } <vstring>
%destructor { delete ((ast::ASTNode*)$$); } <vnode>

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
%token KEYWORD_CALL "call"

%token TYPE_INT "int"
%token TYPE_FLOAT "float"
%token TYPE_BOOL "bool"
%token TYPE_CHAR "char"
%token TYPE_STRING "string"
%token TYPE_ARRAY "array"
%token TYPE_LIST "list"
%token TYPE_FUNCTION "function"

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
%type <vnode> scope program-element
%type <vnode> declaration decl-vars decl-var decl-func param param-list
%type <vnode> func-call arg-list argument braced-func-call func-call-eol arg-list-eol soy-expression soy-func
%type <vnode> expression incr-expression assignment modifying-expression assignable-expression datastructure-access expression-list
%type <vnode> constant
%type <vnode> datastructure array list make-sequence make-sequence-list make-sequence-array seq-expression
%type <vnode> statement return menu menu-body menu-case menu-def loop roll foreach for for-initializer for-update conditional elseif else

%start program

%%

/***************************/
/*  Program general rules  */
/***************************/
program:
  %empty 		{ g_compiler->set_syntax_tree_root(new ast::Program(nullptr)); }
| scope	
	{
		if(error_occurred)
		{
			delete ((ast::ASTNode*) $1);
			YYABORT;
		}
		
		g_compiler->set_syntax_tree_root(new ast::Program((ast::Scope*)$1, location(@$))); 
	}
;

/* Scope containing sushi++ code */

scope:
  program-element           { $$ = (void*) (new ast::Scope((ast::ASTNode*)$1, location(@$))); }
| program-element DELIM_EOL { $$ = (void*) (new ast::Scope((ast::ASTNode*)$1, location(@$))); }
| program-element DELIM_EOL scope
	{
		ast::Scope* scope = ((ast::Scope*)$3);
		scope->add_program_element((ast::ASTNode*)$1);
		$$ = (void*) scope;
	}
| DELIM_EOL scope           { $$ = $2; }
;

program-element:
  statement            { $$ = $1; }
| modifying-expression { $$ = $1; }
| declaration          { $$ = $1; }
;

/***************/
/* Declaration */
/***************/
declaration:
  KEYWORD_MAKI decl-func { $$ = $2; }
| KEYWORD_MAKI decl-vars { $$ = $2; }
;

/* variable declaration */
decl-vars:
  decl-var { $$ = (void*) (new ast::DeclVars((ast::DeclVar*)$1, location(@$))); }
| decl-var ',' decl-vars
	{
		ast::DeclVars* decl = ((ast::DeclVars*)$3);
		decl->set_location(location(@$));
		decl->add_variable((ast::DeclVar*)$1);
		$$ = (void*) decl;
	}
| decl-var ',' DELIM_EOL decl-vars
	{
		ast::DeclVars* decl = ((ast::DeclVars*)$4);
		decl->set_location(location(@$));
		decl->add_variable((ast::DeclVar*)$1);
		$$ = (void*) decl;
	}
;

decl-var:
  IDENTIFIER
	{
		$$ = (void*) (new ast::DeclVar(new ast::Identifier(*$1, location(@1)), location(@$)));
		
		// delete the memory allocated for the string
		delete $1;
	}
| IDENTIFIER '=' expression
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$3, location(@3));
		ast::Identifier* iden = new ast::Identifier(*$1, location(@1));
		$$ = (void*) (new ast::DeclVar(iden, expr, location(@$)));

		// delete the memory allocated for the string
		delete $1;
	}
| error '=' expression
	{
		$$ = (void*) (new ast::ErrorNode);
		//cerr << " Details : a valid identifier name was exptected as left-hand-side item." << endl;
		delete ((ast::ASTNode*)$3);
		yyerrok;
	}
| IDENTIFIER '=' error
	{
		$$ = (void*) (new ast::ErrorNode);
		// delete the memory allocated for the string
		delete $1;
		//cerr << " Details : a valid expression was exptected as right-hand-side item." << endl;
		yyerrok;
	}
;

/* function declaration */
decl-func:
  IDENTIFIER param-list ':' scope DELIM_EOS
	{
		ast::Identifier* iden = new ast::Identifier(*$1, location(@1));
		ast::ParamList* params = ((ast::ParamList*)$2);
		ast::Scope* scope = ((ast::Scope*)$4);
		$$ = (void*) (new ast::DeclFunc(iden, params, scope, location(@$)));

		// delete the memory allocated for the string
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
		if(!$2)
			$$ = (void*) (new ast::ParamList((ast::Param*)$1, location(@$)));
		else
		{
			ast::ParamList* params = ((ast::ParamList*)$2);
			params->set_location(location(@$));
			params->add_param((ast::Param*)$1);
			$$ = (void*) params;
		}
	}
;

param:
  IDENTIFIER
	{
		ast::Identifier* iden = new ast::Identifier(*$1, location(@1));
		$$ = (void*) (new ast::Param(iden, location(@$)));

		// delete the memory allocated for the string
		delete $1;
	}
| IDENTIFIER '<' IDENTIFIER '>'
	{
		// get the type 
		ast::Identifier* iden = new ast::Identifier(*$1, location(@1));
		ast::Type* type = get_type_node(*$3, location(@3));

		if(!type)
		{
			// print the error
			std::stringstream line;
			line << *$1 << '<' << *$3 << '>';

			std::stringstream ss;
			ss << "Invalid type string : given '" << *$3 << "', actual type expected";

			yyerror(ss.str().c_str());

			YYERROR; // signal a parsing error
			yyerrok; // mark the error as ok, to continue parsing

			delete iden;
			$$ = (void*) (new ast::ErrorNode);
		}
		else
			$$ = (void*) (new ast::Param(iden, type, location(@$)));


		// delete the memory allocated for the string
		delete $1;
		delete $3;
	}
;

/******************/
/* Function calls */
/******************/

func-call:
  KEYWORD_CALL IDENTIFIER arg-list
	{
		ast::Identifier* iden = new ast::Identifier(*$2, location(@2));
		ast::ArgList* arglist = ((ast::ArgList*)$3);
		$$ = (void*) (new ast::FuncCall(iden, arglist, location(@$)));

		// delete the memory allocated for the string
		delete $2;
	}
| KEYWORD_CALL soy-expression arg-list
	{
		ast::ArgList* arglist = ((ast::ArgList*)$3);
		$$ = (void*) (new ast::FuncCall(((ast::ASTNode*)$2), arglist));
	}
;

arg-list:
  %empty
	{
		$$ = nullptr;
	}
| argument arg-list
	{
		if(!$2)
			$$ = (void*) (new ast::ArgList(((ast::Argument*)$1),location(@$)));
		else
		{
			ast::ArgList* arglist = ((ast::ArgList*)$2);
			arglist->set_location(location(@$));
			arglist->add_argument(((ast::Argument*)$1));;
			$$ = (void*) arglist;
		}
	}
;

argument:
  IDENTIFIER
	{
		ast::Identifier* iden = new ast::Identifier(*$1, location(@1));
		$$ = (void*) (new ast::Argument(iden, location(@$)));

		// delete the memory allocated for the string
		delete $1;
	}
| constant { $$ = (void*) (new ast::Argument((ast::ASTNode*)$1, location(@$))); }
| datastructure { $$ = (void*) (new ast::Argument((ast::ASTNode*)$1, location(@$))); }
| '(' expression ')'
	{
		// as the expression rule does not return an expression but the actual expression tree,
		// we create the expression node here
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		$$ = (void*) (new ast::Argument(expr, location(@$)));
	}
| soy-expression       { $$ = (void*) (new ast::Argument((ast::ASTNode*)$1, location(@$))); }
| datastructure-access { $$ = (void*) (new ast::Argument((ast::ASTNode*)$1, location(@$))); }
| braced-func-call     { $$ = (void*) (new ast::Argument((ast::ASTNode*)$1, location(@$))); }
| error
	{
		$$ = (void*) (new ast::ErrorNode);
		/*cerr << " Details : the argument is invalid. It should be either " << endl
			 << "    a constant, a braced expression, an anonymous soy function, " << endl
			 << "    a datastructure access or a variable." << endl; */
		yyclearin;
	}
;

braced-func-call: 
  '(' func-call-eol ')' { $$ = $2; }
;

/*
 * The func call eol is introduced to allow programmers to write
 * the arguments on several lines. To prevent ambiguities, this notation
 * is only allowed if the initial function call is braced (braced-func-call).
 */
func-call-eol:
  KEYWORD_CALL IDENTIFIER arg-list-eol
	{
		ast::Identifier* iden = new ast::Identifier(*$2, location(@2));
		ast::ArgList* arglist = ((ast::ArgList*)$3);
		$$ = (void*) (new ast::FuncCall(iden, arglist, location(@$)));

		// delete the memory allocated for the string
		delete $2;
	}
| KEYWORD_CALL soy-expression arg-list-eol
	{
		ast::ArgList* arglist = ((ast::ArgList*)$3);
		$$ = (void*) (new ast::FuncCall(((ast::ASTNode*)$2), arglist));
	}
;

arg-list-eol:
  %empty
  	{ 
  		$$ = nullptr;	
  	}
| argument arg-list-eol
	{	
		ast::ArgList* arglist;

		if($2 == nullptr)
			arglist = new ast::ArgList(((ast::Argument*)$1),location(@$)); 
		else 
		{	
			arglist = ((ast::ArgList*)$2);
			arglist->set_location(location(@$));
			arglist->add_argument(((ast::Argument*)$1));;
		}
		
		$$ = (void*) arglist;
	}
| argument DELIM_EOL arg-list-eol
	{
		ast::ArgList* arglist;

		if($3 == nullptr)
			arglist = new ast::ArgList(((ast::Argument*)$1),location(@$)); 
		else 
		{	
			arglist = ((ast::ArgList*)$3);
			arglist->set_location(location(@$));
			arglist->add_argument(((ast::Argument*)$1));
		}

		$$ = (void*) arglist;
	}
;

/* Anonymous functions */
soy-expression: 
  '(' soy-func ')' { $$ = $2; }
;

soy-func: 
  KEYWORD_SOY param-list ':' scope
	{
		ast::ParamList* params = ((ast::ParamList*)$2);
		ast::Scope* scope = ((ast::Scope*)$4);
		$$ = (void*) (new ast::SoyFunc(params, scope, location(@$)));
	}
;

/***************/
/* Expressions */
/***************/
expression:
  constant { $$ = $1; }
| '(' expression ')' { $$ = $2; }
| IDENTIFIER
	{
		$$ = new ast::Identifier(*$1, location(@1));

		// delete the memory allocated for the string
		delete $1;
	}
| datastructure                       { $$ = $1; }
| soy-expression                      { $$ = $1; }
| datastructure-access                { $$ = $1; }
| incr-expression                     { $$ = $1; }
| assignment                          { $$ = $1; }
| braced-func-call                    { $$ = $1; }
| expression '+' expression           { $$ = (void*) (new ast::Op_Plus(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression '-' expression           { $$ = (void*) (new ast::Op_Minus(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression '*' expression           { $$ = (void*) (new ast::Op_Mult(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression '/' expression           { $$ = (void*) (new ast::Op_Div(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression '%' expression           { $$ = (void*) (new ast::Op_Modulo(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression OP_ARITH_EXPO expression { $$ = (void*) (new ast::Op_Exponentiation(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| '-' expression %prec UNARY_MINUS    { $$ = (void*) (new ast::Op_UnaryMinus(((ast::ASTNode*)$2), location(@$))); }
| expression '|' expression           { $$ = (void*) (new ast::Op_BitwiseOr(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression '&' expression           { $$ = (void*) (new ast::Op_BitwiseAnd(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression '^' expression           { $$ = (void*) (new ast::Op_BitwiseXor(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| '~' expression                      { $$ = (void*) (new ast::Op_BitwiseNot(((ast::ASTNode*)$2), location(@$))); }
| expression OP_LOGIC_OR expression   { $$ = (void*) (new ast::Op_LogicalOr(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression OP_LOGIC_AND expression  { $$ = (void*) (new ast::Op_LogicalAnd(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| '!' expression                      { $$ = (void*) (new ast::Op_LogicalNot(((ast::ASTNode*)$2), location(@$))); }
| expression '<' expression           { $$ = (void*) (new ast::Op_CompLessThan(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression '>' expression           { $$ = (void*) (new ast::Op_CompGreaterThan(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression OP_COMP_LEQ expression   { $$ = (void*) (new ast::Op_CompLessEqual(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression OP_COMP_GEQ expression   { $$ = (void*) (new ast::Op_CompGreaterEqual(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression OP_COMP_EQ  expression   { $$ = (void*) (new ast::Op_CompEqual(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression OP_COMP_NEQ expression   { $$ = (void*) (new ast::Op_CompNotEqual(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression OP_LSHIFT expression     { $$ = (void*) (new ast::Op_RightShift(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression OP_RSHIFT expression     { $$ = (void*) (new ast::Op_LeftShift(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| expression '.' expression           { $$ = (void*) (new ast::Op_StringConcat(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
;

incr-expression:
  OP_ARITH_INCR assignable-expression %prec PREFIX_INCR { $$ = (void*) (new ast::Op_PrefixIncrement(((ast::ASTNode*)$2), location(@$))); }
| OP_ARITH_DECR assignable-expression %prec PREFIX_DECR { $$ = (void*) (new ast::Op_PrefixDecrement(((ast::ASTNode*)$2), location(@$))); }
| assignable-expression OP_ARITH_INCR %prec SUFFIX_INCR { $$ = (void*) (new ast::Op_PostfixIncrement(((ast::ASTNode*)$1), location(@$))); }
| assignable-expression OP_ARITH_DECR %prec SUFFIX_DECR { $$ = (void*) (new ast::Op_PostfixDecrement(((ast::ASTNode*)$1), location(@$))); }
;

assignment:
  assignable-expression '=' expression              { $$ = (void*) (new ast::Op_Assignment(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_PLUS expression   { $$ = (void*) (new ast::Op_AssignPlus(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_MINUS expression  { $$ = (void*) (new ast::Op_AssignMinus(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_MULT expression   { $$ = (void*) (new ast::Op_AssignMult(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_DIV expression    { $$ = (void*) (new ast::Op_AssignDiv(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_EXPO expression   { $$ = (void*) (new ast::Op_AssignExpo(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_MOD expression    { $$ = (void*) (new ast::Op_AssignMod(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_AND expression    { $$ = (void*) (new ast::Op_AssignAnd(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_OR expression     { $$ = (void*) (new ast::Op_AssignOr(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_XOR expression    { $$ = (void*) (new ast::Op_AssignXor(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
| assignable-expression OP_ASSIGN_CONCAT expression { $$ = (void*) (new ast::Op_AssignConcat(((ast::ASTNode*)$1), ((ast::ASTNode*)$3), location(@$))); }
;

/* A modifying expression is an expression that could bring about
 * a state modification (global variable, IO,...). These are the only
 * expressions that can be as such in a program (see program-element rule)
 */
modifying-expression:
  assignment       { $$ = (void*) (new ast::ModifyingExpression((ast::ASTNode*)$1, location(@$))); }
| incr-expression  { $$ = (void*) (new ast::ModifyingExpression((ast::ASTNode*)$1, location(@$))); }
| braced-func-call { $$ = (void*) (new ast::ModifyingExpression((ast::ASTNode*)$1, location(@$))); }
| func-call        { $$ = (void*) (new ast::ModifyingExpression((ast::ASTNode*)$1, location(@$))); }
;

/* An assignable expression is an expression that represents a
 * memory storage that can thus be assigned a new value
 */
assignable-expression:
  IDENTIFIER
    {
		$$ = new ast::Identifier(*$1, location(@1));

		// delete the memory allocated for the string
		delete $1;
	}
| datastructure-access { $$ = $1; }
;

datastructure-access: 
  IDENTIFIER '[' expression ']'
    {
		$$ = (void*) (new ast::DatastructureAccess(new ast::Identifier(*$1, location(@1)), 
					    						   new ast::Expression((ast::ASTNode*)$3, location(@3)), 
					    						   location(@$)));

		// delete allocated string
		delete $1;
	}
;

/* Comma-separated expression list */
expression-list:
  expression
	{
		$$ = (void*) (new ast::ExpressionList(new ast::Expression((ast::ASTNode*)$1, location(@1)), location(@$)));
	}
| expression ',' expression-list
	{
		ast::ExpressionList* expression_list = (ast::ExpressionList*)$3;
		ast::Expression* expression = new ast::Expression((ast::ASTNode*)$1, location(@1));
		expression->set_location(location(@$));
		expression_list->add_expression(expression);

		$$ = (void*) expression_list;
	}
;

/*************/
/* Constants */
/*************/
constant:
  CONST_INT
    {
		$$ = (void*) (new ast::Integer(*$1, location(@1)));

		// delete allocated string
		delete $1;
	}
| CONST_FLOAT
    {
		$$ = (void*) (new ast::Float(*$1, location(@1)));

		// delete allocated string
		delete $1;
	}
| CONST_STRING
    {
		$$ = (void*) (new ast::String(*$1, location(@1)));

		// delete allocated string
		delete $1;
	}
| CONST_BOOL
    {
		$$ = (void*) (new ast::Bool(*$1, location(@1)));

		// delete allocated string
		delete $1;
	}
| CONST_CHAR
    {
		$$ = (void*) (new ast::Character(*$1, location(@1)));

		// delete allocated string
		delete $1;
	}
;

/******************/
/* Datastructures */
/******************/
datastructure:
  array { $$ = $1; }
| list { $$ = $1; }
| make-sequence { $$ = $1; }
;

array:
  DELIM_ARRAY_BEG DELIM_ARRAY_END /* empty array */
    {
		$$ = (void*) (new ast::Array(location(@$)));
	}
| DELIM_ARRAY_BEG expression-list DELIM_ARRAY_END
    {
		$$ = (void*) (new ast::Array((ast::ASTNode*)$2, location(@$)));
	}
;

list:
  '{' '}' /* empty list */
    {
		$$ = (void*) (new ast::List(location(@$)));
	}
| '{' expression-list '}'
    {
		$$ = (void*) (new ast::List((ast::ASTNode*)$2, location(@$)));
	}
;

/* The make sequence list allows to create datastructures
 * filled with increasing values (lists or arrays)
 */
make-sequence: 
  make-sequence-list { $$ = $1; }
| make-sequence-array { $$ = $1; }
;

make-sequence-list: 
  '{' seq-expression '}'
	{
		ExpressionPair* exp_pair = (ExpressionPair*) $2;
		$$ = (void*) (new ast::MakeSequenceList(exp_pair->first, exp_pair->second, location(@$)));
		delete exp_pair;
	}
;

make-sequence-array: 
  DELIM_ARRAY_BEG seq-expression DELIM_ARRAY_END
	{
		ExpressionPair* exp_pair = (ExpressionPair*) $2;
		$$ = (void*) (new ast::MakeSequenceArray(exp_pair->first, exp_pair->second, location(@$)));
		delete exp_pair;
	}
;

/** The semantic value associated with the seq-expression is a pointer to a std::pair<ast::Expression*,ast::Expression*> */
seq-expression: 
  expression KEYWORD_TO expression
	{
		ast::Expression *expr1 = new ast::Expression((ast::ASTNode*)$1, location(@1)), 
						*expr2 = new ast::Expression((ast::ASTNode*)$3, location(@3));
		ExpressionPair* exp_pair = new ExpressionPair(expr1, expr2);
		$$ = (void*) exp_pair;
	}
;

/**************/
/* Statements */
/**************/
statement:
  return           { $$ = (void*) (new ast::Statement((ast::ASTNode*)$1)); }
| menu             { $$ = (void*) (new ast::Statement((ast::ASTNode*)$1)); }
| loop             { $$ = (void*) (new ast::Statement((ast::ASTNode*)$1)); }
| KEYWORD_CONTINUE { $$ = (void*) (new ast::Statement(new ast::K_Continue(location(@1)), location(@$))); }
| KEYWORD_BREAK    { $$ = (void*) (new ast::Statement(new ast::K_Break(location(@1)), location(@$))); }
| conditional      { $$ = (void*) (new ast::Statement((ast::ASTNode*)$1)); }
;

/* Return */
return:
  KEYWORD_NORI
	{
		$$ = (void*) (new ast::Return(location(@$)));
	}
| KEYWORD_NORI expression
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		$$ = (void*) (new ast::Return(expr, location(@$)));
	}
;

/* Switch */
menu: 
  KEYWORD_MENU expression DELIM_EOL menu-body DELIM_EOS
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		ast::MenuBody* menu_body = ((ast::MenuBody*)$4);
		$$ = (void*) (new ast::Menu(menu_body, expr, location(@$)));
	}
;

menu-body:
  menu-def DELIM_EOL
	{
		ast::MenuDef* menu_def = ((ast::MenuDef*)$1);
		$$ = (void*) (new ast::MenuBody(menu_def, location(@$)));
	}
| menu-case DELIM_EOL
	{
		ast::MenuCase* menu_case = ((ast::MenuCase*)$1);
		$$ = (void*) (new ast::MenuBody(menu_case, location(@$)));
	}
| menu-case DELIM_EOL menu-body
	{
		ast::MenuBody* menu_body = ((ast::MenuBody*)$3);
		ast::MenuCase* menu_case = ((ast::MenuCase*)$1);
		menu_body->add_case(menu_case);
		$$ = (void*) menu_body;
	}
;

menu-case: 
  expression DELIM_ARROW scope DELIM_EOS
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$1, location(@1));
		ast::Scope* scope = ((ast::Scope*)$3);
		$$ = (void*) (new ast::MenuCase(scope, expr, location(@$)));
	}
;

menu-def:
 '_' DELIM_ARROW scope DELIM_EOS
	{
		ast::Scope* scope = ((ast::Scope*)$3);
		$$ = (void*) (new ast::MenuDef(scope, location(@$)));
	}
;

/* Loop */
loop :
  foreach { $$ = $1; }
| for     { $$ = $1; }
| roll    { $$ = $1; }
;

/* The roll loop is actually a while loop
 * The expression should be interpretable as a boolean value
 */
roll : 
  KEYWORD_ROLL expression DELIM_EOL scope DELIM_EOS 
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		ast::Scope* scope = ((ast::Scope*)$4);
		$$ = (void*) (new ast::Roll(expr, scope, location(@$)));
	}
;

/* The foreach loop iterates over a list/array expression (so the expression part should be
 * interpretable as a list/array)
 */
foreach: 
  KEYWORD_FOREACH expression KEYWORD_AS IDENTIFIER DELIM_EOL scope DELIM_EOS
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		ast::Scope* scope = ((ast::Scope*)$6);
		ast::Identifier* id = new ast::Identifier(*$4, location(@4));
		$$ = (void*) (new ast::Foreach(expr, id, scope, location(@$)));

		// delete the memory allocated for the string
		delete $4;
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
		ast::ForInitializer* initializer = ((ast::ForInitializer*)$2);
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$4, location(@4));
		ast::ForUpdate* update = ((ast::ForUpdate*)$6);
		ast::Scope* scope = ((ast::Scope*)$8);
		$$ = (void*) (new ast::For(initializer, expr, update, scope, location(@$)));
	}
;

for-initializer:
  %empty     { $$ = nullptr; }
| assignment { $$ = (void*) (new ast::ForInitializer((ast::ASTNode*)$1, location(@$))); }
;

for-update:
  %empty               { $$ = nullptr; }
| modifying-expression { $$ = (void*) (new ast::ForUpdate((ast::ASTNode*)$1, location(@$))); }
;

/* Conditionnal */
conditional:
  KEYWORD_IF expression DELIM_EOL scope DELIM_EOS
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		ast::Scope* scope = ((ast::Scope*)$4);
		ast::If* if_node = new ast::If(expr, scope, location2(@1, @4));
		$$ = (void*) (new ast::Conditional(if_node, std::list<ast::Elseif*>(), nullptr, location(@$)));
	}
| KEYWORD_IF expression DELIM_EOL scope else DELIM_EOS
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		ast::Scope* scope = ((ast::Scope*)$4);
		ast::If* if_node = new ast::If(expr, scope, location2(@1, @4));
		ast::Else* else_node = ((ast::Else*)$5);
		$$ = (void*) (new ast::Conditional(if_node, std::list<ast::Elseif*>(), else_node, location(@$)));
	}
| KEYWORD_IF expression DELIM_EOL scope elseif DELIM_EOS
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		ast::Scope* scope = ((ast::Scope*)$4);
		ast::If* if_node = new ast::If(expr, scope, location2(@1, @4));
		std::list<ast::Elseif*>* elsif_list = ((std::list<ast::Elseif*>*)$5);
		$$ = (void*) (new ast::Conditional(if_node, *elsif_list, nullptr, location(@$)));
		
		// delete the list
		delete elsif_list;
	}
| KEYWORD_IF expression DELIM_EOL scope elseif else DELIM_EOS
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@2));
		ast::Scope* scope = ((ast::Scope*)$4);
		ast::If* if_node = new ast::If(expr, scope, location2(@1, @4));
		ast::Else* else_node = ((ast::Else*)$6);
		std::list<ast::Elseif*>* elsif_list = ((std::list<ast::Elseif*>*)$5);
		$$ = (void*) (new ast::Conditional(if_node, *elsif_list, else_node, location(@$)));
		
		// delete the list
		delete elsif_list;
	}
;

/**  elsif rule return an pointer to a std::list<ast::Elseif*> list */
elseif:
  KEYWORD_ELSEIF expression DELIM_EOL scope
	{
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@$));
		ast::Scope* scope = ((ast::Scope*)$4);
		ast::Elseif* elseif = new ast::Elseif(expr, scope, location(@$));
		std::list<ast::Elseif*>* elseif_list = new std::list<ast::Elseif*>();
		elseif_list->push_front(elseif);
		$$ = (void*) elseif_list;
	}
| KEYWORD_ELSEIF expression DELIM_EOL scope elseif
	{
		// build the elsif
		ast::Expression* expr = new ast::Expression((ast::ASTNode*)$2, location(@$));
		ast::Scope* scope = ((ast::Scope*)$4);
		ast::Elseif* elseif = new ast::Elseif(expr, scope, location(@$));
		// add it to the list
		std::list<ast::Elseif*>* elseif_list = ((std::list<ast::Elseif*>*)$5);
		elseif_list->push_front(elseif);
		$$ = (void*) elseif_list;
	}
;

else: 
  KEYWORD_ELSE scope 
	{
		ast::Scope* scope = ((ast::Scope*)$2);
		$$ = (void*) (new ast::Else(scope, location(@$)));
	}
;

%%

static void yyerror(const char *s)
{
	error_occurred = true;

	errors::ErrorHandler& error_handler = g_compiler->get_error_handler();
	error_handler.add_synt_error("", yylloc.first_line, yylloc.first_column, s);
}

static std::string curr_line_row()
{
	std::stringstream ss;
	ss << " at line " << yylloc.first_line << " (column " << yylloc.first_column << ")";
	return ss.str();
}

static ast::Type* get_type_node(const std::string& type_string, const ast::NodeLocation& loc)
{
	if(!type_string.compare("int"))
		return new ast::Type_Int(loc);
	else if(!type_string.compare("bool"))
		return new ast::Type_Bool(loc);
	else if(!type_string.compare("float"))
		return new ast::Type_Float(loc);
	else if(!type_string.compare("string"))
		return new ast::Type_String(loc);
	else if(!type_string.compare("list"))
		return new ast::Type_List(loc);
	else if(!type_string.compare("array"))
		return new ast::Type_Array(loc);
	else if(!type_string.compare("function"))
		return new ast::Type_Function(loc);
	else return nullptr;
}

static ast::NodeLocation location(struct YYLTYPE loc)
{
	return ast::NodeLocation(loc.first_line, loc.last_line, loc.first_column, loc.last_column);
}

static ast::NodeLocation location2(struct YYLTYPE loc1, struct YYLTYPE loc2)
{
	return ast::NodeLocation(loc1.first_line, loc2.last_line, loc1.first_column, loc2.last_column);
}