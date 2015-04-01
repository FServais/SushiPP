#include <iostream>
#include <cstdio>

/** AST includes*/
#include "ast/AbstractSyntaxTree.hpp"
#include "ast/nodes/ASTNode.hpp"
#include "ast/nodes/NodeLocation.hpp"

#include "ast/nodes/tokens/Token.hpp"
#include "ast/nodes/tokens/Operator.hpp"
#include "ast/nodes/tokens/ConstantToken.hpp"
#include "ast/nodes/tokens/Delimiter.hpp"
#include "ast/nodes/tokens/Keyword.hpp"

#include "ast/nodes/nonterminal/NonTerminal.hpp"
#include "ast/nodes/nonterminal/NT_Constant.hpp"
#include "ast/nodes/nonterminal/NT_Datastructure.hpp"
#include "ast/nodes/nonterminal/NT_Declaration.hpp"
#include "ast/nodes/nonterminal/NT_Expression.hpp"
#include "ast/nodes/nonterminal/NT_FunctionCall.hpp"
#include "ast/nodes/nonterminal/NT_Program.hpp"
#include "ast/nodes/nonterminal/NT_Statement.hpp"

#include "parser/sushipp.tab.h"

using namespace std;
using namespace ast;

// parser functions and globals
extern int yyparse();
extern "C" FILE* yyin;

// abstract syntax tree generated at the parsing 
AbstractSyntaxTree* syntax_tree = NULL;

int main(int argc, char** argv)
{
	/* Check for input file */
	// if(argc == 2) 
	// {
	// 	// tough we use c++, we use FILE* here to 
	// 	// provide the file input to the yyin parser input stream
	// 	FILE* input = fopen(argv[1], "r");

	// 	if(!input)
	// 	{
	// 		cerr << "[IO Error] Cannot open the file '" << argv[1] << "'..." << endl;
	// 		return EXIT_FAILURE;
	// 	}

	// 	yyin = input;
	// 	cout << "Compiling file '" << argv[1] << "'..." << endl;
	// }
	// else 
	// 	cout << "Compiling from stdin..." << endl;

	// /* Parsing */
	// if(yyparse())
	// 	cerr << "Parsing : failure..." << endl;
	// else
	// 	cout << "Parsing : success..." << endl;

	
	return EXIT_SUCCESS;
}