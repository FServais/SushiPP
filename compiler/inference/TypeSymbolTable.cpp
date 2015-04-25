#include "TypeSymbolTable.hpp"

#include <utility>

#include "../../exceptions/Exceptions.hpp"

using namespace std;
using namespace inference;

TypeSymbolTable::TypeSymbolTable()
  : type_variable_count(0)
{

}

std::string TypeSymbolTable::new_variable()
{
	return new_variable(unique_varname());
}

std::string TypeSymbolTable::new_variable(const std::string& varname)
{
	if(count(varname) == 1)
		throw except::ExistingTypeSymbolException(varname);

	// add the variable into the map
	shared_ptr<TypeVariable> var(new TypeVariable(varname));
	shared_ptr<TypeLink> link(new TypeLink(var));

	(*this)[varname] = link;

	return varname;
}

std::string TypeSymbolTable::new_function(const std::vector<std::string>& param_names, size_t scope)
{
	return new_function(param_names, scope, unique_varname());
}

std::string TypeSymbolTable::new_function(const std::vector<std::string>& param_names, size_t scope, const std::string& func_name)
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

std::pair<std::string, std::string> TypeSymbolTable::new_array()
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

std::pair<std::string, std::string> TypeSymbolTable::new_list()
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

void TypeSymbolTable::unify(const std::string&, const std::string&)
{

}

void TypeSymbolTable::unify(const std::string&, const std::string&)
{

}

std::string TypeSymbolTable::unique_varname()
{
	return to_string(type_variable_count++);
}

std::string TypeSymbolTable::unique_id_name(size_t scope, const std::string& identfier)
{
	return identfier + "@" + to_string(scope);
}

namespace inference
{
    std::ostream& operator<<(std::ostream& out, const TypeSymbolTable& table)
    {
        for(auto symbol : table)
            out << symbol.first << " => " << symbol.second->str() << endl;

        return out;
    }
}