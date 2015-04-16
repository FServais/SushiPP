#include "SppCompiler.hpp"

#include <cstdio> // FILE*, stdin
#include <iostream> // ostream
#include <fstream> // ofstream
#include <cstdlib> // srand
#include <ctime> // time
#include <ios> // failure

#include "ast/visitor/PrintASTVisitor.hpp"
#include "parser/sushipp.tab.h"

// bison parsing function
extern int yyparse();

// input stream of the scanner
extern "C" FILE* yyin;

using namespace compiler;
using namespace ast;
using namespace std;

SppCompiler::SppCompiler(int argc, char** argv) : config(argc, argv)
{
	srand(time(NULL));
}

void SppCompiler::execute()
{
	if(config.do_dump_help())
		settings::CompilerSettings::print_help();
	else
	{
		init();
		parse();
		terminate();
	}
}

void SppCompiler::init()
{
	// initialize input stream for parsing
	if(config.read_from_file())
	{
		if(config.is_verbose())
			cout << "Compiling from file '" << config.get_input_file() << "'..." << endl;

		// tough we use c++, we use FILE* here to 
		// provide the file input to the yyin scanner input stream
		FILE* input = fopen(config.get_input_file().c_str(), "r");

		if(!input)
		{
			cerr << "[IO Error] Cannot open the file '" << config.get_input_file()  << "'..." << endl;
			throw ios_base::failure("Cannot open the source file");
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

void SppCompiler::set_syntax_tree_root(ASTNode* root)
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
		break;
	default:
		if(config.is_verbose())
			cout << "Parsing : success..." << endl;

		if(config.do_dump_ast())
			print_ast();
	}
}

void SppCompiler::print_ast()
{
	if(config.do_dump_ast_in_file())
	{
		ofstream file(config.get_ast_dump_file().c_str());

		if(!file.is_open())
		{
			cerr << "[IO Error] Cannot open the file '" << config.get_ast_dump_file() << "'..." << endl;
			return;
		}

		PrintASTVisitor visitor(file);
		syntax_tree.root().accept(visitor);
		file.close();
	}
	else
	{
		PrintASTVisitor visitor(cout);
		syntax_tree.root().accept(visitor);
	}
}