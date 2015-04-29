#include "TypeSymbol.hpp"

#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include "../exceptions/Exceptions.hpp"

using namespace std;
using namespace inference;

TypeVariable::TypeVariable(const string& str) : varname(str) { }

bool TypeVariable::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const TypeVariable* t_var = dynamic_cast<const TypeVariable*>(&symb);
	
	return t_var // symb is of class TypeVariable
			&& !varname.compare(t_var->varname); // symb is linked to the same symbol
}

TypeLink::TypeLink(TypeSymbol* symb) : linked_symbol(symb), symbol_is_link(symb->is_link())
{ 
	if(!symb) throw invalid_argument("The link must be a valid pointer, nullptr given.");
}

TypeLink::~TypeLink()
{
	if(!symbol_is_link) // the ownership is not acquired on the type links
 		delete linked_symbol;
}

TypeSymbol& TypeLink::symbol()
{
	return *linked_symbol;
}

const TypeSymbol& TypeLink::symbol() const
{
	return *linked_symbol;
}

TypeSymbol& TypeLink::resolve()
{
	return resolve_last_link().symbol();
}

const TypeSymbol& TypeLink::resolve() const
{
	return resolve_last_link().symbol();
}

TypeLink& TypeLink::resolve_last_link()
{
	return linked_symbol->is_link() ? dynamic_cast<TypeLink&>(*linked_symbol).resolve_last_link() : *this;
}

const TypeLink& TypeLink::resolve_last_link() const
{
	return linked_symbol->is_link() ? dynamic_cast<TypeLink&>(*linked_symbol).resolve_last_link() : *this;
}

void TypeLink::set_symbol(TypeSymbol* new_symb)
{
	if(!symbol_is_link)
		delete linked_symbol;

	linked_symbol = new_symb;
	symbol_is_link = linked_symbol->is_link();
}

bool TypeLink::is_resolved() const 
{
	return linked_symbol->is_resolved();
}

string TypeLink::str() const
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

	return t_bool;
}

bool Char::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Char* t_char = dynamic_cast<const Char*>(&symb);

	return t_char;
}
bool Int::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Int* t_int = dynamic_cast<const Int*>(&symb);
	
	return t_int;
}

bool Float::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Float* t_float = dynamic_cast<const Float*>(&symb);

	return t_float;
}

bool Void::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Void* t_void = dynamic_cast<const Void*>(&symb);

	return t_void;
}

bool String::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const String* t_string = dynamic_cast<const String*>(&symb);

	return t_string;
}

Function::Function(const vector<reference_wrapper<TypeLink>>& params, TypeLink& ret)
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
		 || !return_type.equals(t_func->return_type)) // return type is not the same
		return false;

	// check whether the parameters are the same
	vector<bool> equality;

	transform(parameters.begin(), parameters.end(), t_func->parameters.begin(), back_inserter(equality),
			 [](TypeLink& link1, TypeLink& link2)
			 {
                return link1.equals(link2);
			 });

	return all_of(equality.begin(), equality.end(), [](bool val) { return val; });
}

bool Function::is_resolved() const 
{
	return return_type.is_resolved() 
			&& all_of(parameters.begin(), parameters.end(), [](const TypeLink& link) { return link.is_resolved(); });
}

string Function::str() const
{
	stringstream ss;


	string params;

	if(parameters.size() > 0)
		params = accumulate(next(parameters.begin()), parameters.end(), parameters[0].get().str(),
							[](string& acc, TypeSymbol& symb)
							{
								return acc += ", " + symb.str();
							});
	ss << "(" << params << ") : (" << return_type.str() << ")";
	return ss.str();
}

UniparameterType::UniparameterType(TypeLink& param_type) : parameter_type(param_type) { }

bool UniparameterType::is_resolved() const 
{
	return parameter_type.is_resolved();
}

Array::Array(TypeLink& type) : UniparameterType(type) { }

string Array::str() const
{
	return "ARRAY ( " + parameter_type.str() + " )";
}

bool Array::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	const Array* t_arr = dynamic_cast<const Array*>(&symb);

	return t_arr && parameter_type.equals(t_arr->parameter_type);
}

List::List(TypeLink& type) : UniparameterType(type) { }

string List::str() const
{
	return "LIST ( " + parameter_type.str() + " )";
}

bool List::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	const List* t_list = dynamic_cast<const List*>(&symb);

	return t_list && parameter_type.equals(t_list->parameter_type);
}
