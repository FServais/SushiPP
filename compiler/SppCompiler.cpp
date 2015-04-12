#include "SPPCompiler.hpp"

#include <cstdio> // FILE*, stdin
#include <iostream> // ostream
#include <fstream>

#include "ast/visitor/PrintASTVisitor.hpp"
#include "parser/sushipp.tab.h"

// bison parsing function
extern int yyparse();

// input stream of the scanner
extern "C" FILE* yyin;

using namespace compiler;
using namespace ast;
using namespace std;

SppCompiler::SppCompiler(int argc, char** argv) : syntax_tree(nullptr), config(argc, argv)
{
	
}

void SppCompiler::execute()
{
	init();
	parse();
	terminate();
}

void SppCompiler::init()
{
	// initialize input stream for parsing
	if(config.read_from_file())
	{
		if(config.is_verbose())
			cout << "Compiling from file '" << config.get_input_file() "'..." << endl;

		// tough we use c++, we use FILE* here to 
		// provide the file input to the yyin scanner input stream
		FILE* input = fopen(config.get_input_file().c_str(), "r");

		if(!input)
		{
			cerr << "[IO Error] Cannot open the file '" << argv[1] << "'..." << endl;
			return;
		}

		yyin = input;
	}
	else if(config.is_verbose())
		cout << "Compiling from stdin..." << endl;
}

void SppCompiler::terminate()
{
	if(config.read_from_file())
		fclose(yyin);
}

void SPPCompiler::set_syntax_tree_root(ASTNode* root)
{
	syntax_tree.set_root(root);
}

void SppCompiler::parse()
{
	int ret = yyparse();

	switch(ret) 
	{
	case 1:
	case 2:
		if(config.is_verbose())
			cerr << "Parsing : failure..." << endl;
	default:
		if(config.is_verbose())
			cout << "Parsing : success..." << endl;

		if(config.dump_ast())
			print_ast();
	}
}

void SPPCompiler::print_ast()
{
	ostream& out = cout;

	if(config.dump_ast_in_dile())
	{
		ofstream file(config.get_ast_dump_file());

		if(!file.is_open())
		{
			cerr << "[IO Error] Cannot open the file '" << argv[1] << "'..." << endl;
			return;
		}

		out = file;
	}

	PrintASTVisitor visitor(out);
	syntax_tree.get_root().accept(visitor);

	if(config.dump_ast_in_file())
		dynamic_cast<ofstream>(file).close();
}