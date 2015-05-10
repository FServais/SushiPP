#ifndef NT_STATEMENT_HPP_DEFINED
#define NT_STATEMENT_HPP_DEFINED

#include <string>
#include <list>

#include "NonTerminal.hpp"
#include "NT_Program.hpp" 
#include "NT_Expression.hpp"
#include "../tokens/Token.hpp"

namespace ast
{
	/*********************************************
	 * Intermediate NT_Statement node base class *
	 *********************************************/
	class NT_Statement : public NonTerminal
	{
	public:
		// Constructors
		NT_Statement(const std::string&);
		NT_Statement(const std::string&,int,int,int,int);
		NT_Statement(const std::string&,const NodeLocation&);

		virtual void accept(visitor::ASTVisitor&);
	};

	/***********************************
	 * Statement rules node base class *
	 ***********************************/
	class Statement : public NT_Statement
	{
	public:
		// Constructors
		Statement(ASTNode*);
		Statement(ASTNode*,int,int,int,int);
		Statement(ASTNode*,const NodeLocation&);

		// return the child node
		ASTNode& get_statement();

		virtual void accept(visitor::ASTVisitor&);
	};

	class Return : public NT_Statement
	{
	public:
		// Constructors
		Return(Expression*);
		Return(Expression*,int,int,int,int);
		Return(Expression*,const NodeLocation&);
		Return();
		Return(int,int,int,int);
		Return(const NodeLocation&);

		bool empty_nori();
		Expression& get_returned_expression();
		
		virtual void accept(visitor::ASTVisitor&);
	};

	class MenuCase : public NT_Statement
	{
	public:
		// Constructrors
		/**
		 * @param Scope* scope The scope to execute when the case is matched
		 * @þaram Expression* expr The matching expression
		 */
		MenuCase(Scope*,ASTNode*);
		MenuCase(Scope*,ASTNode*,int,int,int,int);
		MenuCase(Scope*,ASTNode*,const NodeLocation&);

		Scope& get_scope();
		ASTNode& get_expression();

		virtual void accept(visitor::ASTVisitor&);
	};

	class MenuDef : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param Scope* scope The scope to execute when the case is matched
		 */
		MenuDef(Scope*);
		MenuDef(Scope*,int,int,int,int);
		MenuDef(Scope*,const NodeLocation&);

		Scope& get_scope();

