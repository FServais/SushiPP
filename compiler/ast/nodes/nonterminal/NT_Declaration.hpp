#ifndef NT_DECLARATION_HPP_DEFINED
#define NT_DECLARATION_HPP_DEFINED

#include <string>
#include "NonTerminal.hpp"
#include "../../../symb/SymbolInfo.hpp"
#include "../NodeLocation.hpp"

namespace ast
{
	/*********************************************
	 * Intermediate NT_Declaration node base class *
	 *********************************************/
	class NT_Declaration : public NonTerminal
	{
	public:
		// Constructors
		NT_Declaration(const std::string&);
		NT_Declaration(const std::string&,int,int,int,int);
		NT_Declaration(const std::string&,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	/*************************************
	 * Declaration rules node base class *
	 *************************************/

	class DeclFunc : public NT_Declaration
	{
	public:
		// Constructors
		DeclFunc(Identifier*, ParamList*, Scope*);
		DeclFunc(Identifier*, ParamList*, Scope*, int,int,int,int);
		DeclFunc(Identifier*, ParamList*, Scope*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		Identifier& get_id();
		ArgList& get_param_list();
		Scope& get_scope();
	};

	class DeclVars : public NT_Declaration
	{
	public:
		// Constructors
		DeclVars(DeclVar*);
		DeclVars(DeclVar*, int,int,int,int);
		DeclVars(DeclVar*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		DeclVar& get_decl_var(size_t);
		void add_decl_var(DeclVar*);
	};

	class DeclVar : public NT_Declaration
	{
	public:
		// Constructors
		DeclVar(Identifier*);
		DeclVar(Identifier*, int,int,int,int);
		DeclVar(Identifier*, const NodeLocation&);

		DeclVar(Identifier*, ASTNode*);
		DeclVar(Identifier*, ASTNode*, int,int,int,int);
		DeclVar(Identifier*, ASTNode*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		Identifier& get_id();
		ASTNode& get_exp();
	};

	class ParamList : public NT_Declaration
	{
	public:
		// Constructors
		ParamList(Param*);
		ParamList(Param*, int,int,int,int);
		ParamList(Param*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		void add_param(Param*);
		Param& get_param(size_t);
	};

	class Param : public NT_Declaration
	{
	public:
		// Constructors
		Param(Identifier*);
		Param(Identifier*, ASTNode*);
		Param(Identifier*, int,int,int,int);
		Param(Identifier*, ASTNode*, int,int,int,int);
		Param(Identifier*, const NodeLocation&);
		Param(Identifier*, ASTNode*, const NodeLocation&);

		const std::string& get_param_name() const;
		bool has_type() const;
		symb::Type get_type() const;

		virtual void accept(ASTVisitor&);
		Identifier& get_id();
		ASTNode& get_type();
	};
}

#endif
