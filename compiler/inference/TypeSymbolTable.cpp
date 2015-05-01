#include "TypeSymbolTable.hpp"

#include <utility>
#include <algorithm>
#include <iterator>
#include <map>

#include "InferenceExceptions.hpp"
#include "Types.hpp"

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
	TypesHint hint;
	hint.remove(VOID);
	return new_variable(varname, hint);
}

string TypeSymbolTable::new_variable(const vector<ShallowType>& types)
{
	return new_variable(unique_varname(), types);
}

string TypeSymbolTable::new_variable(const string& varname, const vector<ShallowType>& types)
{
	return new_variable(varname, TypesHint(types));
}

string TypeSymbolTable::new_variable(const TypesHint& hint)
{
	return new_variable(unique_varname(), hint);
}

string TypeSymbolTable::new_variable(const string& varname, const TypesHint& hint)
{
	if(count(varname) == 1)
		throw except::ExistingTypeSymbolException(varname);

	// add the variable into the map
	emplace(piecewise_construct, 
			forward_as_tuple(varname), 
			forward_as_tuple(new TypeVariable(varname)));

	// type of the variable can be anything except void
	dynamic_cast<TypeVariable&>(at(varname).resolve()).set_hints(hint);

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

	// a function can return void
	dynamic_cast<TypeVariable&>(at(ret_type_var).resolve()).set_hints(TypesHint());

	return make_pair(func_name, ret_type_var);
}

pair<string, string> TypeSymbolTable::new_function(const vector<string>& param_names, const vector<ShallowType>& hints)
{
	return new_function(param_names, unique_varname(), hints);
}

pair<string, string> TypeSymbolTable::new_function(const vector<string>& param_names, const string& func_name, const vector<ShallowType>& hints)
{
	pair<string, string> func_type_names = new_function(param_names, func_name);

	for(size_t i = 0; i < hints.size(); ++i)
		unify(param_names[i], hints[i]);
	
	return func_type_names;
}


pair<string, string> TypeSymbolTable::new_array()
{
	// create the array type entry in the map
	int array_type_hints = FLOAT | INT | BOOL | STRING | CHAR;
	string array_type_varname = new_variable(TypesHint(array_type_hints));

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
	int list_type_hints = FLOAT | INT | BOOL | STRING | CHAR;
	string list_type_varname = new_variable(TypesHint(list_type_hints));

	// create the list entry
	string list_name = unique_varname();
	
	emplace(piecewise_construct,
			forward_as_tuple(list_name), 
			forward_as_tuple(new List(at(list_type_varname))));

	return make_pair(list_name, list_type_varname);
}

string TypeSymbolTable::unique_varname()
{
	return std::to_string(type_variable_count++);
}

string TypeSymbolTable::unique_id_name(size_t scope, const string& identfier)
{
	return identfier + "@" + std::to_string(scope);
}

