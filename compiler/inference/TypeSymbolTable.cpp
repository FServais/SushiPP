#include "TypeSymbolTable.hpp"

#include <utility>

#include "../../exceptions/Exceptions.hpp"

using namespace std;
using namespace inference;

TypeSymbolTable::TypeSymbolTable()
  : type_variable_count(0)
{

}

string TypeSymbolTable::new_variable()
{
	return new_variable(unique_varname());
}

string TypeSymbolTable::new_variable(const string& varname)
{
	if(count(varname) == 1)
		throw except::ExistingTypeSymbolException(varname);

	// add the variable into the map
	shared_ptr<TypeVariable> var(new TypeVariable(varname));
	shared_ptr<TypeLink> link(new TypeLink(var));

	(*this)[varname] = link;

	return varname;
}

string TypeSymbolTable::new_function(const vector<string>& param_names, size_t scope)
{
	return new_function(param_names, scope, unique_varname());
}

string TypeSymbolTable::new_function(const vector<string>& param_names, size_t scope, const string& func_name)
{
	if(count(func_name) == 1)
		throw except::ExistingTypeSymbolException(func_name);

	// build the parameter link vector
	vector<shared_ptr<TypeLink>> param_links;

	for(auto param_name : param_names)
	{
		string final_name = unique_id_name(scope, param_name);
		new_variable(final_name); // add the parameter into the map
		param_links.push_back(at(final_name)); // save the link for initializing the function type object
	}

	// create a type variable for the return type add it into the map
	string ret_type_var = new_variable(unique_varname());

	// create the function type entity and add it to the map
	shared_ptr<Function> func_type(new Function(param_links, at(ret_type_var)));
	shared_ptr<TypeLink> func_link(new TypeLink(func_type));

	(*this)[func_name] = func_link;

	return func_name;
}

pair<string, string> TypeSymbolTable::new_array()
{
	// create the array type entry in the map
	string array_type_varname = new_variable(unique_varname());

	// create the array entry
	shared_ptr<Array> array_type(new Array(at(array_type_varname)));
	shared_ptr<TypeLink> array_link(new TypeLink(array_type));

	string array_name = unique_varname();

	(*this)[array_name] = array_link;

	return pair<string,string>(array_name, array_type_varname);
}

pair<string, string> TypeSymbolTable::new_list()
{
	// create the list type entry in the map
	string list_type_varname = new_variable(unique_varname());

	// create the list entry
	shared_ptr<List> list_type(new List(at(list_type_varname)));
	shared_ptr<TypeLink> list_link(new TypeLink(list_type));

	string list_name = unique_varname();

	(*this)[list_name] = list_link;

	return pair<string,string>(list_name, list_type_varname);
}

string TypeSymbolTable::unique_varname()
{
	return to_string(type_variable_count++);
}

string TypeSymbolTable::unique_id_name(size_t scope, const string& identfier)
{
	return identfier + "@" + to_string(scope);
}

namespace inference
{
    ostream& operator<<(ostream& out, const TypeSymbolTable& table)
    {
        for(auto symbol : table)
            out << symbol.first << " => " << symbol.second->str() << endl;

        return out;
    }
}
	
shared_ptr<Int> TypeSymbolTable::flat_int()
{
	if(!p_flat_int)
		p_flat_int = shared_ptr<Int>(new Int);
	return p_flat_int;
}

shared_ptr<Bool> TypeSymbolTable::flat_bool()
{
	if(!p_flat_bool)
		p_flat_bool = shared_ptr<Bool>(new Bool);
	return p_flat_bool;
}

shared_ptr<String> TypeSymbolTable::flat_string()
{
	if(!p_flat_string)
		p_flat_string = shared_ptr<String>(new String);
	return p_flat_string;
}

shared_ptr<Char> TypeSymbolTable::flat_char()
{
	if(!p_flat_char)
		p_flat_char = shared_ptr<Char>(new Char);
	return p_flat_char;
}

shared_ptr<Float> TypeSymbolTable::flat_float()
{
	if(!p_flat_float)
		p_flat_float = shared_ptr<Float>(new Float);
	return p_flat_float;
}

shared_ptr<Void> TypeSymbolTable::flat_void()
{
	if(!p_flat_void)
		p_flat_void = shared_ptr<Void>(new Void);
	return p_flat_void;
}

void TypeSymbolTable::unify(const string& type1, const string& type2)
{

}

void TypeSymbolTable::unify(const string& type, shared_ptr<FlatType> flat)
{
	if(count(type) == 0)
		throw except::NoSuchTypeSymbolException(type);

	TypeLink& link = *at(type);
	TypeSymbol& actual_type = link.resolve();

	// if the type mapped by the symbol is an array, list or function type
	// unification is impossible
	if(actual_type.is_function_type() || actual_type.is_structure_type())
		throw except::UnificationException("couln't unify flat type '" + flat->str() + "' with type '" + actual_type.str() + "'");

	// if the type mapped is a flat type, it must be the same than the other
	if(actual_type.is_flat_type())
	{
		if(flat->equals(actual_type))
			throw except::UnificationException("couldn't unify two different flat types '" + flat->str() + "' and ' " + actual_type.str() + " '");
		return;
	}

	// set the last link
	link.resolve_last_link().set_symbol(flat);
}

void TypeSymbolTable::unify(shared_ptr<FlatType> flat, const string& type)
{
	unify(type, flat);
}

void TypeSymbolTable::unify(const std::string& type, std::shared_ptr<inference::Array> array)
{

}

void TypeSymbolTable::unify(std::shared_ptr<inference::Array> array, const std::string& type)
{
	unify(type, array);
}

void TypeSymbolTable::unify(const std::string& type, std::shared_ptr<inference::List> list)
{

}

void TypeSymbolTable::unify(std::shared_ptr<inference::List> list, const std::string& type)
{
	unify(type, list);
}
