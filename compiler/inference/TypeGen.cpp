

#include "TypeGen.hpp"
using namespace typegen;

Function::Function(std::shared_ptr<Type> ret_type, std::vector<std::shared_ptr<Type>> arg_type): return_type(ret_type), args_types(arg_type)
{

}

std::shared_ptr<Type> Function::get_arg(size_t i)
{
	if( i > args_types.size())
		throw except::BadParameterNumberException("Bad argument : out of bounds");
	return args_types[i];
}

Array::Array(std::shared_ptr<Type> type): param_type(type)
{

}

List::List(std::shared_ptr<Type> type): param_type(type)
{

}