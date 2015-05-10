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
	catch(std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch(std::ios_base::failure& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch(std::exception& e)
	{
		std::cerr << "Unexpected error : " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}