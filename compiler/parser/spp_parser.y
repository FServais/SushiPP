%{
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <cstddef>

	/** AST includes*/
	#include "../ast/AbstractSyntaxTree.hpp"

	#include "../ast/nodes/ASTNode.hpp"
	#include "../ast/nodes/NodeLocation.hpp"
	#include "../ast/nodes/ErrorNode.hpp"

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

	/* Macro for getting the children of a ASTNode* of type void* */
	#define children(node) ((ASTNode*)node)->delete_children()

	using namespace std;
	using namespace ast;

	extern "C" int yylex();

	static void yyerror(const char*);
	static string curr_line_row();

	// will store a pointer to the abstract syntax tree constructed by the parser
	extern AbstractSyntaxTree* syntax_tree;
	// true if an error occurred -> used for exiting yyparse with correct code if the parser
	// reaches the end of file after error recovery
	bool error_occurred;
%}

%define parse.error verbose
%locations

%initial-action
{
	if(syntax_tree != nullptr)
	{
		delete syntax_tree;
		syntax_tree = nullptr;
	}

	error_occurred = false;
}

%union
{
	std::string* vstring;
	void* vnode;
}

%destructor { delete $$; } <vstring>
%destructor { delete ((ASTNode*)$$); } <vnode>

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
%type <vnode> scope-body program-element scope
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
  %empty 		{ syntax_tree = new AbstractSyntaxTree(new Program); }
| scope-body	
	{
		if(error_occurred)
		{
			syntax_tree = nullptr;
			delete ((ScopeBody*) $1);
			YYABORT;
		}

		ASTNode* prog = new Program;

		if(prog == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		prog->add_child((ASTNode*)$1);
		syntax_tree = new AbstractSyntaxTree(prog); 
	}
;

/* Scope containing sushi++ code */
scope: 
  scope-body 
	{ 
		$$ = (void*) (new Scope);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1); 
	}
;

scope-body:
  program-element 
	{
		$$ = (void*) (new ScopeBody);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| program-element DELIM_EOL
	{
		$$ = (void*) (new ScopeBody);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| program-element DELIM_EOL scope-body
	{
		$$ = (void*) (new ScopeBody);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_children(children($3));

		// delete remaining node (which has no children)
		delete ((ScopeBody*)$3);
	}
| DELIM_EOL scope-body
	{
		$$ = (void*) (new ScopeBody);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_children(children($2));

		// delete remaining node (which has no children)
		delete ((ScopeBody*)$2);
	}
;

program-element:
  statement
	{
		$$ = (void*) (new ProgramElement);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| modifying-expression
	{
		$$ = (void*) (new ProgramElement);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| declaration
	{
		$$ = (void*) (new ProgramElement);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
;

/***************/
/* Declaration */
/***************/
declaration:
  KEYWORD_MAKI decl-func
	{
		$$ = (void*) (new Declaration);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_Maki);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
| KEYWORD_MAKI decl-vars
	{
		$$ = (void*) (new Declaration);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_Maki);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
;

/* variable declaration */
decl-vars:
  decl-var
	{
		$$ = (void*) (new DeclVars);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| decl-var ',' decl-vars
	{
		$$ = (void*) (new DeclVars);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Virg);
		((ASTNode*)$$)->add_children(children($3));

		// delete remaining node (which has no children)
		delete ((DeclVars*)$3);
	}
| decl-var ',' DELIM_EOL decl-vars
	{
		$$ = (void*) (new DeclVars);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Virg);
		((ASTNode*)$$)->add_children(children($4));

		// delete remaining node (which has no children)
		delete ((DeclVars*)$4);
	}
;

decl-var:
  IDENTIFIER
	{
		$$ = (void*) (new DeclVar);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));
		
		// delete the memory allocated for the string
		delete $1;
	}
| IDENTIFIER '=' expression
	{
		$$ = (void*) (new DeclVar);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));
		((ASTNode*)$$)->add_child(new Op_Assignment);
		((ASTNode*)$$)->add_child((ASTNode*)$3);

		// delete the memory allocated for the string
		delete $1;
	}
