#include <cstddef> // nullptr
#include <iostream> // cerr, endl
#include <stdexcept> // exception

#include "SppCompiler.hpp"

// parser functions and globals
extern int yyparse();
extern "C" FILE* yyin;

// the compiler object is made global
compiler::SppCompiler* g_compiler = nullptr;

int main(int argc, char** argv)
{
	try
	{
		compiler::SppCompiler comp(argc, argv);
		g_compiler = &comp;
		comp.execute();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}