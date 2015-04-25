#ifndef NT_PROGRAM_HPP_DEFINED
#define NT_PROGRAM_HPP_DEFINED

#include "NonTerminal.hpp"

namespace ast
{
	/*********************************************
	 * Intermediate NT_Program node base class *
	 *********************************************/
	class NT_Program : public NonTerminal
	{
	public:
		// Constructors
		NT_Program(const std::string&);
		NT_Program(const std::string&,int,int,int,int);
		NT_Program(const std::string&,const NodeLocation&);

		virtual void accept(visitor::ASTVisitor&);
	};

	class Scope : public NT_Program
	{
	public:
		// Constructors
		Scope(ASTNode*);
		Scope(ASTNode*,int,int,int,int);
		Scope(ASTNode*,const NodeLocation&);

		/**
		 * @brief Insert a new program element (as first program element of the scope)
		 * @param ASTNode* program_element The program element to add
		 */
		void add_program_element(ASTNode*);
		/**
		 * @brief Return the number of child program elements
		 * @retval size_t The number of elements
		 */
		size_t nb_elements() const;

		size_t get_scope_id() const { return scope_id; }
		void set_scope_id(size_t id) { scope_id = id; }

		virtual void accept(visitor::ASTVisitor&);
	private:
		size_t scope_id;
	};

	/********************************
	 * Program rules node base class *
	 ********************************/
	class Program : public NT_Program
	{
	public:
		// Constructors
		// nullptr for no scope child
		Program(Scope*);
		Program(Scope*,int,int,int,int);
		Program(Scope*,const NodeLocation&);

		virtual void accept(visitor::ASTVisitor&);
	};
}

#endif