		virtual void accept(visitor::ASTVisitor&);
	};

	class MenuBody : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param MenuDef* default_case The default case node
		 * @param MenuCase* menu_case A case node of the menu
		 */
		MenuBody(MenuDef*);
		MenuBody(MenuDef*,int,int,int,int);
		MenuBody(MenuDef*,const NodeLocation&);
		MenuBody(MenuCase*);
		MenuBody(MenuCase*,int,int,int,int);
		MenuBody(MenuCase*,const NodeLocation&);

		/** 
		 * @brief Adds a case the the case list (insert it as the first one)
		 * @param MenuCase* menu_case The case to add
		 */
		void add_case(MenuCase*);

		/**
		 * @brief Checks wether the menu body contains a default case
		 * @retval bool True if it contains a default case, false otherwise
		 */
		bool contains_default() const { return has_default; };

		/**
		 * @brief Get the default case
		 * @throw NoSuchChildException if the body does not contain a default case
		 */
		MenuDef& get_default_case();

		/**
		 * @brief Return the number of (non-default) cases in the menu body
		 * @retval size_t The number of non-default cases in the body
		 */
		size_t nb_cases() const;

		/**
		 * @brief Return the nth (non-default) case of the menu body
		 * @param size_t n The menu case index in [0, nb_cases()[
		 * @retval MenuCase& The nth menu case
		 * @throw NoSuchChildException if the given index does not match any default case
		 */
		MenuCase& get_nth_case(size_t);

		virtual void accept(visitor::ASTVisitor&);

	private:
		bool has_default; // true if the menu body contains a default case (contained at the end of the children vector)
	};

	class Menu : public NT_Statement
	{
	public:
		// Constructors
		// second pointer is the menu expression
		Menu(MenuBody*,Expression*);
		Menu(MenuBody*,Expression*,int,int,int,int);
		Menu(MenuBody*,Expression*,const NodeLocation&);

		MenuBody& get_body();
		Expression& get_expression();

		virtual void accept(visitor::ASTVisitor&);
	};

	class Roll : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param Expression* expr The roll expression node
		 * @param Scope* scope The roll scope node
		 */
		Roll(Expression*,Scope*);
		Roll(Expression*,Scope*,int,int,int,int);
		Roll(Expression*,Scope*,const NodeLocation&);

		Scope& get_scope();
		Expression& get_expression();

		virtual void accept(visitor::ASTVisitor&);
	};

	class Foreach : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param Expression* expr datastructure expression
		 * @param Identifier* The id node of the identifier used for iterating over array/list
		 * @param Scope* the foreach scope
		 */
		Foreach(Expression*,Identifier*,Scope*);
		Foreach(Expression*,Identifier*,Scope*,int,int,int,int);
		Foreach(Expression*,Identifier*,Scope*,const NodeLocation&);

		Identifier& get_identifier();
		Expression& get_expression();
		Scope& get_scope();

		virtual void accept(visitor::ASTVisitor&);
	};

	class ForInitializer : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param ASTNode* expr Initializer expression
		 */
		ForInitializer(ASTNode*);
		ForInitializer(ASTNode*,int,int,int,int);
		ForInitializer(ASTNode*,const NodeLocation&);

		ASTNode& get_expression();
		
		virtual void accept(visitor::ASTVisitor&);
	};

	class ForUpdate : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param ASTNode* expr Update expression
		 */
		ForUpdate(ASTNode*);
		ForUpdate(ASTNode*,int,int,int,int);
		ForUpdate(ASTNode*,const NodeLocation&);
		
		ASTNode& get_expression();
		
		virtual void accept(visitor::ASTVisitor&);
	};

	class For : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param ForInitializer* init Loop initializer node
		 * @param Expression* expr Loop guardian node
		 * @param ForUpdate* update Loop update node
		 * @param Scope* Loop scope node
		 * @note nullptr can be given for the ForInitializer and ForUpdate if there is none
		 */
		For(ForInitializer*,Expression*,ForUpdate*,Scope*);
		For(ForInitializer*,Expression*,ForUpdate*,Scope*,int,int,int,int);
		For(ForInitializer*,Expression*,ForUpdate*,Scope*,const NodeLocation&);

		/**
		 * @throw NoSuchChildException if the initializer part is empty
		 */
		ForInitializer& get_initializer();
		Expression& get_expression();
		/**
		 * @throw NoSuchChildException if the update part is empty
		 */
		ForUpdate& get_update();
		Scope& get_scope();

		bool empty_initializer() const { return !has_initializer; }
		bool empty_update() const { return !has_update; }

		virtual void accept(visitor::ASTVisitor&);

	private:
		bool has_initializer;
		bool has_update;
	};

	class If : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param Expression* expr The condition expression node
		 * @param Scope* scope The scope node 
		 */
		If(Expression*,Scope*);
		If(Expression*,Scope*,int,int,int,int);
		If(Expression*,Scope*,const NodeLocation&);

		Scope& get_scope();
		Expression& get_expression();

		virtual void accept(visitor::ASTVisitor&);
	};

	class Elseif : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param Expression* expr The condition expression node
		 * @param Scope* scope The scope node 
		 */
		Elseif(Expression*,Scope*);
		Elseif(Expression*,Scope*,int,int,int,int);
		Elseif(Expression*,Scope*,const NodeLocation&);

		Scope& get_scope();
		Expression& get_expression();

		virtual void accept(visitor::ASTVisitor&);
	};

	class Else : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param Scope* scope The scope node 
		 */
		Else(Scope*);
		Else(Scope*,int,int,int,int);
		Else(Scope*,const NodeLocation&);

		Scope& get_scope();

		virtual void accept(visitor::ASTVisitor&);
	};

	class Conditional : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param If* if_node The if node
		 * @param const std::list<Elseif*> elseifs A list containing the Elseif children nodes (ordered from the first to the last elseif)
		 * @param Else* else_node The else node (nullptr if there is none)
		 */
		Conditional(If*,const std::list<Elseif*>&,Else*);
		Conditional(If*,const std::list<Elseif*>&,Else*,int,int,int,int);
		Conditional(If*,const std::list<Elseif*>&,Else*,const NodeLocation&);

		/**
		 * @brief Count the number of elseif
		 * @retval size_t The number of elseif 
		 */
		size_t count_elseif() const;

		/**
		 * @brief Get the nth elseif 
		 * @param size_t The nth elseif 
		 * @throw NoSuchChildException If the index does not refer to an existing node
		 */
		Elseif& get_nth_elseif(size_t);

		If& get_if();

		/**
		 * @brief Checks whether there is a Else child node
		 */
		bool contains_else() const { return has_else; }
		/**
		 * @throw NoSuchChildException If there is no else node
		 */
		Else& get_else();

		virtual void accept(visitor::ASTVisitor&);
	private:
		bool has_else;
	};
}

#endif
