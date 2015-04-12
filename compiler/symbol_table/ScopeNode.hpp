#ifndef SCOPE_NODE_HPP_DEFINED
#define SCOPE_NODE_HPP_DEFINED

#include <string>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <memory>

#include "../exceptions/Exceptions.hpp"

namespace symb
{
	template <class S>
	class ScopeNode 
	{
	public:
		// constructors
		ScopeNode(unsigned int scope_id);

		// copy constructor and assignment operator perform a deep copy
		ScopeNode(const ScopeNode&);
		ScopeNode<S>& operator=(const ScopeNode&);

		// destructor
		~ScopeNode();

		/**
		 * @brief Checks whether the given symbol exists
		 * @param const std::string& symb_name The symbol name
		 * @retval bool True if the symbol exists, false otherwise
		 */
		bool symbol_exists(const std::string&) const;

		/**
		 * @brief Return the information associated with the given symbol
		 * @param const std::string& symb_name The symbol name
		 * @retval S& The object containing the information about the given symbol
		 * @throw UndefinedSymbolException If the symbol does not exist
		 */
		S& symbol_info(const std::string&);

		/**
		 * @brief See the non-const version of the function
		 */
		const S& symbol_info(const std::string&) const;

		/**
		 * @brief Deletes the given symbol from the current scope table
		 * @param const std::string& symb_name The symbol name
		 */
		void delete_symbol(const std::string&) const;
		
		/**
		 * @brief Adds a new symbol in the current scopenode map
		 * @param const std::string& symb_name The new symbol's name
		 * @param const S& data The information about the symbol
		 * @note Previous data associated with a symbol of the same name is discarded
		 */
		void add_symbol(const std::string&, const S& data) const;

		/**
		 * @brief Create a new child scope 
		 * @param int pos The position at which the new scope must be inserted (optionnal, default: inserted as last child)
		 * @retval unsigned long The new identifier of the node
		 * @throw out_of_range If the given position is invalid
		 */
		unsigned long create_child_scope(int);

		/**
		 * @brief Find and return the scope having the given scope id 
		 * @param unsigned int id The scope id
		 * @retval ScopeNode& The scope node having the given id
		 * @note The scope node is searched recursively in the children 
		 * @throw UndefinedScopeException If the scope is not found
		 */
		ScopeNode<S>& find_scope(unsigned int);

		/**
		 * @brief See the non*const version of the find_scope function
		 */
		const ScopeNode<S>& find_scope(unsigned int) const;

		/**
		 * @brief Return the identifier of the node
		 */
		unsigned long get_id() const;

		/**
		 * @brief Return the parent of the given scope node
		 * @retval ScopeNode& a reference to the ScopeNode parent object
		 * @throw UndefinedScopeException If the current ScopeNode has no parent
		 */
		ScopeNode<S>& get_parent();
		const ScopeNode<S>& get_parent() const;

		/**
		 * @brief Check whether the current node has a parent
		 * @retval bool True if the current node has a parent, false otherwise
		 */
		bool has_parent() const;

		/**
		 * @brief Return the posth child of the current ScopeNode
		 * @param int pos The position of the child to return (in [0, size[)
		 */
		ScopeNode<S>& get_child(int pos);
		const ScopeNode& get_child(int pos);


	private:
		/**
		 * map : structure mapping symbols with symbol data
		 * scope_id : the id of the scope 
		 * scope_id_counter : counter for generating he scope ids
		 * children : children scopes
		 * parent : parent scope
		 */

		std::unordered_map<std::string, S> map;
		std::vector<ScopeNode*> children;
		ScopeNode* parent; 
		unsigned long scope_id;

		/**
		 * @brief Free the memory allocated for the children
		 */
		void free_children();
	};



	template <class S>
	ScopeNode<S>::ScopeNode(unsigned long scope_id_) : parent(nullptr), scope_id(scope_id_)
	{

	}

	template <class S>
	ScopeNode<S>::ScopeNode(const ScopeNode& copy) 
	  : map(copy.map),
		parent(nullptr),
		scope_id(copy.scope_id)
	{
		for(ScopeNode* scope : copy.children)
		{
			ScopeNode* new_scope = new ScopeNode(*scope);
			children.add_child_scope(new_scope);
		}
	}

