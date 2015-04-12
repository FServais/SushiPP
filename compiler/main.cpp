#include <iostream>
#include <cstdio>

#include "SPPCompiler.hpp"


// parser functions and globals
extern int yyparse();
extern "C" FILE* yyin;

// the compiler object is made global
compiler::SPPCompiler* g_compiler = nullptr;

int main(int argc, char** argv)
{
	compiler::SPPCompiler comp(argc, argv);
	g_compiler = &comp;
	comp.execute();
	return EXIT_SUCCESS;
}