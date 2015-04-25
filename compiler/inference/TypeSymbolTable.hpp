#ifndef TYPE_SYMBOL_TABLE_HPP_DEFINED
#define TYPE_SYMBOL_TABLE_HPP_DEFINED

#include <unordered_map>
#include <functionnal>
#include <string>
#include <utility>

#include "TypeSymbol.hpp"

namespace inference
{
	class TypeSymbolTable : public std::unordered_map<std::string, std::reference_wrapper<TypeLink>>
	{
	public:

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
		 * @param const std::string& The function name (optional)
		 * @retval std::string The function name in the map
		 */
		std::string new_function();
		std::string new_function(const std::string&);

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
		 * @brief Unify the two types referenced by the given strings
		 * @param const std::string& type1 The first type 
		 * @param const std::string& type2 The second type
		 * @throw UnificationException if the unification fails
		 */
		void unify(const std::string&, const std::string&);

	private:
		/**
		 * type_variable_count : count the number of type variable already created
		 */
		int type_variable_count; 

		/** Common flat types objects */
		inference::Int type_int;
		inference::Bool type_bool;
		inference::String type_string;
		inference::Char type_char;
		inference::Float type_float;
		inference::Void type_void;
	};
}

#endif // TYPE_SYMBOL_TABLE_HPP_DEFINED