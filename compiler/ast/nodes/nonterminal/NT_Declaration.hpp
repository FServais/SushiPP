#ifndef NT_DECLARATION_HPP_DEFINED
#define NT_DECLARATION_HPP_DEFINED

#include <string>
#include "NonTerminal.hpp"
#include "NT_Program.hpp"
#include "NT_Expression.hpp"
#include "../tokens/Token.hpp"
#include "../tokens/Keyword.hpp"
#include "../NodeLocation.hpp"
#include "../../../inference/Types.hpp"

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

		virtual void accept(visitor::ASTVisitor&);
	};

	/*************************************
	 * Declaration rules node base class *
	 *************************************/
	class Param : public NT_Declaration
	{
	public:
		// Constructors
		Param(Identifier*);
		Param(Identifier*, Type*);
		Param(Identifier*, int,int,int,int);
		Param(Identifier*, Type*, int,int,int,int);
		Param(Identifier*, const NodeLocation&);
		Param(Identifier*, Type*, const NodeLocation&);

		const std::string& get_param_name() const;
		bool has_type() const;
		inference::ShallowType get_type() const;

		Identifier& get_identifier();
		const Identifier& get_identifier() const;
		Type& get_type_node();
		const Type& get_type_node() const;

		virtual void accept(visitor::ASTVisitor&);

	};

	class ParamList : public NT_Declaration
	{
	public:
		// Constructors
		ParamList(Param*);
		ParamList(Param*, int,int,int,int);
		ParamList(Param*, const NodeLocation&);

		virtual void accept(visitor::ASTVisitor&);
		void add_param(Param*);
		Param& get_param(size_t);
		size_t nb_params() const;

		/**
		 * @brief Return the parameters name in a vector
		 * The return a vector of n strings if the param list contains n parameters
		 */
		void get_parameters_name(std::vector<std::string>&);

		/**
		 * @brief Return the parameters types in a vector
		 * The return a vector of n strings if the param list contains n parameters
		 */
		void get_parameters_type(std::vector<inference::ShallowType>&);
	};

	class DeclFunc : public NT_Declaration
	{
	public:
		// Constructors
		DeclFunc(Identifier*, ParamList*, Scope*);
		DeclFunc(Identifier*, ParamList*, Scope*, int,int,int,int);
		DeclFunc(Identifier*, ParamList*, Scope*, const NodeLocation&);

		virtual void accept(visitor::ASTVisitor&);

		Identifier& get_id();
		/**
		 * @throw NoSuchChildException if there is no parameters
		 */
		ParamList& get_param_list();
		Scope& get_scope();

		bool contains_params() const { return has_params; }
		
	private:
		bool has_params;
	};

	class DeclVar : public NT_Declaration
	{
	public:
		// Constructors
		DeclVar(Identifier*);
		DeclVar(Identifier*, int,int,int,int);
		DeclVar(Identifier*, const NodeLocation&);

		DeclVar(Identifier*, Expression*);
		DeclVar(Identifier*, Expression*, int,int,int,int);
		DeclVar(Identifier*, Expression*, const NodeLocation&);

		Identifier& get_identifier();
		Expression& get_expression();

		bool contains_expr() const { return has_expression; }

		virtual void accept(visitor::ASTVisitor&);
	private:
		bool has_expression;
	};

	class DeclVars : public NT_Declaration
	{
	public:
		// Constructors
		DeclVars(DeclVar*);
		DeclVars(DeclVar*, int,int,int,int);
		DeclVars(DeclVar*, const NodeLocation&);

		DeclVar& get_variable(size_t);
		void add_variable(DeclVar*);
		size_t nb_variables() const; 

		virtual void accept(visitor::ASTVisitor&);
	};

	class SoyFunc : public NT_Declaration
	{
	public:
		// Constructors
		SoyFunc(ParamList*, Scope*);
		SoyFunc(ParamList*, Scope*, int,int,int,int);
		SoyFunc(ParamList*, Scope*, const NodeLocation&);

		virtual void accept(visitor::ASTVisitor&);
		ParamList& get_params();
		Scope& get_scope();

		bool contains_params() const { return has_params; }
	private:
		bool has_params;
	};
}

#endif
