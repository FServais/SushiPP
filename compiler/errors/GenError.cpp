#include "GenError.hpp"

using namespace errors;
using namespace std;

GenError::GenError(const string& _context, const string& _file, const string& _additional_desc) : ErrorItem("Code generation error", _context, 0, 0, _file, _additional_desc) { }

void GenError::print(bool is_from_file) const
{
	cout << BOLDRED << error_type << RESET << ": " << additional_desc << endl;	
}
