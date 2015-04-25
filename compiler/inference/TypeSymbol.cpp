#include "TypeSymbol.hpp"

#include <sstream>
#include <algorithm>
#include <iterator>

#include "../exceptions/Exceptions.hpp"

using namespace std;
using namespace inference;

TypeVariable::TypeVariable(const std::string& str) : varname(str) { }

bool TypeVariable::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	TypeVariable* t_var = dynamic_cast<TypeVariable*>(&symb);

	return t_var != nullptr // symb is not of class TypeVariable
			&& !varname.compare(t_var->varname); // symb is linked to the same symbol
}

TypeLink::TypeLink(TypeSymbol& pointed_symbol) : symbol(pointed_symbol) { }

TypeSymbol& TypeLink::resolve()
{
	if(symbol.is_link()) // if the pointed symbol is a link, resolve it too
		return dynamic_cast<TypeLink&>(symbol).resolve();
	else  
		return symbol;
}

bool TypeLink::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;
	TypeLink* t_link = dynamic_cast<TypeLink*>(&symb);
	return !t_link ? symb.equals(resolve()) : resolve().equals(t_link->resolve());
}

bool Bool::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	Bool* t_bool = dynamic_cast<Bool*>(&symb);

	return t_bool != nullptr;
}

bool Char::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	Char* t_bool = dynamic_cast<Char*>(&symb);

	return t_bool != nullptr;
}

bool Int::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	Int* t_bool = dynamic_cast<Int*>(&symb);

	return t_bool != nullptr;
}

bool Float::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	Float* t_bool = dynamic_cast<Float*>(&symb);

	return t_bool != nullptr;
}

bool Void::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	Void* t_bool = dynamic_cast<Void*>(&symb);

	return t_bool != nullptr;
}

bool String::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	String* t_bool = dynamic_cast<String*>(&symb);

	return t_bool != nullptr;
}

Function::Function(const std::vector<TypeLink&>& params, TypeLink& ret)
  : return_type(ret),
  	parameters(params)
{

}

bool Function::equals(const TypeSymbol& symb) const
{
	if(this == *symb) return true;

	Function* t_func = dynamic_cast<Function*>(symb);

	if(!t_func  // symb is not of type Function
		 || t_func->parameters.size() != parameters.size() // parameter list are not the same
		 || !return_type.equals(t_func->return_type)) // return type is not the same
		return false;

	// check whether the parameters are the same
	std::vector<bool> equality;

	generate(parameters.begin(), parameters.end(), t_func->parameters.begin(), back_inserter(equality),
			[symb](TypeLink& link1, TypeLink& link2)
			{
				return link1.equals(link2);
			});

	return all_of(equality.begin(), equality.end(), [](bool val) { return val; });
}

void Function::get_return_type(types::Type* type) const
{
	return_type.get_type(type);
}

void Function::get_parameter_type(size_t param_nb, types::Type* type) const
{
	parameters[param_nb].get_type(type);
}

void Function::get_parameter_types(std::vector<types::Type>& types) const
{
	transform(parameters.begin(), parameters.end(), back_inserter(types), 
			  [](TypeLink& link)
			  {
				types::Type* type;
				link.get_type(type);
				return *type;
			  });
}

Array::Array(TypeLink& type) : items_type(type) { }

bool Array::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	Array* t_arr = dynamic_cast<Array*>(symb);

	return t_arr != nullptr && items_type.equals(t_arr->items_type);
}

Array::get_items_type(types::Type* type) const
{
	items_type.get_type(type);
}

List::List(TypeLink& type) : items_type(type) { }

bool List::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	List* t_list = dynamic_cast<List*>(symb);

	return t_list != nullptr && items_type.equals(t_list->items_type);
}

List::get_items_type(types::Type* type) const
{
	items_type.get_type(type);
}
