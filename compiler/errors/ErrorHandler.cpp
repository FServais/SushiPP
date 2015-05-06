#include <iostream>
#include <string>

#include "ErrorHandler.hpp"

using namespace errors;
using namespace std;

ErrorHandler::ErrorHandler(settings::CompilerSettings _settings) : settings(_settings) { }

const ErrorItem& ErrorHandler::get_nth_error(int n) const
{
	return *(errors[n].get());
}

void ErrorHandler::print_errors() const
{
	bool is_from_file = settings.read_from_file();
	for(size_t i = 0 ; i < errors.size() ; ++i)
	{
		get_nth_error(i).print(is_from_file);
	}
}

/*
 ***************************************
 *			Lexical errors
 *************************************** 
 */

void ErrorHandler::add_lex_error(const string& context, int line, int col, const string& desc)
{
	errors.push_back(unique_ptr<LexicalError>(new LexicalError(context, line, col, (settings.read_from_file()) ? settings.get_input_file() : "", desc)));
}

void ErrorHandler::add_lex_error(LexicalError& err)
{
	errors.push_back(unique_ptr<LexicalError>(new LexicalError(err)));
}

/*
 ***************************************
 *		     Syntax errors
 *************************************** 
 */

void ErrorHandler::add_synt_error(const string& context, int line, int col, const string& desc)
{
	errors.push_back(unique_ptr<SyntaxError>(new SyntaxError(context, line, col, (settings.read_from_file()) ? settings.get_input_file() : "", desc)));
}

void ErrorHandler::add_synt_error(SyntaxError& err)
{
	errors.push_back(unique_ptr<SyntaxError>(new SyntaxError(err)));
}

/*
 ***************************************
 *		     Semantic errors
 *************************************** 
 */

void ErrorHandler::add_sem_error(const string& context, int line, int col, const string& desc)
{
	errors.push_back(unique_ptr<SemanticError>(new SemanticError(context, line, col, (settings.read_from_file()) ? settings.get_input_file() : "", desc)));
}

void ErrorHandler::add_sem_error(SemanticError& err)
{
	errors.push_back(unique_ptr<SemanticError>(new SemanticError(err)));
}

/*
 ***************************************
 *		     	IO errors
 *************************************** 
 */

void ErrorHandler::add_io_error(const string& context, const string& desc)
{
	errors.push_back(unique_ptr<IOError>(new IOError(context, (settings.read_from_file()) ? settings.get_input_file() : "", desc)));
}

void ErrorHandler::add_io_error(IOError& err)
{
	errors.push_back(unique_ptr<IOError>(new IOError(err)));
}

/*
 ***************************************
 *		     Memory errors
 *************************************** 
 */

void ErrorHandler::add_mem_error(const string& context, int line, int col, const string& desc)
{
	errors.push_back(unique_ptr<MemoryError>(new MemoryError(context, line, col, (settings.read_from_file()) ? settings.get_input_file() : "", desc)));
}

void ErrorHandler::add_mem_error(MemoryError& err)
{
	errors.push_back(unique_ptr<MemoryError>(new MemoryError(err)));
}

bool ErrorHandler::error_occurred()
{
	return errors.size() != 0;
}