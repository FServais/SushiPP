#include "Token.hpp"
#include "../../visitor/ASTVisitor.hpp"

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
Identifier::Identifier(const std::string& id) : Token("Identifier"), id_(id) {}

Identifier::Identifier(const std::string& id, int first_line, int last_line, int first_column, int last_column)
	: Token("Identifier", first_line, last_line, first_column, last_column),
	  id_(id)
{

}

Identifier::Identifier(const std::string& id, const NodeLocation& node_loc)
	: Token("Identifier", node_loc),
	  id_(id)
{

}

void Identifier::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

std::string& Identifier::id()
{
	return id_;
}

const std::string& Identifier::id() const
{
	return id_;
}
