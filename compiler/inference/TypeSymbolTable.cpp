#include "TypeSymbolTable.hpp"

#include <utility>
#include <algorithm>
#include <iterator>
#include <map>

#include "../exceptions/Exceptions.hpp"

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
	emplace(piecewise_construct, 
			forward_as_tuple(varname), 
			forward_as_tuple(new TypeVariable(varname)));

	return varname;
}

pair<string, string> TypeSymbolTable::new_function(const vector<string>& param_names)
{
	return new_function(param_names, unique_varname());
}

pair<string, string> TypeSymbolTable::new_function(const vector<string>& param_names, const string& func_name)
{
	if(count(func_name) == 1)
		throw except::ExistingTypeSymbolException(func_name);

	// build the parameter link vector
	vector<reference_wrapper<TypeLink>> param_links;

	for(auto param_name : param_names)
	{
		new_variable(param_name); // add the parameter's variable into the map
		param_links.push_back(at(param_name)); // save the link for initializing the function type object
	}

	// create a type variable for the return type and add it into the map
	string ret_type_var = new_variable(unique_varname());

	emplace(piecewise_construct, 
			forward_as_tuple(func_name), 
			forward_as_tuple(new Function(param_links, at(ret_type_var))));

	return make_pair(func_name, ret_type_var);
}

pair<string, string> TypeSymbolTable::new_array()
{
	// create the array type entry in the map
	string array_type_varname = new_variable(unique_varname());

	// create the array entry
	string array_name = unique_varname();

	emplace(piecewise_construct,
			forward_as_tuple(array_name), 
			forward_as_tuple(new Array(at(array_type_varname))));

	return make_pair(array_name, array_type_varname);
}

pair<string, string> TypeSymbolTable::new_list()
{
	// create the list type entry in the map
	string list_type_varname = new_variable(unique_varname());

	// create the array entry
	string list_name = unique_varname();
	
	emplace(piecewise_construct,
			forward_as_tuple(list_name), 
			forward_as_tuple(new List(at(list_type_varname))));

	return make_pair(list_name, list_type_varname);
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
    	// sort the indexes
    	map<TypeSymbolTable::key_type, string> omap;
        
        for(auto& symbol : table)
        	omap[symbol.first] = symbol.second.str();

        for(auto& symbol : omap)
            out << symbol.first << " => " << symbol.second << endl;

        return out;
    }
}

void TypeSymbolTable::unify_int(const std::string& type)
{
	unify(type, new Int);
}

void TypeSymbolTable::unify_float(const std::string& type)
{
	unify(type, new Float);
}

void TypeSymbolTable::unify_string(const std::string& type)
{
	unify(type, new String);
}

void TypeSymbolTable::unify_bool(const std::string& type)
{
	unify(type, new Bool);
}

void TypeSymbolTable::unify_void(const std::string& type)
{
	unify(type, new Void);
}

void TypeSymbolTable::unify_char(const std::string& type)
{
	unify(type, new Char);
}


void TypeSymbolTable::unify(const string& type1, const string& type2)
{
	if(count(type1) == 0)
		throw except::NoSuchTypeSymbolException(type1);

	if(count(type2) == 0)
		throw except::NoSuchTypeSymbolException(type2);

	unify(at(type1), at(type2));
}

void TypeSymbolTable::unify(TypeLink& link1, TypeLink& link2)
{
	// extract actual pointed symbols and last links
	TypeSymbol &symbol1 = link1.resolve(),
			   &symbol2 = link2.resolve();

	// one or both symbol(s) is (are) variable(s)
	if(symbol1.is_variable() || symbol2.is_variable())
	{
		if(symbol1.equals(symbol2)) // the variables were already unified
			return;

		TypeLink &last_link1 = link1.resolve_last_link(),
				 &last_link2 = link2.resolve_last_link();

		// relink the variable to the last link type of the other link
		TypeLink &to_relink = symbol1.is_variable() ? last_link1 : last_link2,
				 &to_be_linked = symbol1.is_variable() ? last_link2 : last_link1;

		to_relink.set_symbol(&to_be_linked);
		return;
	}

	// symbols are both function
	if(symbol1.is_function_type() && symbol2.is_function_type())
	{
		Function &func_symb1 = dynamic_cast<Function&>(symbol1),
				 &func_symb2 = dynamic_cast<Function&>(symbol2);

		// unify the parameters type
		vector<reference_wrapper<TypeLink>> &parameters1 = func_symb1.get_parameters(),
                                     	    &parameters2 = func_symb2.get_parameters();

		if(parameters1.size() != parameters1.size())
			throw except::UnificationException("couldn't unify function types because of an parameter count mismatch "
											   "(function 1 expects " + to_string(parameters1.size()) + " parameter(s) and "
											   "function 2 expects " + to_string(parameters2.size()) + " parameter(s))");

		for(size_t i = 0; i < parameters1.size(); ++i)
			unify(parameters1[i], parameters2[i]);

		// unify the function return type
		unify(func_symb1.get_return_type(), func_symb2.get_return_type());
		return;
	}

	// are either arrays or a lists or both
	if(symbol1.is_uniparameter_type() && symbol2.is_uniparameter_type())
	{
		UniparameterType &structure_symb1 = dynamic_cast<UniparameterType&>(symbol1),
				 		 &structure_symb2 = dynamic_cast<UniparameterType&>(symbol2);

		// if they are different -> unification of a list type and an array type : error
		if(structure_symb1.is_array() != structure_symb2.is_array())
			throw except::UnificationException("couldn't unify two different datastructure types. Here : '" +
												structure_symb1.str() + "' and '" + structure_symb2.str() + "'");

		// unify the only parameter type
		unify(structure_symb1.get_param_type(), structure_symb2.get_param_type());
		return;
	}

	// are both flat types
	if(symbol1.is_flat_type() && symbol2.is_flat_type())
	{
		if(!symbol1.equals(symbol2))
			throw except::UnificationException("couldn't unify two different flat types '" + symbol1.str() + "' and '" + symbol2.str() + "'");
		return; // unification succeeds as the flat type are the same
	}

	// at this point, any unifiable combination was examined and there is no more way to unify the given type links
	throw except::UnificationException("couldn't unify the given types '" + symbol1.str() + "' and '" + symbol2.str() + "'");
}

void TypeSymbolTable::unify(const string& type, FlatType* flat)
{
	if(count(type) == 0)
		throw except::NoSuchTypeSymbolException(type);

	TypeLink& link = at(type);
	TypeSymbol& actual_type = link.resolve();
	string err_type(flat->str());

	// if the type mapped by the symbol is an array, list or function type
	// unification is impossible
	if(actual_type.is_structured_type())
	{
		delete flat;
		throw except::UnificationException("couln't unify flat type '" + err_type + "' with structured type '" + actual_type.str() + "'");
	}
	// if the type mapped is a flat type, it must be the same than the other
	if(actual_type.is_flat_type())
	{
		delete flat;
		if(flat->equals(actual_type))
			throw except::UnificationException("couldn't unify two different flat types '" + err_type + "' and '" + actual_type.str() + "'");
		return;
	}

	// set the last link
	link.resolve_last_link().set_symbol(flat);
}