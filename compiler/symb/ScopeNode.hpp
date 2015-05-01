#ifndef SCOPE_NODE_HPP_DEFINED
#define SCOPE_NODE_HPP_DEFINED

#include <string>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <memory>
#include <iostream>

#include "../exceptions/Exceptions.hpp"

namespace symb
{
	template <class S>
	class ScopeNode 
	{
	public:
		// constructors, param : scope id
		ScopeNode(size_t);

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
		void add_symbol(const std::string&, const S& data);

		/**
		 * @brief Create a new child scope 
		 * @retval size_t The new identifier of the node
		 * @param int pos The position at which the new scope must be inserted (optionnal, default: inserted as last child)
		 * @throw out_of_range If the given position is invalid
		 */
		size_t create_child_scope(size_t, int = -1);

		/**
		 * @brief Find and return the scope having the given scope id 
		 * @param size_t id The scope id
		 * @retval ScopeNode& The scope node having the given id
		 * @note The scope node is searched recursively in the children 
		 * @throw UndefinedScopeException If the scope is not found
		 */
		ScopeNode<S>& find_scope(size_t);

		/**
		 * @brief See the non*const version of the find_scope function
		 */
		const ScopeNode<S>& find_scope(size_t) const;

		/**
		 * @brief Return the identifier of the node
		 */
		size_t get_id() const;

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
		const ScopeNode& get_child(int pos) const;

		void print_scope();

		void print_children();

		size_t get_id_for_symb(const std::string );

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
		size_t scope_id;

		/**
		 * @brief Free the memory allocated for the children
		 */
		void free_children();
	};

	template<class S>
	size_t ScopeNode<S>::get_id_for_symb(const std::string name)
	{


		if(symbol_exists(name))
		{	
			std::cout<<"TU ME CHERCHES???"<<std::endl;
			return scope_id;
		}
		for(ScopeNode* child : children)
		{
			try
			{
				return child->get_id_for_symb(name); 

			}
			catch(except::UndefinedSymbolException& e) { }

		}

		throw except::UndefinedSymbolException(name);

	}

	template <class S>
	void ScopeNode<S>::print_children()
	{
		std::cout << "Children of "<<scope_id<<std::endl;
		for(ScopeNode* c : children)
		{
			std::cout<<" 	Node : "<<c->get_id()<<std::endl;
		}
	}

	template <class S>
	void ScopeNode<S>::print_scope()
	{
		std::cout<< "------" << scope_id << "--------"<<std::endl;
		for(auto it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;

		for(auto child : children)
		{
			
			child->print_scope();
		}
	}


	template <class S>
	ScopeNode<S>::ScopeNode(size_t scope_id_) : parent(nullptr), scope_id(scope_id_)
	{

	}

	template <class S>
	ScopeNode<S>::ScopeNode(const ScopeNode<S>& copy) 
	  : map(copy.map),
		parent(nullptr),
		scope_id(copy.scope_id)
	{

		for(ScopeNode* scope : copy.children)
		{
			ScopeNode* new_scope = new ScopeNode(*scope);
			children.push_back(new_scope);
		}
	}

	template <class S>
	ScopeNode<S>& ScopeNode<S>::operator=(const ScopeNode& copy)
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
			children.push_back(new_scope);
		}

		return *this;
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
			throw except::UndefinedSymbolException(symb_name);

		return (map.find(symb_name))->second;
	}

	template <class S>
	const S& ScopeNode<S>::symbol_info(const std::string& symb_name) const
	{
		if(!symbol_exists(symb_name))
			throw except::UndefinedSymbolException(symb_name);

		return (map.find(symb_name))->second;		
	}

	template <class S>
	void ScopeNode<S>::delete_symbol(const std::string& symb_name) const
	{
		map.erase(symb_name);
	}

	template <class S>
	void ScopeNode<S>::add_symbol(const std::string& symb_name, const S& data)
	{
		if(!map.count(symb_name))
			map.emplace(symb_name, data);
	
	}

	template <class S>
	size_t ScopeNode<S>::create_child_scope(size_t scope_id, int pos)
	{



		if(pos > ((int)children.size()) || pos < -1)
			throw std::out_of_range("The new scope must inserted in the range of existing children.");

		if(pos == -1)
			pos = children.size();

		ScopeNode* new_scope = new ScopeNode(scope_id);
		children.insert(std::next(children.begin(), pos), new_scope);

		new_scope->parent = this;
		return new_scope->get_id();
	}

	template <class S>
	ScopeNode<S>& ScopeNode<S>::find_scope(size_t id)
	{
		if(id == scope_id)
			return *this;

		for(ScopeNode* child : children)
		{
			try
			{

				return (child->find_scope(id)); 

			}
			catch(except::UndefinedScopeException& e) { }

		}

		throw except::UndefinedScopeException(id);
	}

	template <class S>
	const ScopeNode<S>& ScopeNode<S>::find_scope(size_t id) const
	{
		if(id == scope_id)
			return *this;

		for(ScopeNode* child : children)
		{
			try
			{

				return (child->find_scope(id));

			}
			catch(except::UndefinedScopeException& e) { }
		}

		throw except::UndefinedScopeException(id);
	}

	template <class S>
	void ScopeNode<S>::free_children()
	{
		std::for_each(children.begin(), children.end(), std::default_delete<ScopeNode>());
	}

	template <class S>
	size_t ScopeNode<S>::get_id() const
	{
		return scope_id;
	}

	template <class S>
	ScopeNode<S>& ScopeNode<S>::get_parent()
	{
		if(parent == nullptr)
			throw except::UndefinedScopeException();
		
		return *parent;
	}

	template <class S>
	const ScopeNode<S>& ScopeNode<S>::get_parent() const
	{
		if(parent == nullptr)
			throw except::UndefinedScopeException();

		return *parent;
	}

	template <class S>
	ScopeNode<S>& ScopeNode<S>::get_child(int pos)
	{
		if(pos >= children.size() || pos < 0)
			throw std::out_of_range("The new scope must inserted in the range of existing children.");

		return *children[pos];
	}

	template <class S>
	const ScopeNode<S>& ScopeNode<S>::get_child(int pos) const
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