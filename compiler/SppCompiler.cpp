#include "SppCompiler.hpp"

#include <cstdio> // FILE*, stdin
#include <iostream> // ostream
#include <fstream> // ofstream
#include <cstdlib> // srand, system
#include <ctime> // time
#include <ios> // failure

#include "ast/visitor/PrintASTVisitor.hpp"
#include "ast/visitor/TypeInferenceVisitor.hpp"
#include "ast/visitor/FunctionTableVisitor.hpp"
#include "ast/visitor/SymbolTableVisitor.hpp"
#include "ast/visitor/CodeGenVisitor.hpp"

#include "util.hpp"

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

SppCompiler::SppCompiler(int argc, char** argv)
  : config(argc, argv),
  	error_handler(config),
  	optimization_flags("-mem2reg -tailcallelim -inline -constprop -dce")
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
		executable_generation();
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
	if(error_handler.error_occurred())
		return;

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
	if(error_handler.error_occurred())
		return;

	if(config.is_verbose())
		cout << "Starting code generation..." << endl;

	visitor::CodeGenVisitor visitor(variable_table, function_table, type_table, built_in);
	syntax_tree.root().accept(visitor);

	stringstream ss;
	visitor.print(ss);
	generated_llvm = ss.str();

	if(!config.do_dump_llvm())
		return;

	if(config.do_dump_llvm_in_file()) // write to a file
		write_llvm_to_file(config.get_llvm_dump_file());
	else // dump to screen
		cout << generated_llvm << endl;
}

void SppCompiler::executable_generation()
{
	if(error_handler.error_occurred())
		return;

	if(config.is_verbose())
		cout << "Generate the executable..." << endl;

	// check for the command processor
	if(!system(NULL))
	{
		error_handler.add_io_error("Command processor `system` not available");
		return;
	}

	// name of the .ll file to assemble, compile and link
	vector<string> to_assemble({ "runtime/list_runtime", "runtime/array_runtime", "runtime/support" }),
					generated_files;

	// add generated file
	string prog_file;

	if(config.do_dump_llvm_in_file())
		prog_file = util::remove_extension(config.get_llvm_dump_file());
	else
	{
		prog_file = "main__";
		if(!write_llvm_to_file(prog_file + ".ll"))
		{
			error_handler.add_gen_error("Cannot generate llvm temporary file...");
			return;
		}
		generated_files.push_back("main__.ll");
	}

	// add it in file to remove
	to_assemble.push_back(prog_file);

	// perform optimization
	string optimize_cmd("opt \"" + prog_file + ".ll\" " + optimization_flags + " -S >> \"" + prog_file + "_opt.ll\"");
	if(config.do_optimize() && execute_cmd(optimize_cmd))
	{
		error_handler.add_gen_error("", "cannot optimize intermediate representation");
		return;
	}
	else if(config.do_optimize()) // put back optimize code into the prog_file
	{
		string move_cmd("mv \"" + prog_file + "_opt.ll\" \"" + prog_file + ".ll\"");

		if(execute_cmd(move_cmd))
		{
			error_handler.add_gen_error("", "post-optimization cleaning failed");
			return;
		}
	}

	for(string& filename : to_assemble)
	{
		string convert2ll_cmd("clang \"" + filename + ".c\" --std=c99 -emit-llvm -S -O3 -o \"" + filename + ".ll\""),
			   assembly_cmd("llvm-as \"" + filename + ".ll\" -o \"" + filename + ".bc\""),
			   compile_cmd("llc \"" + filename + ".bc\" -o \"" + filename + ".s\"");

		if(filename != prog_file && execute_cmd(convert2ll_cmd))
		{
			error_handler.add_gen_error("", "cannot convert runtime sources to llvm assembly...");
			return;
		}
		else if(filename != prog_file)
			generated_files.push_back(filename + ".ll");

		// convert to bitcode
		if(execute_cmd(assembly_cmd))
		{
			error_handler.add_gen_error("", "cannot assemble file " + filename + ".ll...");
			return;
		}
		else generated_files.push_back(filename + ".bc");

		if(execute_cmd(compile_cmd))
		{
			error_handler.add_gen_error("", "cannot compile file " + filename + ".bc...");
			return;
		}
		else generated_files.push_back(filename + ".s");
	}

	// link the generated files
	vector<string> assembly_files, bitcode_files;
	transform(to_assemble.begin(), to_assemble.end(), back_inserter(assembly_files),
			  [](const std::string& file){ return "\"" + file + ".s\""; });
	transform(to_assemble.begin(), to_assemble.end(), back_inserter(bitcode_files),
			  [](const std::string& file){ return "\"" + file + ".bc\""; });

	string assembly_files_str = util::implode(assembly_files.begin(), assembly_files.end(), " "),
		   bitcode_files_str = util::implode(bitcode_files.begin(), bitcode_files.end(), " "),
		   files_to_rm = "\"" + util::implode(generated_files.begin(), generated_files.end(), "\" \"") + "\"",
		   link_cmd("gcc -o " + config.get_executable_file() + " " + assembly_files_str);

    if(execute_cmd(link_cmd))
    {
		error_handler.add_gen_error("", "cannot generate the executable...");
		return;
    }

    // delete generated files
    if(execute_cmd("rm " + files_to_rm))
    {
    	error_handler.add_gen_error("", "cannot delete tempory files...");
		return;
    }
}

ErrorHandler& SppCompiler::get_error_handler()
{
	return error_handler;
}

int SppCompiler::execute_cmd(const std::string& cmd)
{
	if(config.is_verbose())
		cout << "Bash : " << cmd << endl;
	return system(cmd.c_str());
}

bool SppCompiler::write_llvm_to_file(const std::string& filepath)
{
	ofstream file(filepath.c_str());

	if(!file.is_open())
	{
		stringstream ss;
		ss << "Cannot open the file '" << filepath  << "'...";
		error_handler.add_io_error("", ss.str());
		return false;
	}

	file << generated_llvm;
	file.close();
	return true;
}
