#include <iostream>
#include <cstdio>

/** AST includes*/
#include "ast/AbstractSyntaxTree.hpp"
#include "ast/visitor/PrintASTVisitor.hpp"
#include "parser/sushipp.tab.h"

using namespace std;
using namespace ast;

// parser functions and globals
extern int yyparse();
extern "C" FILE* yyin;

// abstract syntax tree generated at the parsing 
AbstractSyntaxTree* syntax_tree = nullptr;

// static functions' prototypes
/**
 * @brief Run the parser to build the abstract syntax tree
 * @param[in] bool close_yyin True if the ressource held in yyin must be closed, false otherwise (must be true if the scanner gets its input from a file)
 * @retval int 0 if the parsing ended successfully, a positive integer otherwise
 * @note The resulting parse tree can be found in the global variable syntax_tree
 */
static int parse();


// static functions' implementations
static int parse(bool close_yyin)
{
	int yyparse_ret = yyparse();

	// close the file from which the token were read
	if(close_yyin)
		fclose(yyin);

	return yyparse_ret;
}

int main(int argc, char** argv)
{
	bool read_from_file = false;
	/* Check for input file */
	if(argc == 2) 
	{
		// tough we use c++, we use FILE* here to 
		// provide the file input to the yyin parser input stream
		FILE* input = fopen(argv[1], "r");
		read_from_file = true;

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
	if(parse(read_from_file))
		cerr << "Parsing : failure..." << endl;
	else
	{
		cout << "Parsing : success..." << endl;
		PrintASTVisitor printer_v;
		syntax_tree->root().accept(printer_v);
		
	}

	// delete the abstract syntax tree
	delete syntax_tree;

	return EXIT_SUCCESS;
}