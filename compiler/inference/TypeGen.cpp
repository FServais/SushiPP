
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

void Array::to_str()
{
	cout<<"Array : "<<endl;
	get_param_type()->to_str();
}

void List::to_str()
{
	cout<<"List : "<<endl;
	get_param_type()->to_str();
}

void Function::to_str()
{
	get_ret_type()->to_str();
		string str;
	for(int i = 0; i < nb_param(); i++)
		get_arg(i)->to_str();
}

void Int::to_str()
{
	cout<<"Int"<<endl;
}

void Float::to_str()
{
	cout<<"Float"<<endl;
}

void Char::to_str()
{
	cout<<"Char"<<endl;
}

void String::to_str()
{
	cout<<"String"<<endl;
}

void Bool::to_str()
{
	cout<<"Bool"<<endl;
}

void Void::to_str()
{
	cout<<"Void"<<endl;
}