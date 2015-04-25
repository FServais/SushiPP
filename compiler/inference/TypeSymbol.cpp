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

	const TypeVariable* t_var = dynamic_cast<const TypeVariable*>(&symb);

	return t_var != nullptr // symb is not of class TypeVariable
			&& !varname.compare(t_var->varname); // symb is linked to the same symbol
}

TypeLink::TypeLink(shared_ptr<TypeSymbol> pointed_symbol) : symbol(pointed_symbol) { }

const TypeSymbol& TypeLink::resolve() const
{
	if(symbol->is_link()) // if the pointed symbol is a link, resolve it too
		return dynamic_cast<TypeLink*>(symbol.get())->resolve();
	else
		return *symbol;
}

TypeSymbol& TypeLink::resolve()
{
	if(symbol->is_link()) // if the pointed symbol is a link, resolve it too
		return dynamic_cast<TypeLink*>(symbol.get())->resolve();
	else
		return *symbol;
}

bool TypeLink::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;
	const TypeLink* t_link = dynamic_cast<const TypeLink*>(&symb);
	return !t_link ? symb.equals(resolve()) : resolve().equals(t_link->resolve());
}

bool Bool::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Bool* t_bool = dynamic_cast<const Bool*>(&symb);

	return t_bool != nullptr;
}

bool Char::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Char* t_bool = dynamic_cast<const Char*>(&symb);

	return t_bool != nullptr;
}

bool Int::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Int* t_bool = dynamic_cast<const Int*>(&symb);

	return t_bool != nullptr;
}

bool Float::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Float* t_bool = dynamic_cast<const Float*>(&symb);

	return t_bool != nullptr;
}

bool Void::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Void* t_bool = dynamic_cast<const Void*>(&symb);

	return t_bool != nullptr;
}

bool String::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const String* t_bool = dynamic_cast<const String*>(&symb);

	return t_bool != nullptr;
}

Function::Function(const std::vector<shared_ptr<TypeLink>>& params, shared_ptr<TypeLink> ret)
  : return_type(ret),
  	parameters(params)
{

}

bool Function::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Function* t_func = dynamic_cast<const Function*>(&symb);

	if(!t_func  // symb is not of type Function
		 || t_func->parameters.size() != parameters.size() // parameter list are not the same
		 || !return_type->equals(*(t_func->return_type))) // return type is not the same
		return false;

	// check whether the parameters are the same
	std::vector<bool> equality;

	transform(parameters.begin(), parameters.end(), t_func->parameters.begin(), back_inserter(equality),
			 [](shared_ptr<TypeLink> link1, shared_ptr<TypeLink> link2)
			 {
                return link1->equals(*link2);
			 });

	return all_of(equality.begin(), equality.end(), [](bool val) { return val; });
}
/*
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
*/
Array::Array(shared_ptr<TypeLink> type) : items_type(type) { }

bool Array::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	const Array* t_arr = dynamic_cast<const Array*>(&symb);

	return !t_arr && items_type->equals(*(t_arr->items_type));
}

List::List(shared_ptr<TypeLink> type) : items_type(type) { }

bool List::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	const List* t_list = dynamic_cast<const List*>(&symb);

	return !t_list && items_type->equals(*(t_list->items_type));
}
