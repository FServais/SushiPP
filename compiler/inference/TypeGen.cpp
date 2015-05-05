
#include <iostream>
#include "TypeGen.hpp"
using namespace std; 
using namespace typegen;

Function::Function(shared_ptr<Type> ret_type, vector<shared_ptr<Type>> arg_type): return_type(ret_type), args_types(arg_type)
{

}

shared_ptr<Type> Function::get_arg(size_t i)
{
	if( i > args_types.size())
		throw except::BadParameterNumberException("Bad argument : out of bounds");
	return args_types[i];
}

Array::Array(shared_ptr<Type> type): param_type(type)
{

}

List::List(shared_ptr<Type> type): param_type(type)
{

}

string Array::to_str()
{
	to_return = 
	cout<<"Array : "<<endl;
	get_param_type()->to_str();
}

string List::to_str()
{
	cout<<"List : "<<endl;
	get_param_type()->to_str();
}

string Function::to_str()
{
	string to_return = get_ret_type()->to_str() + " (";
	for(int i = 0; i < nb_param(); i++)
	{
		if(i != nb_param() - 1)
			to_return += get_arg(i)->to_str() + ", ";
		else
			to_return += get_arg(i)->to_str() + " )";
	}
		
	return to_return;
}

string Int::to_str()
{
	return "i32";
}

string Float::to_str()
{
	return "float";
}

string Char::to_str()
{
	return "i8";
}

string String::to_str()
{
	cout<<"String"<<endl;
}

string Bool::to_str()
{
	return "i8";
}

string Void::to_str()
{
	return "void";
}