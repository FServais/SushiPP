#include <iostream>

#include "ErrorHandler.hpp"
#include "../settings/CompilerSettings.hpp"

using namespace errors;

int main(int argc, char const *argv[])
{
	settings::CompilerSettings cs;
	ErrorHandler eh(cs);

	eh.add_lex_error("maki ;a = 33", 3, 6, "file.spp", "Completely wtf error");
	eh.add_synt_error("maki 33 = a", 3, 6, "file.spp");
	eh.add_sem_error("a + \"string\"", 4, 3, "file.spp");
	eh.add_io_error("> oazr;;ar", 5, 7, "file.spp");
	eh.add_mem_error("*(a+1231414)", 5, 3, "file.spp");

	eh.print_errors();

	return 0;
}

