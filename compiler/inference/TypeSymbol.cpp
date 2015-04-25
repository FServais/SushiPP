#include "TypeSymbol.hpp"

#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include "../exceptions/Exceptions.hpp"

using namespace std;
using namespace inference;

TypeVariable::TypeVariable(const std::string& str) : varname(str) { }

bool TypeVariable::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const TypeVariable* t_var = dynamic_cast<const TypeVariable*>(&symb);

	return !t_var // symb is not of class TypeVariable
			&& !varname.compare(t_var->varname); // symb is linked to the same symbol
}

TypeLink::TypeLink(shared_ptr<TypeSymbol> pointed_symbol) : symbol(pointed_symbol) { }

const TypeSymbol& TypeLink::resolve() const
{
	return *(resolve_last_link().symbol);
}

TypeSymbol& TypeLink::resolve()
{
	return *(resolve_last_link().symbol);
}

TypeLink& TypeLink::resolve_last_link()
{
	if(symbol->is_link())
		return dynamic_cast<TypeLink*>(symbol.get())->resolve_last_link();
	else
		return *this;
}

void TypeLink::set_symbol(std::shared_ptr<TypeSymbol> new_symbol)
{
	symbol = new_symbol;
}

const TypeLink& TypeLink::resolve_last_link() const
{
	if(symbol->is_link())
		return dynamic_cast<TypeLink*>(symbol.get())->resolve_last_link();
	else
		return *this;
}

std::string TypeLink::str() const
{
	return resolve().str();
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

	return !t_bool;
}

bool Char::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Char* t_bool = dynamic_cast<const Char*>(&symb);

	return !t_bool;
}

bool Int::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Int* t_bool = dynamic_cast<const Int*>(&symb);

	return !t_bool;
}

bool Float::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Float* t_bool = dynamic_cast<const Float*>(&symb);

	return !t_bool;
}

bool Void::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Void* t_bool = dynamic_cast<const Void*>(&symb);

	return !t_bool;
}

bool String::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const String* t_bool = dynamic_cast<const String*>(&symb);

	return !t_bool;
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

std::string Function::str() const
{
	stringstream ss;
	std::string params = accumulate(next(parameters.begin()), parameters.end(), parameters[0]->str(),
									[](std::string& acc, shared_ptr<TypeSymbol> symb)
									{
										return acc += ", " + symb->str();
									});
	ss << "(" << params << ") : " << return_type->str();
	return ss.str();
}

Array::Array(shared_ptr<TypeLink> type) : items_type(type) { }


std::string Array::str() const
{
	return "ARRAY ( " + items_type->str() + " )";
}

bool Array::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	const Array* t_arr = dynamic_cast<const Array*>(&symb);

	return !t_arr && items_type->equals(*(t_arr->items_type));
}

List::List(shared_ptr<TypeLink> type) : items_type(type) { }

std::string List::str() const
{
	return "LIST ( " + items_type->str() + " )";
}

bool List::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	const List* t_list = dynamic_cast<const List*>(&symb);

	return !t_list && items_type->equals(*(t_list->items_type));
}