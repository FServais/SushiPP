#include "TypeSymbol.hpp"

#include "InferenceExceptions.hpp"

#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

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

shared_ptr<typegen::Type> TypeVariable::ret_type() const 
{
	throw except::UnresolvableTypeException("type wasn't successfully inferred at type inference phase");
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

TerminalTypeSymbol& TypeLink::resolve()
{
	return dynamic_cast<TerminalTypeSymbol&>(resolve_last_link().symbol());
}

const TerminalTypeSymbol& TypeLink::resolve() const
{
	return dynamic_cast<const TerminalTypeSymbol&>(resolve_last_link().symbol());
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

shared_ptr<typegen::Type> TypeLink::ret_type() const
{
	return resolve().ret_type();
}

Bool::Bool() { hints = TypesHint(BOOL); }

bool Bool::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Bool* t_bool = dynamic_cast<const Bool*>(&symb);

	return t_bool;
}

shared_ptr<typegen::Type> Bool::ret_type() const
{
	return shared_ptr<typegen::Type>(new typegen::Bool());
}

Char::Char() { hints = TypesHint(CHAR); }

bool Char::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Char* t_char = dynamic_cast<const Char*>(&symb);

	return t_char;
}

shared_ptr<typegen::Type> Char::ret_type() const
{
	return shared_ptr<typegen::Type>(new typegen::Char());
}


Int::Int() { hints = TypesHint(INT); }

bool Int::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Int* t_int = dynamic_cast<const Int*>(&symb);
	
	return t_int;
}

shared_ptr<typegen::Type> Int::ret_type() const
{
	return shared_ptr<typegen::Type>(new typegen::Int());
}


Float::Float() { hints = TypesHint(FLOAT); }

bool Float::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Float* t_float = dynamic_cast<const Float*>(&symb);

	return t_float;
}

shared_ptr<typegen::Type> Float::ret_type() const
{
	return shared_ptr<typegen::Type>(new typegen::Float());
}


Void::Void() { hints = TypesHint(VOID); }

bool Void::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const Void* t_void = dynamic_cast<const Void*>(&symb);

	return t_void;
}

shared_ptr<typegen::Type> Void::ret_type() const
{
	return shared_ptr<typegen::Type>(new typegen::Void());
}

String::String() { hints = TypesHint(STRING); }

bool String::equals(const TypeSymbol& symb) const
{
	if(this == &symb) return true;

	const String* t_string = dynamic_cast<const String*>(&symb);

	return t_string;
}

shared_ptr<typegen::Type> String::ret_type() const
{
	return shared_ptr<typegen::Type>(new typegen::String());
}


Function::Function(const vector<reference_wrapper<TypeLink>>& params, TypeLink& ret)
  : return_type(ret),
  	parameters(params)
{
	hints = TypesHint(FUNCTION);
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
	string params;

	if(parameters.size() > 0)
		params = accumulate(next(parameters.begin()), parameters.end(), parameters[0].get().str(),
							[](string& acc, TypeSymbol& symb)
							{
								return acc += ", " + symb.str();
							});

	stringstream ss;
	ss << "Function(" << params << " -> " << return_type.str() << ")";
	return ss.str();
}



UniparameterType::UniparameterType(TypeLink& param_type) : parameter_type(param_type) { }

bool UniparameterType::is_resolved() const 
{
	return parameter_type.is_resolved();
}

Array::Array(TypeLink& type) : UniparameterType(type) { hints = TypesHint(ARRAY); }

string Array::str() const
{
	return "Array( " + parameter_type.str() + " )";
}

bool Array::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	const Array* t_arr = dynamic_cast<const Array*>(&symb);

	return t_arr && parameter_type.equals(t_arr->parameter_type);
}

List::List(TypeLink& type) : UniparameterType(type) { hints = TypesHint(LIST); }

string List::str() const
{
	return "List( " + parameter_type.str() + " )";
}

bool List::equals(const TypeSymbol& symb) const
{
	if(this == &symb)
		return true;

	const List* t_list = dynamic_cast<const List*>(&symb);

	return t_list && parameter_type.equals(t_list->parameter_type);
}

shared_ptr<typegen::Type> List::ret_type() const
{
	shared_ptr<typegen::Type> param = get_param_type().resolve().ret_type();
	return shared_ptr<typegen::Type>(new typegen::List(param));
}

shared_ptr<typegen::Type> Array::ret_type() const
{
	shared_ptr<typegen::Type> param = get_param_type().resolve().ret_type();
	return shared_ptr<typegen::Type>(new typegen::Array(param));
}

shared_ptr<typegen::Type> Function::ret_type() const
{
	shared_ptr<typegen::Type> ret = get_return_type().resolve().ret_type();
	vector<reference_wrapper<TypeLink>> ref =  get_parameters(); 
	vector<shared_ptr<typegen::Type> > to_return;
	for(auto r : ref)
	{
		to_return.push_back(r.get().resolve().ret_type());
	}

	return shared_ptr<typegen::Type>(new typegen::Function(ret, to_return ));
}