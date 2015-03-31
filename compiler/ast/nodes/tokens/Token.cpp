#include "Token.hpp"
#include <iostream>
#include <string>

using namespace ast;

/********************
 * Token base class *
 ********************/
Token::Token(const std::string& node_name) : ASTNode(node_name) {}

Token::Token(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: ASTNode(node_name, first_line, last_line, first_column, last_column)
{

}

Token::Token(const std::string& node_name, const NodeLocation& node_loc)
	: ASTNode(node_name, node_loc)
{

}

/***********************************
 * Token intermediate base classes *
 ***********************************/

/** Identifier */
Identifier::Identifier(const std::string& id) : Token("identifier"), id_(id) {}

Identifier::Identifier(const std::string& id, int first_line, int last_line, int first_column, int last_column)
	: Token("identifier", first_line, last_line, first_column, last_column),
	  id_(id)
{

}

Identifier::Identifier(const std::string& id, const NodeLocation& node_loc)
	: Token("identifier", node_loc),
	  id_(id)
{

}

void Identifier::print(int depth)
{
	string s("");
	string t("");
	if(depth > 2)
		 s = string((depth-1)*3, ' ');
	
	if(depth > 1)
		t = string("|___");
	
	std::cout<<s<<t<<node_name_<<std::endl;
	for( auto it = children.begin(); it != children.end(); it++){
		(*it)->print(depth+1);
	}
}

std::string& Identifier::id()
{
	return id_;
}

const std::string& Identifier::id() const
{
	return id_;
}
