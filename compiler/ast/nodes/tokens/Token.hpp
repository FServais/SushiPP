#ifndef TOKEN_HPP_DEFINED
#define TOKEN_HPP_DEFINED

#include <string>
#include "../NodeLocation.hpp"

namespace ast::nodes::tokens
{

	/*************************
	 * Token node base class *
	 *************************/
	class Token : public ast::nodes::ASTNode
	{
	public: 
		// constructors
		// string arg is the token node name 
		Token(const std::string&);
		// additionnal arguments are for location (see ast node constructors for ordering)
		Token(const std::string&,int,int,int,int);
		Token(const std::string&,const ast::nodes::NodeLocation&);
	};

	/**************************************
	 * Intermediate token node base class *
	 **************************************/
	class ConstantToken : public Token
	{
	public: 
		// constructors
		ConstantToken(const std::string&);
		ConstantToken(const std::string&,int,int,int,int);
		ConstantToken(const std::string&,const ast::nodes::NodeLocation&);
	};


	class Delimiter : public Token
	{
	public: 
		// constructors
		Delimiter(const std::string&,);
		Delimiter(const std::string&,int,int,int,int);
		Delimiter(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Keyword : public Token
	{
	public: 
		// constructors
		Keyword(const std::string&,);
		Keyword(const std::string&,int,int,int,int);
		Keyword(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Identifier : public Token
	{
	public: 
		// constructors
		// the string parameters is the identifier name (not the node name /!\)
		Identifier(const std::string&);
		Identifier(const std::string&,int,int,int,int);
		Identifier(const std::string&,const ast::nodes::NodeLocation&);

		// id getters 
		std::string& id() const;
		const std::string& id() const;

	private:
		std::string id_;
	};

	/*************
	 * Operators *
	 *************/

}

#endif
