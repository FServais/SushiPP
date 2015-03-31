#ifndef TOKEN_HPP_DEFINED
#define TOKEN_HPP_DEFINED

//class ASTNode;

#include <string>
#include "../ASTNode.hpp"
//#include "../NodeLocation.hpp"

namespace ast
{
	class NodeLocation;

	/*************************
	 * Token node base class *
	 *************************/
	class Token : public ASTNode
	{
	public:
		// constructors
		// string arg is the token node name
		Token(const std::string&);
		// additionnal arguments are for location (see ast node constructors for ordering)
		Token(const std::string&,int,int,int,int);
		Token(const std::string&,const NodeLocation&);
	};


	/* Identifier token */
	class Identifier : public Token
	{
	public:
		// constructors
		// the string parameters is the identifier name (not the node name /!\)
		Identifier(const std::string&);
		Identifier(const std::string&,int,int,int,int);
		Identifier(const std::string&,const NodeLocation&);

		// id getters
		std::string& id();
		const std::string& id() const;

	private:
		std::string id_;
	};
}

#endif
