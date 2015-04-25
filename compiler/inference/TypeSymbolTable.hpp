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
	class TypeSymbolTable : public std::unordered_map<std::string, std::shared_ptr<TypeLink>>
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
		 * @param const std::vector<std::string>& param_names Names of the parameters 
		 * @param size_t scope The scope id 
		 * @param const std::string& name The function name (optional)
		 * @retval std::string The function name in the map
		 */
		std::string new_function(const std::vector<std::string>&, size_t);
		std::string new_function(const std::vector<std::string>&, size_t, const std::string&);

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

		/** Getters for flat types */
		std::shared_ptr<inference::Int> flat_int();
		std::shared_ptr<inference::Bool> flat_bool();
		std::shared_ptr<inference::String> flat_string();
		std::shared_ptr<inference::Char> flat_char();
		std::shared_ptr<inference::Float> flat_float();
		std::shared_ptr<inference::Void> flat_void();

		/**
		 * @brief Unify the two types referenced by the given strings
		 * @param const std::string& type1 The first type 
		 * @param const std::string& type2 The second type
		 * @throw UnificationException if the unification fails
		 */
		void unify(const std::string&, const std::string&);
		/**
		 * @brief Unify the types referenced by the given string with the given flat type
		 * @param const std::string& type The type string reference
		 * @param std::shared_ptr<*> flat A shared pointer containing a pointer to the flat type *	
		 * @throw UnificationException if the unification fails
		 */
		void unify(const std::string&, std::shared_ptr<inference::FlatType>);
		/*void unify(const std::string&, std::shared_ptr<inference::Bool>);
		void unify(const std::string&, std::shared_ptr<inference::String>);
		void unify(const std::string&, std::shared_ptr<inference::Char>);
		void unify(const std::string&, std::shared_ptr<inference::Float>);
		void unify(const std::string&, std::shared_ptr<inference::Void>);*/
		void unify(std::shared_ptr<inference::FlatType>, const std::string&);
		/*void unify(std::shared_ptr<inference::Bool>, const std::string&);
		void unify(std::shared_ptr<inference::String>, const std::string&);
		void unify(std::shared_ptr<inference::Char>, const std::string&);
		void unify(std::shared_ptr<inference::Float>, const std::string&);
		void unify(std::shared_ptr<inference::Void>, const std::string&);*/

	private:
		/**
		 * type_variable_count : count the number of type variable already created
		 */
		int type_variable_count; 

		/**
		 * Keep only one copy of every kind of flat type objects (to save memory)
		 */
		std::shared_ptr<Int> p_flat_int;
		std::shared_ptr<Bool> p_flat_bool;
		std::shared_ptr<String> p_flat_string;
		std::shared_ptr<Char> p_flat_char;
		std::shared_ptr<Float> p_flat_float;
		std::shared_ptr<Void> p_flat_void;
	};

	std::ostream& operator<<(std::ostream&, const TypeSymbolTable&);
}

#endif // TYPE_SYMBOL_TABLE_HPP_DEFINED