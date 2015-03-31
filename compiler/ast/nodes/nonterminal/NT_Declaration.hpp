#ifndef NT_DECLARATION_HPP_DEFINED
#define NT_DECLARATION_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_declaration
{

	/*************************************
	 * Declaration rules node base class *
	 *************************************/
	class Declaration : public NT_Declaration
	{
	public:
		// Constructors
		Declaration(const std::string&);
		Declaration(const std::string&,int,int,int,int);
		Declaration(const std::string&,const ast::nodes::NodeLocation&);
	};

	class DeclFunc : public NT_Declaration
	{
	public:
		// Constructors
		DeclFunc(const std::string&);
		DeclFunc(const std::string&,int,int,int,int);
		DeclFunc(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Decl_vars : public NT_Declaration
	{
	public:
		// Constructors
		Decl_vars(const std::string&);
		Decl_vars(const std::string&,int,int,int,int);
		Decl_vars(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Decl_var : public NT_Declaration
	{
	public:
		// Constructors
		Decl_var(const std::string&);
		Decl_var(const std::string&,int,int,int,int);
		Decl_var(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Param_list : public NT_Declaration
	{
	public:
		// Constructors
		Param_list(const std::string&);
		Param_list(const std::string&,int,int,int,int);
		Param_list(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Param : public NT_Declaration
	{
	public:
		// Constructors
		Param(const std::string&);
		Param(const std::string&,int,int,int,int);
		Param(const std::string&,const ast::nodes::NodeLocation&);
	};


}

#endif