	template <class S>
	ScopeNode<S>::ScopeNode& operator=(const ScopeNode& copy)
	{
		// free the memory allocated for the current ScopeNode
		free_children();
		children.clear();

		map = copy.map;
		scope_id = copy.scope_id;
		parent = nullptr;

		// copy the children
		for(ScopeNode* scope : copy.children)
		{
			ScopeNode* new_scope = new ScopeNode(*scope);
			children.add_child_scope(new_scope);
		}
	}

	template <class S>
	ScopeNode<S>::~ScopeNode()
	{
		free_children();
	}

	template <class S>
	bool ScopeNode<S>::symbol_exists(const std::string& symb_name) const
	{
		return map.count(symb_name) > 0;
	}

	template <class S>
	S& ScopeNode<S>::symbol_info(const std::string& symb_name)
	{
		if(!symbol_exists(symb_name))
			throw UndefinedSymbolException(symb_name);

		return *(map.find(symb_name));
	}

	template <class S>
	const S& ScopeNode<S>::symbol_info(const std::string&) const
	{
		if(!symbol_exists(symb_name))
			throw UndefinedSymbolException(symb_name);

		return *(map.find(symb_name));		
	}

	template <class S>
	void ScopeNode<S>::delete_symbol(const std::string& symb_name) const
	{
		map.erase(symb_name);
	}

	template <class S>
	void ScopeNode<S>::add_symbol(const std::string& symb_name, const S& data) const
	{
		map[symb_name] = data;
	}

	template <class S>
	unsigned long ScopeNode<S>::create_child_scope(unsigned long scope_id_, int pos = -1)
	{
		if(pos > children.size() || pos < -1)
			throw std::out_of_range("The new scope must inserted in the range of existing children.");

		if(pos == -1)
			pos = children.size();

		ScopeNode* new_scope = new ScopeNode(scope_id);
		children.insert(std::next(children.begin(), pos), new_scope);
		new_scope->parent = this;
		return new_scope->get_id();
	}

	template <class S>
	ScopeNode<S>& ScopeNode<S>::find_scope(unsigned int id)
	{
		if(id == scope_id)
			return *this;

		for(ScopeNode* child : children)
		{
			try
			{
				return child->find_scope(id);
			}
			catch(exceptions::UndefinedScopeException& e) { }
		}

		throw exceptions::UndefinedScopeException(id);
	}

	template <class S>
	const ScopeNode<S>& ScopeNode<S>::find_scope(unsigned int) const
	{
		if(id == scope_id)
			return *this;

		for(ScopeNode* child : children)
		{
			try
			{
				return child->find_scope(id);
			}
			catch(exceptions::UndefinedScopeException& e) { }
		}

		throw exceptions::UndefinedScopeException(id);
	}

	template <class S>
	const void ScopeNode<S>::free_children()
	{
		std::for_each(children.begin(), children.end(), std::default_delete<ScopeNode>());
	}

	template <class S>
	unsigned long ScopeNode<S>::get_id() const
	{
		return scope_id;
	}

	template <class S>
	ScopeNode<S>& ScopeNode::<S>get_parent()
	{
		if(parent == nullptr)
			throw exceptions::UndefinedScopeException();
		
		return *parent;
	}

	template <class S>
	const ScopeNode<S>& ScopeNode::<S>get_parent() const
	{
		if(parent == nullptr)
			throw exceptions::UndefinedScopeException();

		return *parent;
	}

	template <class S>
	ScopeNode<S>& ScopeNode::<S>get_child(int pos)
	{
		if(pos >= children.size() || pos < 0)
			throw std::out_of_range("The new scope must inserted in the range of existing children.");

		return *children[pos];
	}

	template <class S>
	const ScopeNode<S>& ScopeNode::<S>get_child(int pos)
	{
		if(pos >= children.size() || pos < 0)
			throw std::out_of_range("The new scope must inserted in the range of existing children.");

		return *children[pos];
	}

	template <class S>
	bool ScopeNode<S>::has_parent() const
	{
		return parent != nullptr;
	}
}

#endif // SCOPE_NODE_HPP_DEFINED