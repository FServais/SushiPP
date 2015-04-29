#include "SyntaxError.hpp"

using namespace errors;
using namespace std;

SyntaxError::SyntaxError(const string& _context, int _line, int _col, const string& _file, const string& _additional_desc) : ErrorItem("Syntax error", _context, _line, _col, _file, _additional_desc) { }

void SyntaxError::print(bool is_from_file) const
{
	if(is_from_file)
		cout << "In file \"" << file << "\":";
	else
		cout << "Line ";
	cout << line << ":" << col << ": "<< BOLDRED << error_type << RESET << ": " << additional_desc << endl;
	
	//print_location_error();
}