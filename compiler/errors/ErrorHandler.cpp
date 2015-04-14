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
		get_nth_error(i).print(is_from_file);
}

/*
 ***************************************
 *			Lexical errors
 *************************************** 
 */

void ErrorHandler::add_lex_error(const string& context, int col, int line, const string& file, const string& desc)
{
	errors.push_back(unique_ptr<LexicalError>(new LexicalError(context, col, line, file, desc)));
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