| error '=' expression
	{
		$$ = (void*) (new ErrorNode);
		//cerr << " Details : a valid identifier name was exptected as left-hand-side item." << endl;
		yyerrok;
	}
| IDENTIFIER '=' error
	{
		$$ = (void*) (new ErrorNode);
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
		$$ = (void*) (new DeclFunc);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));

		if($2 != nullptr) // if no parameters
			((ASTNode*)$$)->add_child((ASTNode*)$2);

		((ASTNode*)$$)->add_child(new Op_AssignFunc);
		((ASTNode*)$$)->add_child((ASTNode*)$4);
		((ASTNode*)$$)->add_child(new DelimEos);

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
		$$ = (void*) (new ParamList);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);

		if($2 != nullptr)
		{
			((ASTNode*)$$)->add_children(children($2));
			
			// delete remaining node (which has no children)
			delete ((ParamList*)$2);
		}
	}
;

param:
  IDENTIFIER
	{
		$$ = (void*) (new Param);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));

		// delete the memory allocated for the string
		delete $1;
	}
| IDENTIFIER '<' IDENTIFIER '>'
	{
		$$ = (void*) (new Param);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));
		((ASTNode*)$$)->add_child(new OpenChevr);
		((ASTNode*)$$)->add_child(new Identifier(*$3)); /** Discriminate identifier for type */
		((ASTNode*)$$)->add_child(new ClosingChevr);

		// delete the memory allocated for the string
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
		$$ = (void*) (new FuncCall);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));

		if($2 != nullptr)
			((ASTNode*)$$)->add_child((ASTNode*)$2);

		// delete the memory allocated for the string
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
		$$ = (void*) (new ArgList);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);

		if($2 != nullptr)
		{
			((ASTNode*)$$)->add_children(children($2));
			
			// delete remaining node (which has no children)
			delete ((ArgList*)$2);
		}
	}
;

argument:
  IDENTIFIER
	{
		$$ = (void*) (new Argument);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));

		// delete the memory allocated for the string
		delete $1;
	}
| constant
	{
		$$ = (void*) (new Argument);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| datastructure
	{
		$$ = (void*) (new Argument);

		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| '(' expression ')'
	{
		$$ = (void*) (new Argument);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new OpenPar);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new ClosingPar);
	}
| soy-expression
	{
		$$ = (void*) (new Argument);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| datastructure-access
	{
		$$ = (void*) (new Argument);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| braced-func-call
	{
		$$ = (void*) (new Argument);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| error
	{
		$$ = new ErrorNode();
		/*cerr << " Details : the argument is invalid. It should be either " << endl
			 << "    a constant, a braced expression, an anonymous soy function, " << endl
			 << "    a datastructure access or a variable." << endl; */
		yyclearin;
	}
;

braced-func-call: 
  '(' func-call-eol ')'
	{
		$$ = (void*) (new BracedFuncCall);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new OpenPar);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new ClosingPar);
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
		$$ = (void*) (new FuncCallEol);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));
		((ASTNode*)$$)->add_child((ASTNode*)$2);

		// delete the memory allocated for the string
		delete $1;
	}
| soy-expression arg-list-eol
	{
		$$ = (void*) (new FuncCallEol);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
| error arg-list-eol
	{
		$$ = (void*) (new ErrorNode);
		//cerr << " Details : either an identifier or a soy anonymous function was expected" << endl;
		yyerrok;
	}
;

arg-list-eol:
  argument
	{
		$$ = (void*) (new ArgListEol);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| argument arg-list-eol
	{
		$$ = (void*) (new ArgListEol);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_children(children($2));

		// delete remaining node (which has no children)
		delete ((ArgListEol*)$2);
	}
| argument DELIM_EOL arg-list-eol
	{
		$$ = (void*) (new ArgListEol);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_children(children($3));

		// delete remaining node (which has no children)
		delete ((ArgListEol*)$3);
	}
;

/* Anonymous functions */
soy-expression: 
  '(' soy-func ')'
	{
		$$ = (void*) (new SoyExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new OpenPar);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new ClosingPar);
	}
;

soy-func: 
  KEYWORD_SOY param-list ':' scope
	{
		$$ = (void*) (new SoyFunc);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_Soy);

		if((ASTNode*)$2 != nullptr)
			((ASTNode*)$$)->add_child((ASTNode*)$2);

		((ASTNode*)$$)->add_child(new Op_AssignFunc);
		((ASTNode*)$$)->add_child((ASTNode*)$4);
	}
