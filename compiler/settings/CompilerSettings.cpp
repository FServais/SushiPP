#include "CompilerSettings.hpp"

#include <iostream> // cout, endl
#include <cctype>

using namespace settings;
using namespace exceptions;
using namespace std;

CompilerSettings::CompilerSettings() 
{
	set_default();
}	

enum ExecutionMode { PRINT_HELP, COMPILE }
	enum VerboseMode { QUIET, VERBOSE };
	enum DumpAST { DUMP_FILE, DUMP_STDOUT, NO_DUMP };
	enum ProgramSource { STDIN, FILE };

CompilerSettings::CompilerSettings(int argc, char** argv)
{
	build_map(); // build the parameter map

	// set up the settings
	exec_mode = param_map.count('h') ? PRINT_HELP : COMPILE;

	if(param_map.count('d'))
		ast_dump = param_map['d'].empty() ? DUMP_STDOUT : DUMP_FILE;
	else
		ast_dump = NO_DUMP;

	prog_source = param_map.count('i') ? FILE : STDIN;
	verbose_mode = param_map.count('v') ? VERBOSE : QUIET;
}

void CompilerSettings::print_help()
{
	cout << "USAGE :           " << endl;
	cout << "  -i filename     " << endl;
	cout << "		Input source : specify the file from which the input program to compile should be read" << endl;
	cout << "  -h 			   " << endl;
	cout << "		Help : the compiler will only print a help message detailing program usage" << endl;
	cout << "  -d [ filename ] " << endl;
	cout << "		Dump : specify if the ast must printed out as soon as it is built. If a filename is " << endl;
	cout << "		  provided, the AST is printed out in this file" << endl;
	cout << "  -v              " << endl;
	cout << "		Verbose : the compiler emits messages detailing its execution" << endl;
	cout << endl;
}

void CompilerSettings::print_settings() const
{
	cout << "	- Verbose mode   : " << (verbose_mode == QUIET ? "off" : "on") << endl;
	cout << "	- Program source : " << (prog_source == STDIN ? "standard input" : "from file '" + param_map.at('i') + "'") << endl;
	cout << "	- Dump AST 		 : ";

	switch(dump_ast)
	{
	case DUMP_STDOUT:
		case << "on (in standard output)" << endl;
		break;
	case DUMP_FILE:
		case << "on (in file '" << param_map.at('d') << "')" << endl;
		break;
	default:// NO DUMP
		cout << "off" << endl;
	}

	cout << "	- Help display	 : " << (exec_mode == COMPILE ? "off" : "on") << endl;
}

void CompilerSettings::build_map(int argc, char** argv)
{
	char param; // param char identifier
	bool reading_parameter = false;

	for(int i = 1; i < argc; ++i)
	{
		string current(argv[i]);
		
		// check whether there is a '-'
		size_t hyphen = current.find_first_of('-');
		
		if(hyphen == 0) // reading a parameter
		{
			if(reading_parameter) // reading a parameter while another was already read without value
				param_map[param] = "";

			// extract the param char
			string param_str = current.substr(1);

			if(param_str.empty())
				throw BadInputParameterException("reading standalone hyphen, parameter of type '-[vhdi]' expected.");

			param = param_str[0];

			if(!isalpha(param))
				throw BadInputParameterException("reading a non-alphabetical parameter, parameter of type '-[vhdi]' expected.");

			if(!valid_param_id(param))
				throw BadInputParameterException("reading a unauthorized parameter, parameter of type '-[vhdi]' expected.");

			param = param_str[0];
			reading_parameter = true;
		}
		else // reading a value
		{
			if(!reading_parameter)
				throw BadInputParameterException("reading value, parameter of type '-[vhdi]' expected.");
			
			param_map[param] = current;
			reading_parameter = false;
		}
	}
}

void CompilerSettings::set_default()
{
	verbose_mode = QUIET;
	dump_ast = NO_DUMP;
	prog_source = STDIN;
	exec_mode = COMPILE;
}

bool valid_param_id(char c)
{
	return c == 'v' || c == 'h' || c == 'd' || c == 'i';
}

#endif // COMPILER_SETTINGS_HPP_DEFINED