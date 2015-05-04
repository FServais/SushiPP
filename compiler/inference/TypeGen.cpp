

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

std::string Array::to_str()
{
	std::cout<<"Array : "<<get_param_type()->to_str()<<std::endl;
}

std::string List::to_str()
{
	std::cout<<"List : "<<get_param_type()->to_str()<<std::endl;
}

std::string Function::to_str()
{
	std::cout<<"Function : "<<get_return_type()->to_str()<<"(" ;
		std::string str;
	for(auto param : get_arg)
		str += param->to_str() + " , ";
	std::cout<<str<<std::endl;
}

std::string Int::to_str()
{
	std::cout<<"Int"<<std::endl;
}

std::string Float::to_str()
{
	std::cout<<"Float"<<std::endl;
}

std::string Char::to_str()
{
	std::cout<<"Char"<<std::endl;
}

std::string String::to_str()
{
	std::cout<<"String"<<std::endl;
}

std::string Bool::to_str()
{
	std::cout<<"Bool"<<std::endl;
}

std::string Void::to_str()
{
	std::cout<<"Void"<<std::endl;
}