;

/***************/
/* Expressions */
/***************/
expression:
  constant
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| '(' expression ')'
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new OpenPar);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new ClosingPar);
	}
| IDENTIFIER
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));

		// delete the memory allocated for the string
		delete $1;
	}
| datastructure
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| soy-expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| datastructure-access
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| incr-expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| assignment
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| braced-func-call
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| expression '+' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_Plus);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression '-' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_Minus);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression '*' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_Mult);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression '/' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_Div);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression '%' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_Modulo);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression OP_ARITH_EXPO expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_Exponentiation);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| '-' expression %prec UNARY_MINUS
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Op_UnaryMinus);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
| expression '|' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_BitwiseOr);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression '&' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_BitwiseAnd);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression '^' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_BitwiseXor);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| '~' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Op_BitwiseNot);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
| expression OP_LOGIC_OR expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_LogicalOr);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression OP_LOGIC_AND expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_LogicalAnd);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| '!' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Op_LogicalNot);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
| expression '<' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_CompLessThan);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression '>' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_CompGreaterThan);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression OP_COMP_LEQ expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_CompLessEqual);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression OP_COMP_GEQ expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_CompGreaterEqual);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression OP_COMP_EQ  expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_CompEqual);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression OP_COMP_NEQ expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_CompNotEqual);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression OP_LSHIFT expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_RightShift);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression OP_RSHIFT expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_LeftShift);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| expression '.' expression
	{
		$$ = (void*) (new Expression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_StringConcat);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
;

incr-expression:
  OP_ARITH_INCR assignable-expression %prec PREFIX_INCR
	{
		$$ = (void*) (new IncrExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Op_PrefixIncrement);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
| OP_ARITH_DECR assignable-expression %prec PREFIX_DECR
	{
		$$ = (void*) (new IncrExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Op_PrefixDecrement);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
| assignable-expression OP_ARITH_INCR %prec SUFFIX_INCR
	{
		$$ = (void*) (new IncrExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_PostfixIncrement);
	}
| assignable-expression OP_ARITH_DECR %prec SUFFIX_DECR
	{
		$$ = (void*) (new IncrExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_PostfixDecrement);
	}
;

assignment:
  assignable-expression '=' expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_Assignment);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_PLUS expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignPlus);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_MINUS expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignMinus);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_MULT expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignMult);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_DIV expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignDiv);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_EXPO expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignExpo);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_MOD expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignMod);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_AND expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignAnd);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_OR expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignOr);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_XOR expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignXor);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
| assignable-expression OP_ASSIGN_CONCAT expression
	{
		$$ = (void*) (new Assignment);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Op_AssignConcat);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
;

/* A modifying expression is an expression that could bring about
 * a state modification (global variable, IO,...). These are the only
 * expressions that can be as such in a program (see program-element rule)
 */