namespace inference
{
    ostream& operator<<(ostream& out, const TypeSymbolTable& table)
    {  
    	// sort the indexes
    	map<TypeSymbolTable::key_type, string> omap;
        
        for(auto& symbol : table)
        	omap[symbol.first] = symbol.second.str() + " (hints : " + symbol.second.resolve().get_hints().str() + ")";

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
	TerminalTypeSymbol &symbol1 = link1.resolve(),
			   		   &symbol2 = link2.resolve();

	// one or both symbol(s) is (are) variable(s)
	if(symbol1.is_variable() || symbol2.is_variable())
	{
		if(symbol1.equals(symbol2)) // the variables were already unified
			return;

			// check hints compatiblity
		if(!symbol1.get_hints().compatible(symbol2.get_hints()))
			throw except::HintsUnificationException(symbol1.get_hints(), symbol2.get_hints());

		TypeLink &last_link1 = link1.resolve_last_link(),
				 &last_link2 = link2.resolve_last_link();

		// relink the variable to the last link type of the other link
		TypeLink &to_relink = symbol1.is_variable() ? last_link1 : last_link2,
				 &to_be_linked = symbol1.is_variable() ? last_link2 : last_link1;

		// update the hints
		if(symbol1.is_variable())
			dynamic_cast<TypeVariable&>(symbol1).get_hints().hints_intersection(symbol2.get_hints());
		if(symbol2.is_variable())
			dynamic_cast<TypeVariable&>(symbol2).get_hints().hints_intersection(symbol1.get_hints());

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

		if(parameters1.size() != parameters2.size())
			throw except::ParameterNumberMismatchException(parameters1.size(), parameters2.size());

		for(size_t i = 0; i < parameters1.size(); ++i)
			unify(parameters1[i], parameters2[i]);

		// unify the function return type
		unify(func_symb1.get_return_type(), func_symb2.get_return_type());
		return;
	}
	else if(symbol1.is_function_type())
		throw except::FunctionTypeUnificationException(dynamic_cast<Function&>(symbol1), symbol2);
	else if(symbol2.is_function_type())
		throw except::FunctionTypeUnificationException(dynamic_cast<Function&>(symbol2), symbol1);

	// are either arrays or a lists or both
	if(symbol1.is_uniparameter_type() && symbol2.is_uniparameter_type())
	{
		UniparameterType &structure_symb1 = dynamic_cast<UniparameterType&>(symbol1),
				 		 &structure_symb2 = dynamic_cast<UniparameterType&>(symbol2);

		// if they are different -> unification of a list type and an array type : error
		if(structure_symb1.is_array() != structure_symb2.is_array())
			throw except::UniparameterTypesUnificationException(structure_symb1, structure_symb2);

		// unify the only parameter type
		unify(structure_symb1.get_param_type(), structure_symb2.get_param_type());
		return;
	}
	else if(symbol1.is_uniparameter_type())
		throw except::UniparameterTypesUnificationException(dynamic_cast<UniparameterType&>(symbol1), symbol2);
	else if(symbol2.is_uniparameter_type())
		throw except::UniparameterTypesUnificationException(dynamic_cast<UniparameterType&>(symbol2), symbol1);
	
	// at this stage, both symbol must be flat types 
	if(!symbol1.equals(symbol2))
		throw except::FlatTypesUnificationException(dynamic_cast<FlatType&>(symbol1), symbol2);
	
	// flat type are the same at this stage
}

void TypeSymbolTable::unify(const string& type, FlatType* flat)
{
	if(count(type) == 0)
		throw except::NoSuchTypeSymbolException(type);

	TypeLink& link = at(type);
	TerminalTypeSymbol& actual_type = link.resolve();
	string err_type(flat->str());

	// if the type mapped by the symbol is an array, list or function type
	// unification is impossible
	if(actual_type.is_structured_type())
	{
		except::FlatTypesUnificationException exception(*flat, actual_type);
		delete flat;
		throw exception;
	}

	// if the type mapped is a flat type, it must be the same than the other
	if(actual_type.is_flat_type())
	{
		if(!flat->equals(actual_type))
		{
			except::FlatTypesUnificationException exception(*flat, actual_type);
			delete flat;
			throw exception;
		}

		delete flat;
		return;
	}

	// check hints compatibility :
	if(!flat->get_hints().compatible(actual_type.get_hints()))
	{
		except::HintsUnificationException exception(flat->get_hints(), actual_type.get_hints());
		delete flat;
		throw exception;
	}	

	// set the last link
	link.resolve_last_link().set_symbol(flat);
}

void TypeSymbolTable::update_hints(const std::string& varname, const TypesHint& hints)
{
	TerminalTypeSymbol& symbol = at(varname).resolve();

	if(!symbol.is_variable())
		throw except::NoSuchTypeSymbolException("hints update can only be performed on type variables. " + varname + " is not a type variable.");
		
	// check compatibility between hints
	TypeVariable& var = dynamic_cast<TypeVariable&>(symbol);

	if(!var.get_hints().compatible(hints))
		throw except::UnificationException("couldn't update the hints of the type variable " + symbol.str() + 
										   " because of incompatibility between the variable's hints (" + var.get_hints().str() +
										   ") and the given hints (" + hints.str() + ")");
	
	var.get_hints().hints_intersection(hints);
}

void TypeSymbolTable::unify(const std::string& type_str, ShallowType s_type)
{
	switch(s_type)
	{
	case INT: unify_int(type_str); break;
	case FLOAT: unify_float(type_str); break;
	case VOID: unify_void(type_str); break;
	case STRING: unify_string(type_str); break;
	case BOOL: unify_bool(type_str); break;
	case CHAR: unify_char(type_str); break;
	case NO_TYPE: break;
	default: 
		update_hints(type_str, TypesHint(s_type));
		break;
	}
}