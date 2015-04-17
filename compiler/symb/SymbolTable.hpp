#ifndef SYMBOL_TABLE_HPP_DEFINED
#define SYMBOL_TABLE_HPP_DEFINED

#include <string>

#include "ScopeNode.hpp"

namespace symb
{
	template <class S>
	class SymbolTable
	{
	public:
		// construct a symbol table with the root scope as the current scope
		SymbolTable();

		/**
		 * @brief Add a new symbol in the current scope table
		 * @param const std::string& symbol The symbol
		 * @param const S& data The data associated with the symbol
		 * @note Previously add symbol with the same name is discarded
		 */
		void add_symbol(const std::string&, const S& data);

		/**
		 * @brief Checks whether a given symbol exists in the current scope
		 * @param const std::string& symbol The symbol
		 * @retval bool True if the symbol exists, false otherwise
		 */
		bool symbol_exists(const std::string&);

		/**
		 * @brief Deletes the given symbol from the current scope table
		 * @param const std::string& symb_name The symbol 
		 */
		void delete_symbol(const std::string&);

		/**
		 * @brief Return the information associated with the given symbol
		 * @param const std::string& symb_name The symbol name
		 * @retval S& The object containing the information about the given symbol
		 * @throw UndefinedSymbolException If the symbol does not exist
		 */
		S& symbol_info(const std::string&);
		const S& symbol_info(const std::string&) const;
		/**
		* @brief creates a new scope adds it as a child scope of the current scope
		* @return the new scope's id
		*/
		int add_scope();

		// Displacement function : move_to another scope
		void move_to_scope(size_t scope_id);
		void move_to_parent_scope();
		void move_to_child_scope(int child_number);
		void move_to_root_scope();

		/**
		 * @brief Generate a brand new unique scope identifier
		 * @retval size_t The scope identifier
		 */
		static size_t new_scope_id();

	private:
		/** 
		 * root_scope : the root scope object
		 * current_scope : a reference to the scope the symbol table is currently in
		 * scope_id_counter : a counter for generating unique scope identifiers
		 */
		ScopeNode<S> root_scope;
		ScopeNode<S>& current_scope;
		static size_t scope_id_counter;
	};

	template <class S>
	size_t SymbolTable<S>::scope_id_counter = 1;

	template <class S>
	size_t SymbolTable<S>::new_scope_id() 
	{
		return scope_id_counter++;
	}

	template <class S>
	SymbolTable<S>::SymbolTable() : root_scope(new_scope_id()), current_scope(root_scope)
	{

	}

	template <class S>
	void SymbolTable<S>::add_symbol(const std::string& symbol, const S& data)
	{
		current_scope.add_symbol(symbol, data);
	}

	template <class S>
	bool SymbolTable<S>::symbol_exists(const std::string& symbol)
	{
		if(current_scope.symbol_exists(symbol))
			return true;

		ScopeNode<S>& iter_scope = current_scope;
		
		while(iter_scope.has_parent())
		{
			iter_scope = iter_scope.get_parent();
			if(iter_scope.symbol_exists(symbol))
				return true;
		}

		return false;
	}

	template <class S>
	void SymbolTable<S>::delete_symbol(const std::string& symbol)
	{
		current_scope.delete_symbol(symbol);
	}

	template <class S>
	S& SymbolTable<S>::symbol_info(const std::string& symbol)
	{
		if(current_scope.symbol_exists(symbol))
			return current_scope.symbol_info(symbol);

		ScopeNode<S>& iter_scope = current_scope;
		
		while(iter_scope.has_parent())
		{
			iter_scope = iter_scope.get_parent();
			if(iter_scope.symbol_exists(symbol))
				return iter_scope.symbol_info(symbol);
		}

		throw except::UndefinedSymbolException(symbol);
	}

	template <class S>
	const S& SymbolTable<S>::symbol_info(const std::string& symbol) const
	{
		if(current_scope.symbol_exists(symbol))
			return current_scope.symbol_info(symbol);

		ScopeNode<S>& iter_scope = current_scope;
		
		while(iter_scope.has_parent())
		{
			iter_scope = iter_scope.get_parent();
			if(iter_scope.symbol_exists(symbol))
				return iter_scope.symbol_info(symbol);
		}

		throw except::UndefinedSymbolException(symbol);
	}


	template <class S>
	void SymbolTable<S>::add_scope()
	{
		return current_scope.create_child_scope(new_scope_id());
	}

	template <class S>
	void SymbolTable<S>::move_to_scope(size_t scope_id)
	{
		current_scope = root_scope.find_scope(scope_id);
	}

	template <class S>
	void SymbolTable<S>::move_to_parent_scope()
	{
		current_scope = current_scope.get_parent();
	}

	template <class S>
	void SymbolTable<S>::move_to_child_scope(int child_number)
	{
		current_scope = current_scope.get_child(child_number);
	}

	template <class S>
	void SymbolTable<S>::move_to_root_scope()
	{
		current_scope = root_scope;
	}

}

#endif // SYMBOL_TABLE_HPP_DEFINED