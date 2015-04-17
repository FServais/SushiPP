#ifndef NT_STATEMENT_HPP_DEFINED
#define NT_STATEMENT_HPP_DEFINED

#include "NonTerminal.hpp"
#include "NT_Program.hpp";

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

		virtual void accept(ASTVisitor&);
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

		virtual void accept(ASTVisitor&);
	};

	class Return : public NT_Statement
	{
	public:
		// Constructors
		Return(ASTNode*);
		Return(ASTNode*,int,int,int,int);
		Return(ASTNode*,const NodeLocation&);
		Return();
		Return(int,int,int,int);
		Return(const NodeLocation&);

		bool empty_nori();
		ASTNode& get_returned_expression();
		
		virtual void accept(ASTVisitor&);
	};

	class MenuCase : public NT_Statement
	{
	public:
		// Constructors
		/**
		 * @param Scope* scope The scope to execute when the case is matched
		 * @þaram ASTNode* expr The matching expression
		 */
		MenuCase(Scope*,ASTNode*);
		MenuCase(Scope*,ASTNode*,int,int,int,int);
		MenuCase(Scope*,ASTNode*,const NodeLocation&);

		Scope& get_scope();
		ASTNode& get_expression();

		virtual void accept(ASTVisitor&);
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

		virtual void accept(ASTVisitor&);
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

		virtual void accept(ASTVisitor&);

	private:
		bool has_default; // true if the menu body contains a default case (contained at the end of the children vector)
	};

	class Menu : public NT_Statement
	{
	public:
		// Constructors
		// second pointer is the menu expression
		Menu(MenuBody*,ASTNode*);
		Menu(MenuBody*,ASTNode*,int,int,int,int);
		Menu(MenuBody*,ASTNode*,const NodeLocation&);

		MenuBody& get_body();
		ASTNode& get_expression();

		virtual void accept(ASTVisitor&);
	};

	class Roll : public NT_Statement
	{
	public:
		// Constructors
		Roll();
		Roll(int,int,int,int);
		Roll(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Foreach : public NT_Statement
	{
	public:
		// Constructors
		Foreach();
		Foreach(int,int,int,int);
		Foreach(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class For : public NT_Statement
	{
	public:
		// Constructors
		For();
		For(int,int,int,int);
		For(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class ForInitializer : public NT_Statement
	{
	public:
		// Constructors
		ForInitializer();
		ForInitializer(int,int,int,int);
		ForInitializer(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class ForUpdate : public NT_Statement
	{
	public:
		// Constructors
		ForUpdate();
		ForUpdate(int,int,int,int);
		ForUpdate(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Conditional : public NT_Statement
	{
	public:
		// Constructors
		Conditional();
		Conditional(int,int,int,int);
		Conditional(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class If : public NT_Statement
	{
	public:
		// Constructors
		If();
		If(int,int,int,int);
		If(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Elseif : public NT_Statement
	{
	public:
		// Constructors
		Elseif();
		Elseif(int,int,int,int);
		Elseif(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Else : public NT_Statement
	{
	public:
		// Constructors
		Else();
		Else(int,int,int,int);
		Else(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}

#endif
