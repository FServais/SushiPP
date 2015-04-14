#include <iostream>

#include "ErrorHandler.hpp"
#include "../settings/CompilerSettings.hpp"

using namespace errors;

int main(int argc, char const *argv[])
{
	settings::CompilerSettings cs;
	ErrorHandler eh(cs);

	eh.add_lex_error("maki ;a = 33", 3, 6, "file.spp", "Completely wtf error");
	eh.print_errors();

	return 0;
}

