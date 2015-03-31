#include "ConstantToken.hpp"

using namespace ast::nodes::tokens::constants;
using ast::nodes::tokens::Token;

/** Constant token base class */
ConstantToken::ConstantToken(const std::string& node_name) : Token(node_name) {}

ConstantToken::ConstantToken(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Token(node_name, first_line, last_line, first_column, last_column)
{

}

ConstantToken::ConstantToken(const std::string& node_name, const NodeLocation& loc)
	: Token(node_name, node_loc)
{

}

/** Constant token derived classes */
String::String(const std::string& lexer_val)
{

}

String::String(const std::string& lexer_val,int,int,int,int)
{

}

String::String(const std::string& lexer_val,const ast::nodes::NodeLocation&)
{

}

std::string& String::value() const
{

}

const std::string& lexer_val String::value() const
{

}

Character::Character(const std::string& lexer_val)
{

}

Character::Character(const std::string& lexer_val,int,int,int,int)
{

}

Character::Character(const std::string& lexer_val,const ast::nodes::NodeLocation&)
{

}

char Character::value() const
{

}

Integer::Integer(const std::string& lexer_val)
{

}

Integer::Integer(const std::string& lexer_val,int,int,int,int)
{

}

Integer::Integer(const std::string& lexer_val,const ast::nodes::NodeLocation&)
{

}

int Integer::value() const
{

}

Float::Float(const std::string& lexer_val)
{

}

Float::Float(const std::string& lexer_val,int,int,int,int)
{

}

Float::Float(const std::string& lexer_val,const ast::nodes::NodeLocation&)
{

}

float Float::value() const
{

}

Bool::Bool(const std::string& lexer_val)
{

}

Bool::Bool(const std::string& lexer_val,int,int,int,int)
{

}

Bool::Bool(const std::string& lexer_val,const ast::nodes::NodeLocation&)
{

}

bool Bool::value() const
{

}