modifying-expression:
  assignment
  	{
		$$ = (void*) (new ModifyingExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| incr-expression
  	{
		$$ = (void*) (new ModifyingExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| braced-func-call
  	{
		$$ = (void*) (new ModifyingExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| func-call
  	{
		$$ = (void*) (new ModifyingExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
;

/* An assignable expression is an expression that represents a
 * memory storage that can thus be assigned a new value
 */
assignable-expression:
  IDENTIFIER
    {
		$$ = (void*) (new AssignableExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));

		// delete the memory allocated for the string
		delete $1;
	}
| datastructure-access
  	{
		$$ = (void*) (new AssignableExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
;

datastructure-access: 
  IDENTIFIER '[' expression ']'
    {
		$$ = (void*) (new DatastructureAccess);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Identifier(*$1));
		((ASTNode*)$$)->add_child(new OpenBrace);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
		((ASTNode*)$$)->add_child(new ClosingBrace);

		// delete allocated string
		delete $1;
	}
;

/* Comma-separated expression list */
expression-list:
  expression
	{
		$$ = (void*) (new ExpressionList);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| expression ',' expression-list
	{
		$$ = (void*) (new ExpressionList);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Virg);
		((ASTNode*)$$)->add_children(children($3));

		// delete remaining node (which has no children)
		delete ((ExpressionList*)$3);
	}
;

/*************/
/* Constants */
/*************/
constant:
  CONST_INT
    {
		$$ = (void*) (new NT_Constant);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Integer(*$1));
		
		// delete allocated string
		delete $1;
	}
| CONST_FLOAT
    {
		$$ = (void*) (new NT_Constant);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Float(*$1));
		
		// delete allocated string
		delete $1;
	}
| CONST_STRING
    {
		$$ = (void*) (new NT_Constant);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new String(*$1));
		
		// delete allocated string
		delete $1;
	}
| CONST_BOOL
    {
		$$ = (void*) (new NT_Constant);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Bool(*$1));
		
		// delete allocated string
		delete $1;
	}
| CONST_CHAR
    {
		$$ = (void*) (new NT_Constant);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Character(*$1));
		
		// delete allocated string
		delete $1;
	}
;

/******************/
/* Datastructures */
/******************/
datastructure:
  array
    {
		$$ = (void*) (new Datastructure);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| list
    {
		$$ = (void*) (new Datastructure);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| tuple
    {
		$$ = (void*) (new Datastructure);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| make-sequence
    {
		$$ = (void*) (new Datastructure);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
;

array:
  DELIM_ARRAY_BEG DELIM_ARRAY_END /* empty array */
    {
		$$ = (void*) (new Array);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new ArrayBeg);
		((ASTNode*)$$)->add_child(new ArrayEnd);
	}
| DELIM_ARRAY_BEG expression-list DELIM_ARRAY_END
    {
		$$ = (void*) (new Array);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new ArrayBeg);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new ArrayEnd);
	}
;

list:
  '{' '}' /* empty list */
    {
		$$ = (void*) (new List);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new OpenAcc);
		((ASTNode*)$$)->add_child(new ClosingAcc);
	}
| '{' expression-list '}'
    {
		$$ = (void*) (new List);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new OpenAcc);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new ClosingAcc);
	}
;

tuple:
  DELIM_TUPLE_BEG DELIM_TUPLE_END /* empty tuple */
    {
		$$ = (void*) (new Tuple);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new TupleBeg);
		((ASTNode*)$$)->add_child(new TupleEnd);
	}
| DELIM_TUPLE_BEG expression-list DELIM_TUPLE_END
    {
		$$ = (void*) (new Tuple);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new TupleBeg);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new TupleEnd);
	}
;

/* The make sequence list allows to create datastructures
 * filled with increasing values (lists or arrays)
 */
make-sequence: 
  make-sequence-list
	{
		$$ = (void*) (new MakeSequence);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| make-sequence-array
	{	
		$$ = (void*) (new MakeSequence);

		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	 }
;

make-sequence-list: 
  '{' seq-expression '}'
	{
		$$ = (void*) (new MakeSequenceList);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new OpenAcc());
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new ClosingAcc());
	}
;

make-sequence-array: 
  DELIM_ARRAY_BEG seq-expression DELIM_ARRAY_END
	{
		$$ = (void*) (new MakeSequenceArray);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new ArrayBeg());
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new ArrayEnd());

	}
;

