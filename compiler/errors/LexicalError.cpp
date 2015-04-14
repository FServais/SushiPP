#include "LexicalError.hpp"

using namespace errors;
using namespace std;

LexicalError::LexicalError(const string& _context, int _col, int _line, const string& _file, const string& _additional_desc) : ErrorItem(_context, _col, _line, _file, _additional_desc) { }

void LexicalError::print(bool is_from_file) const
{
	if(is_from_file)
		cout << "In file \"" << file << "\":";
	else
		cout << "Line ";
	cout << line << ":" << col << ": "<< error_flag << ": " << additional_desc << endl;
	
	print_location_error();
}