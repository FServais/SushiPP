#include "ErrorItem.hpp"

using namespace errors;

std::string ErrorItem::error_flag = "error";

void ErrorItem::print_location_error() const
{
	std::cout << context << std::endl;
	std::cout << GREEN;
	for(int i = 0 ; i < context.size() ; ++i)
	{
		if(i+1 == col)
			std::cout << "^";
		else
			std::cout << "_";
	}
	std::cout << RESET << std::endl;
}