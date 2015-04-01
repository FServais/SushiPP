#include <iostream>
#include <cstdio>

/** AST includes*/
#include "ast/AbstractSyntaxTree.hpp"
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
	if(argc == 2) 
	{
		// tough we use c++, we use FILE* here to 
		// provide the file input to the yyin parser input stream
		FILE* input = fopen(argv[1], "r");

		if(!input)
		{
			cerr << "[IO Error] Cannot open the file '" << argv[1] << "'..." << endl;
			return EXIT_FAILURE;
		}

		yyin = input;
		cout << "Compiling file '" << argv[1] << "'..." << endl;
	}
	else 
		cout << "Compiling from stdin..." << endl;

	/* Parsing */
	if(yyparse())
		cerr << "Parsing : failure..." << endl;
	else
		cout << "Parsing : success..." << endl;

	
	return EXIT_SUCCESS;
}