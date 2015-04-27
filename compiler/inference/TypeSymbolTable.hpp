#ifndef TYPE_SYMBOL_TABLE_HPP_DEFINED
#define TYPE_SYMBOL_TABLE_HPP_DEFINED

#include <unordered_map>
#include <string>
#include <utility>
#include <memory>
#include <iostream>

#include "TypeSymbol.hpp"

namespace inference
{
	/**
	 * @class TypeSymbolTable
	 * @brief A class for representing the TypeSymbolTable (for type symbols see TypeSymbol.hpp)
	 * A type symbol table maps a type symbol identifier with a TypeLink that is linked to the actual type
	 * element associated with the identifier.
	 * The type identifiers can be of two kinds :
	 *  - type variable : represent a still unresolved type. A unique name can be obtained with the 'unique_varname' function
	 *  - an identifier of a program : a unique name can be obtained with the 'unique_id_name' function
	 */
	class TypeSymbolTable : protected std::unordered_map<std::string, TypeLink>
	{
		friend std::ostream& operator<<(std::ostream&, const TypeSymbolTable&);
	public:
		TypeSymbolTable();

		/**  Functions for creating a new entity in the type symbol table */
		/**
		 * @brief Adds a new variable in the table
		 * @param const std::string& The variable name (optional)
		 * @retval std::string The variable name in the map
		 */
		std::string new_variable();
		std::string new_variable(const std::string&);

		/**
		 * @brief Adds a new function in the table
		 * @param const std::vector<std::string>& param_names Names of the parameters (must be unique)
		 * @param const std::string& name The function name (optional)
		 * @retval std::pair<std::string, std::string> A pair of string of which the first is the name of the function 
		 * and the second is the name of the return type variable
		 */
		std::pair<std::string, std::string> new_function(const std::vector<std::string>&);
		std::pair<std::string, std::string> new_function(const std::vector<std::string>&, const std::string&);

		/**
		 * @brief Adds a new array in the table
		 * @retval std::pair<std::string, std::string> A pair of which the first element is the array name in the map
		 * and the second is the array type name in the map
		 */
		std::pair<std::string, std::string> new_array();

		/**
		 * @brief Adds a new list in the table
		 * @retval std::pair<std::string, std::string> A pair of which the first element is the list name in the map
		 * and the second is the list type name in the map
		 */
		std::pair<std::string, std::string> new_list();

		/**
		 * @brief Return a unique variable name string
		 * @retval std::string A unique variable string
		 */
		std::string unique_varname();

		/**
		 * @brief Get the identifier unique name
		 * @param size_t scope The id of the scope in which is defined the identifier
		 * @param const std::string& The identifier string
		 * @retval std::string The unique string identifiying the identifier
		 */
		std::string unique_id_name(size_t, const std::string&);

		/**
		 * @brief Unify the two types referenced by the given strings
		 * @param const std::string& type1 The first type
		 * @param const std::string& type2 The second type
		 * @throw UnificationException if the unification fails
		 */
		void unify(const std::string&, const std::string&);

		/** 
		 * @brief Unification with a flat type
		 * @param const std::string& type The type symbol to unify with the given flat type
		 */
		void unify_int(const std::string&);
		void unify_float(const std::string&);
		void unify_string(const std::string&);
		void unify_bool(const std::string&);
		void unify_void(const std::string&);
		void unify_char(const std::string&);

	private:
		/**
		 * type_variable_count : count the number of type variable already created
		 */
		int type_variable_count;

		/**
		 * @brief unifify two type links
		 * @param TypeLink& link1 The first link
		 * @param TypeLink& link2 The second link
		 * @throw UnificationException if the unification fails
		 */
		void unify(TypeLink&, TypeLink&);

		/**
		 * @brief Unify the types referenced by the given string with the given flat type
		 * @param const std::string& type The type string reference
		 * @param FlatType* flat A shared pointer containing a pointer to the flat type
		 * @throw UnificationException if the unification fails
		 */
		void unify(const std::string&, FlatType*);
	};

	std::ostream& operator<<(std::ostream&, const TypeSymbolTable&);
}

#endif // TYPE_SYMBOL_TABLE_HPP_DEFINED