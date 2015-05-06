#include "SppCompiler.hpp"

#include <cstdio> // FILE*, stdin
#include <iostream> // ostream
#include <fstream> // ofstream
#include <cstdlib> // srand
#include <ctime> // time
#include <ios> // failure

#include "ast/visitor/PrintASTVisitor.hpp"
#include "ast/visitor/TypeInferenceVisitor.hpp"
#include "ast/visitor/FunctionTableVisitor.hpp"
#include "ast/visitor/SymbolTableVisitor.hpp"
#include "ast/visitor/CodeGenVisitor.hpp"

#include "parser/sushipp.tab.h"

// bison parsing function
extern int yyparse();

// input stream of the scanner
extern "C" FILE* yyin;

using namespace compiler;
using namespace ast;
using namespace errors;
using namespace std;
using namespace visitor;

SppCompiler::SppCompiler(int argc, char** argv) : config(argc, argv), error_handler(config)
{
	srand(time(NULL));

	if(config.is_verbose())
		config.print_settings();
}

void SppCompiler::execute()
{
	if(config.do_dump_help())
		settings::CompilerSettings::print_help();
	else
	{
		init();
		parse();
		scope_checking();
		inference();
		export_llvm();
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
			stringstream ss;
			ss << "Cannot open the file '" << config.get_input_file()  << "'...";
			error_handler.add_io_error("", ss.str());
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

	if(config.is_verbose())
	{
		if(error_handler.error_occurred())
			cerr << "Compilation terminated with errors..." << endl;
		else
			cout << "Compilation terminated successfully..." << endl;
	}

	error_handler.print_errors();
}

void SppCompiler::set_syntax_tree_root(ASTNode* root)
{
	syntax_tree.set_root(root);
}

void SppCompiler::parse()
{
	if(config.is_verbose())
		cout << "Starting parsing..." << endl;

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

void SppCompiler::scope_checking()
{
	if(error_handler.error_occurred())
		return;

	if(config.is_verbose())
		cout << "Starting scope checking..." << endl;

	visitor::FunctionTableVisitor func_visitor(function_table, variable_table, error_handler, built_in);
	syntax_tree.root().accept(func_visitor);

	visitor::SymbolTableVisitor var_visitor(function_table, variable_table, error_handler);
	syntax_tree.root().accept(var_visitor);

	// std::cout<<"FUNCTION TABLE"<<std::endl;
	// function_table.print_table();

	// std::cout<<"VARIABLE TABLE"<<std::endl;
	// variable_table.print_table();
}

void SppCompiler::inference()
{
	//if(error_handler.error_occurred())
	//	return;

	if(config.is_verbose())
		cout << "Starting type inference..." << endl;

	visitor::TypeInferenceVisitor visitor(error_handler, function_table, variable_table, type_table, built_in);
	syntax_tree.root().accept(visitor);
	
	//cout << endl << type_table << endl << endl;
}

void SppCompiler::print_ast()
{
	if(error_handler.error_occurred())
		return;
	if(config.do_dump_ast_in_file())
	{
		ofstream file(config.get_ast_dump_file().c_str());

		if(!file.is_open())
		{
			cerr << "[IO Error] Cannot open the file '" << config.get_ast_dump_file() << "'..." << endl;
			return;
		}

		visitor::PrintASTVisitor visitor(file);
		syntax_tree.root().accept(visitor);
		file.close();
	}
	else
	{
		visitor::PrintASTVisitor visitor(cout);
		syntax_tree.root().accept(visitor);
	}
}

void SppCompiler::export_llvm()
{
	if(config.is_verbose())
		cout << "Starting code generation..." << endl;

	visitor::CodeGenVisitor visitor(variable_table, function_table, type_table);
	syntax_tree.root().accept(visitor);

	if(!config.do_dump_llvm())
		return;

	if(config.do_dump_llvm_in_file())
	{
		ofstream file(config.get_llvm_dump_file().c_str());

		if(!file.is_open())
		{
			stringstream ss;
			ss << "Cannot open the file '" << config.get_input_file()  << "'...";
			error_handler.add_io_error("", ss.str());
			return;
		}
		
		visitor.print(file);

		file.close();
	}
	else
		visitor.print(cout);
/*
	CodeGenVisitor visitor(variable_table, function_table, type_table);
	syntax_tree.root().accept(visitor);
	visitor.print(cout); */
}

ErrorHandler& SppCompiler::get_error_handler()
{
	return error_handler;
}
