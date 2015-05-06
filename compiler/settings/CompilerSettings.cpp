#include "CompilerSettings.hpp"

#include <iostream> // cout, endl
#include <cctype>

using namespace settings;
using namespace except;
using namespace std;

CompilerSettings::CompilerSettings() 
{
	set_default();
}	

CompilerSettings::CompilerSettings(int argc, char** argv)
{
	build_map(argc, argv); // build the parameter map

	// set up the settings
	exec_mode = param_map.count('h') ? PRINT_HELP : COMPILE;

	if(param_map.count('d'))
		dump_ast = param_map['d'].empty() ? DUMP_STDOUT : DUMP_FILE;
	else
		dump_ast = NO_DUMP;

	if(param_map.count('l'))
		dump_llvm = param_map['l'].empty() ? DUMP_STDOUT : DUMP_FILE;
	else
		dump_llvm = NO_DUMP;

	prog_source = param_map.count('i') ? FILE : STDIN;
	verbose_mode = param_map.count('v') ? VERBOSE : QUIET;

	set_program_name(); 

	if(!param_map.count('o'))
		param_map['o'] = program_name;
}

void CompilerSettings::print_help()
{
	cout << "USAGE :           " << endl;
	cout << "  -i filename     " << endl;
	cout << "     Input source : specify the file from which the input program to compile should be read" << endl;
	cout << "  -h 			   " << endl;
	cout << "     Help : the compiler will only print a help message detailing program usage" << endl;
	cout << "  -d [ filename ] " << endl;
	cout << "     Dump : specify if the ast must printed out as soon as it is built. If a filename is " << endl;
	cout << "     provided, the AST is printed out in this file" << endl;
	cout << "  -v              " << endl;
	cout << "     Verbose : the compiler emits messages detailing its execution" << endl;
	cout << "  -o filename     " << endl;
	cout << "     Output program : name of the executable file" << endl;
	cout << "  -l [ filename ] " << endl;
	cout << "     LLVM output : specify if the LLVM assembly must printed out as soon as it is generated. If a filename is " << endl;
	cout << "     provided, the LLVM assembly is printed out in this file" << endl;
	cout << endl;
}

void CompilerSettings::print_settings() const
{
	cout << "Compiler settings : " << endl;
	cout << "  - Verbose mode   : " << (verbose_mode == QUIET ? "off" : "on") << endl;
	cout << "  - Program source : " << (prog_source == STDIN ? "standard input" : "from file '" + param_map.at('i') + "'") << endl;
	cout << "  - Dump AST       : ";

	switch(dump_ast)
	{
	case DUMP_STDOUT:
		cout << "on (in standard output)" << endl;
		break;
	case DUMP_FILE:
		cout << "on (in file '" << param_map.at('d') << "')" << endl;
		break;
	default:// NO DUMP
		cout << "off" << endl;
	}

	cout << "  - Dump LLVM      : ";

	switch(dump_llvm)
	{
	case DUMP_STDOUT:
		cout << "on (in standard output)" << endl;
		break;
	case DUMP_FILE:
		cout << "on (in file '" << param_map.at('l') << "')" << endl;
		break;
	default:// NO DUMP
		cout << "off" << endl;
	}

	cout << "  - Exec. name     : " << param_map.at('o') << endl; 
	cout << "  - Help display   : " << (exec_mode == COMPILE ? "off" : "on") << endl;
}

void CompilerSettings::build_map(int argc, char** argv)
{
	char param; // param char identifier
	bool reading_parameter = false;

	for(int i = 1; i < argc; ++i)
	{
		string current = argv[i];
		
		// check whether there is a '-'
		size_t hyphen = current.find_first_of('-');
		
		if(hyphen == 0) // reading a parameter
		{
			if(reading_parameter) // reading a parameter while another was already read without value
				param_map[param] = "";

			// extract the param char
			string param_str = current.substr(1);

			if(param_str.empty())
				throw BadInputParameterException("reading standalone hyphen, parameter of type '-[vhdilo]' expected.");

			param = param_str[0];

			if(!isalpha(param))
				throw BadInputParameterException("reading a non-alphabetical parameter, parameter of type '-[vhdilo]' expected.");

			if(!valid_param_id(param))
				throw BadInputParameterException("reading a unauthorized parameter, parameter of type '-[vhdilo]' expected.");

			reading_parameter = true;

			if(i == argc - 1) // last parameter
			{
				if(param == 'i' || param == 'o')
					throw BadInputParameterException("paramater '" + string(param, 1) + "' expect a argument specifying a file");
				else // because i except a value
					param_map[param] = "";				
			}
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

bool CompilerSettings::valid_param_id(char c)
{
	return c == 'v' || c == 'h' || c == 'd' || c == 'i' || c == 'l' || c == 'o';
}

void CompilerSettings::set_program_name()
{
	if(read_from_file())
	{
		size_t pos_of_slash = param_map['i'].find_last_of('/'),
			   pos_of_dot = param_map['i'].find_last_of('.');

		if(pos_of_slash == param_map['i'].length())
			program_name = param_map['i'].substr(0, pos_of_dot);
		else
			program_name = param_map['i'].substr(pos_of_slash + 1, pos_of_dot - pos_of_slash - 1);
	}
	else
		program_name = "spp_program";
}