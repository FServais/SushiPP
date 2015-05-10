#include "IOError.hpp"

using namespace errors;
using namespace std;

IOError::IOError(const string& _context, const string& _file, const string& _additional_desc) : ErrorItem("IO error", _context, 0, 0, _file, _additional_desc) { }

void IOError::print(bool is_from_file) const
{
	cout << BOLDRED << error_type << RESET << ": " << additional_desc << endl;	
}
