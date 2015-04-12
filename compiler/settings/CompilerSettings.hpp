#ifndef COMPILER_SETTINGS_HPP_DEFINED
#define COMPILER_SETTINGS_HPP_DEFINED


#include <map>

#include "../exceptions/Exceptions.hpp"

namespace settings
{
	enum ExecutionMode { PRINT_HELP, COMPILE }
	enum VerboseMode { QUIET, VERBOSE };
	enum DumpAST { DUMP_FILE, DUMP_STDOUT, NO_DUMP };
	enum ProgramSource { STDIN, FILE };

	/**
	 * @class CompilerSettings
	 * @brief A class for initializing and storing the compiler execution settings
	 * 
	 * The settings are the following :
	 *  - execution nmode : what the program is supposed to do (compiler or print help)
	 *  - verbose mode : should the compiler be verbose or not
	 *  - program source : should the compiler read the input program from the standard input or from a file
	 *  - dump ast : should the program output de AST in a txt format
	 * 
	 * Program parameters are the following :
	 * 
	 *    -i filename
	 *		 Input source : specify the file from which the input program to compile should be read
	 *    -h 
	 *		 Help : the compiler will only print a help message detailing program usage
	 *    -d [ filename ]
	 *       Dump : specify if the ast must printed out as soon as it is built. If a filename is provided, 
	 *       	the AST is printed out in this file
	 *    -v 
	 *		 Verbose : the compiler emits messages detailing its execution
	 */
	class CompilerSettings
	{
	public: 
		/** 
		 * Initialize the default settings :
		 *  - ProgramSource : STDIN
		 *  - VerboseMode : QUIET
		 *  - ExcutionMode : COMPILE
		 *  - DumpAST : NO_DUMP
		 */
		CompilerSettings();

		/**
		 * @brief build the settings from the program input
		 * @throw exceptions::BadInputParameterException If the parsing of the program parameters failss
		 */
		CompilerSettings(int argc, char** argv);

		// getters and setters 
		void set_verbose_mode(VerboseMode verbose_mode_) { verbose_mode = verbose_mode_; };
		void set_dump_ast(DumpAST dump_ast_) { dump_ast = dump_ast_; };
		void set_program_source(ProgramSource prog_source_) { prog_source = prog_source_; };
		void set_execution_mode(ExecutionMode exec_mode_) { exec_mode = exec_mode_; };

		VerboseMode get_verbose_mode() const { return verbose_mode; };
		DumpAST get_dump_ast() const { return dump_ast; };
		ProgramSource get_program_source() const { return prog_source; }; 
		ExecutionMode get_execution_mode() const { return exec_mode; };

		// these methods return relevant data only for some given settings
		const std::string& get_ast_dump_file() const { return param_map.at('d'); }; // only if dump ast is DUMP_FILE
		const std::string& get_input_file() const { return param_map.at('i'); }; // only if program source is FILE

		// check whether the VerboseMode setting was set to verbose
		bool is_verbose() const { return verbose_mode == VERBOSE; };
		bool dump_ast_in_file() const { return dump_ast == DUMP_FILE; };
		bool dump_ast_in_stdout() const { return dump_ast == DUMP_STDOUT; };

		// print the compiler program usage to the standard output
		static void print_help();
		// print the compiler settings to the standard output
		void print_settings();

	private:
		/** settings */
		VerboseMode verbose_mode;
		DumpAST dump_ast;
		ProgramSource prog_source;
		ExecutionMode exec_mode;

		// parameter map mapping input paremeters and their values
		std::map<char, std::string> param_map;

		/**
		 * @brief Build the parameter map from the program input
		 * @param int argc Arguments count
		 * @param char** argv Arguments values
		 * @throw exceptions::BadInputParameterException If the parsing of the parameter fails
		 */
		void build_map(int argc, char** argv);

		/**
		 * @brief Set the default settings
		 */
		void set_default();

		/**
		 * @brief Checks whether a parameter letter id is valid
		 * @retval bool True if the parameter id is valid
		 */
		bool valid_param_id(char c);
	};
}

#endif // COMPILER_SETTINGS_HPP_DEFINED