seq-expression: 
  expression KEYWORD_TO expression
	{
		$$ = (void*) (new SeqExpression);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new K_To());
		((ASTNode*)$$)->add_child((ASTNode*)$3);
	}
;

/**************/
/* Statements */
/**************/
statement:
  return
  	{
  		
 $$ = (void*) (new Statement);
 
 if($$ == nullptr)
 {
 	yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child((ASTNode*)$1);
  	}
| menu
	{
		$$ = (void*) (new Statement);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| loop
	{
		$$ = (void*) (new Statement);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| KEYWORD_CONTINUE
	{
		$$ = (void*) (new Statement);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child(new K_Continue);
	}
| KEYWORD_BREAK
	{
		$$ = (void*) (new Statement);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child(new K_Break);
	}
| conditional
	{
		$$ = (void*) (new Statement);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
;

/* Return */
return:
  KEYWORD_NORI
  	{
		$$ = (void*) (new Return);

		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child(new K_Nori);
  	}
| KEYWORD_NORI expression
	{
		$$ = (void*) (new Return);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child(new K_Nori);
  		((ASTNode*)$$)->add_child((ASTNode*)$2);
	}
;

/* Switch */
menu: 
  KEYWORD_MENU expression DELIM_EOL menu-body DELIM_EOS
	{
		$$ = (void*) (new Menu);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_Menu);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child((ASTNode*)$4);
		((ASTNode*)$$)->add_child(new DelimEos);
	}
;

menu-body:
  menu-def DELIM_EOL
	{
		$$ = (void*) (new MenuBody);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| menu-case DELIM_EOL
	{
		$$ = (void*) (new MenuBody);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child((ASTNode*)$1);
 
	}
| menu-case DELIM_EOL menu-body
	{
		$$ = (void*) (new MenuBody);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_children(children($3));

		// delete remaining node (which has no children)
		delete ((MenuBody*)$3);
	}
;

menu-case: 
  expression DELIM_ARROW scope DELIM_EOS
	{
		$$ = (void*) (new MenuCase);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
		((ASTNode*)$$)->add_child(new Arrow);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
		((ASTNode*)$$)->add_child(new DelimEos);
	}
;

menu-def:
 '_' DELIM_ARROW scope DELIM_EOS
	{
		$$ = (void*) (new MenuDef);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new Underscore);
		((ASTNode*)$$)->add_child(new Arrow);
		((ASTNode*)$$)->add_child((ASTNode*)$3);
		((ASTNode*)$$)->add_child(new DelimEos);
	}
;

/* Loop */
loop :
  foreach
  	{
		$$ = (void*) (new Loop);

		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child((ASTNode*)$1);
  	}
| for
	{
		$$ = (void*) (new Loop);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
| roll
	{
		$$ = (void*) (new Loop);
  		
  		if($$ == nullptr)
  		{
  			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
;

/* The roll loop is actually a while loop
 * The expression should be interpretable as a boolean value
 */
roll : 
  KEYWORD_ROLL expression DELIM_EOL scope DELIM_EOS 
	{
		$$ = (void*) (new Roll);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_Roll);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child((ASTNode*)$4);
		((ASTNode*)$$)->add_child(new DelimEos);
	}
;

/* The foreach loop iterates over a list/array expression (so the expression part should be
 * interpretable as a list/array)
 */
foreach: 
  KEYWORD_FOREACH expression KEYWORD_AS IDENTIFIER DELIM_EOL scope DELIM_EOS
	{
		$$ = (void*) (new Foreach);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_Foreach);
		((ASTNode*)$$)->add_child((ASTNode*)$2);
		((ASTNode*)$$)->add_child(new K_As);
		((ASTNode*)$$)->add_child(new Identifier(*$4));
		((ASTNode*)$$)->add_child((ASTNode*)$6);
		((ASTNode*)$$)->add_child(new DelimEos);

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
		$$ = (void*) (new For);

		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_For);

		if((ASTNode*)$2 != nullptr)
			((ASTNode*)$$)->add_child((ASTNode*)$2);

		((ASTNode*)$$)->add_child(new Virg);
		((ASTNode*)$$)->add_child((ASTNode*)$4);
		((ASTNode*)$$)->add_child(new Virg);

		if((ASTNode*)$2 != nullptr)
			((ASTNode*)$$)->add_child((ASTNode*)$6);

		((ASTNode*)$$)->add_child((ASTNode*)$8);
		((ASTNode*)$$)->add_child(new DelimEos);
	}
;

for-initializer:
  %empty
	{
		$$ = nullptr;
	}
| assignment
	{
		$$ = (void*) (new ForInitializer);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
;

for-update:
  %empty
	{
		$$ = nullptr;
	}
| modifying-expression
	{
		$$ = (void*) (new ForUpdate);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child((ASTNode*)$1);
	}
;

/* Conditionnal */
conditional:
  KEYWORD_IF expression DELIM_EOL scope-body DELIM_EOS
  	{
  		
		$$ = (void*) (new Conditional);

		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

  		((ASTNode*)$$)->add_child(new K_If);
  		((ASTNode*)$$)->add_child((ASTNode*)$2);
 
  		((ASTNode*)$$)->add_child((ASTNode*)$4);
  		((ASTNode*)$$)->add_child(new DelimEos);
  	}
| KEYWORD_IF expression DELIM_EOL scope-body KEYWORD_ELSE scope-body DELIM_EOS
	{
		$$ = (void*) (new Conditional);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_If);
  		((ASTNode*)$$)->add_child((ASTNode*)$2);
 
  		((ASTNode*)$$)->add_child((ASTNode*)$4);
  		((ASTNode*)$$)->add_child(new K_Else);
  		((ASTNode*)$$)->add_child((ASTNode*)$6);
  		((ASTNode*)$$)->add_child(new DelimEos);
	}
| KEYWORD_IF expression DELIM_EOL scope-body elseif DELIM_EOS
	{
		$$ = (void*) (new Conditional);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_If);
  		((ASTNode*)$$)->add_child((ASTNode*)$2);
 
  		((ASTNode*)$$)->add_child((ASTNode*)$4);
  		((ASTNode*)$$)->add_child((ASTNode*)$5);
  		((ASTNode*)$$)->add_child(new DelimEos);
	}
| KEYWORD_IF expression DELIM_EOL scope-body elseif KEYWORD_ELSE scope-body DELIM_EOS
	{
		$$ = (void*) (new Conditional);
		
		if($$ == nullptr)
		{
			yyerror("cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_If);
  		((ASTNode*)$$)->add_child((ASTNode*)$2);
 
  		((ASTNode*)$$)->add_child((ASTNode*)$4);
  		((ASTNode*)$$)->add_child((ASTNode*)$5);
  		((ASTNode*)$$)->add_child(new K_Else);
  		((ASTNode*)$$)->add_child((ASTNode*)$7);
  		((ASTNode*)$$)->add_child(new DelimEos);
	}
;

elseif:
  KEYWORD_ELSEIF expression DELIM_EOL scope-body
  	{
		$$ = (void*) (new Elseif);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_Elseif);
  		((ASTNode*)$$)->add_child((ASTNode*)$2);
 
  		((ASTNode*)$$)->add_child((ASTNode*)$4);
  	}
| KEYWORD_ELSEIF expression DELIM_EOL scope-body elseif
	{
		$$ = (void*) (new Elseif);
		
		if($$ == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 1;
		}

		((ASTNode*)$$)->add_child(new K_Elseif);
  		((ASTNode*)$$)->add_child((ASTNode*)$2);
 
  		((ASTNode*)$$)->add_child((ASTNode*)$4);
  		((ASTNode*)$$)->add_child((ASTNode*)$5);
	}
;

%%

static void yyerror(const char *s)
{
	error_occurred = true;
	cerr << "[Error] " << s << curr_line_row() << endl;
}

static string curr_line_row()
{
	stringstream ss;
	ss << " at line " << yylloc.first_line << " (column " << yylloc.first_column << ")";
	return ss.str();
}