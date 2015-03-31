#include "Token.hpp"

using namespace ast::nodes::tokens;
using ast::nodes::ASTNode;
using ast::nodes::NodeLocation;

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



/** Delimiter */
Delimiter::Delimiter(const std::string& node_name) : Token(node_name) {}

Delimiter::Delimiter(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Token(node_name, first_line, last_line, first_column, last_column)
{

}

Delimiter::Delimiter(const std::string& node_name, const NodeLocation& loc)
	: Token(node_name, node_loc)
{

}



/** Keyword */
Keyword::Keyword(const std::string& node_name) : Token(node_name) {}

Keyword::Keyword(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Token(node_name, first_line, last_line, first_column, last_column)
{

}

Keyword::Keyword(const std::string& node_name, const NodeLocation& loc)
	: Token(node_name, node_loc)
{

}

/** Identifier */
Identifier::Identifier(const std::string& id) : Token("identifier"), id_(id) {}

Identifier::Identifier(const std::string& id, int first_line, int last_line, int first_column, int last_column)
	: Token("identifier", first_line, last_line, first_column, last_column), id_(id) 
{

}

Identifier::Identifier(const std::string& id, const NodeLocation& loc)
	: Token("identifier", node_loc), id_(id)
{

}

std::string& id() const
{
	return id_;
}

const std::string& id() const
{
	return id_;
}
