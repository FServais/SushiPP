#include "MemoryError.hpp"

using namespace errors;
using namespace std;

MemoryError::MemoryError(const string& _context, int _line, int _col, const string& _file, const string& _additional_desc) : ErrorItem("Memory error", _context, _line, _col, _file, _additional_desc) { }

void MemoryError::print(bool is_from_file) const
{
	if(is_from_file)
		cout << "In file \"" << file << "\":";
	else
		cout << "Line ";
	cout << line << ":" << col << ": "<< BOLDRED << error_type << RESET << ": " << additional_desc << endl;
	
	//print_location_error();
}