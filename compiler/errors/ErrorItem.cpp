#include "ErrorItem.hpp"

using namespace errors;

std::string ErrorItem::error_flag = "error";

void ErrorItem::print_location_error() const
{
	std::cout << context << std::endl;
	for(int i = 0 ; i < context.size() ; ++i)
	{
		if(i+1 == line)
			std::cout << "▲";
		else
			std::cout << "_";
	}
	std::cout << std::endl;
}