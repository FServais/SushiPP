#include "ConstantToken.hpp"

#include <iterator>

using namespace std;
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
	: ConstantToken("string"), 
	  str_val(next(lexer_val.begin()), prev(lexer_val.end())) // remove the double quotes
{

}

String::String(const std::string& lexer_val, int first_line, int last_line, int first_column, int last_column) 
	: ConstantToken("string", first_line, last_line, first_column, last_column), 
	  str_val(next(lexer_val.begin()), prev(lexer_val.end())) // remove the double quotes
{

}

String::String(const std::string& lexer_val, const ast::nodes::NodeLocation& node_loc) 
	: ConstantToken("string", node_loc), 
	  str_val(next(lexer_val.begin()), prev(lexer_val.end())) // remove the double quotes
{

}

std::string& String::value() const
{
	return str_val;
}

const std::string& lexer_val String::value() const
{
	return str_val;
}

Character::Character(const std::string& lexer_val) 
	: ConstantToken("char"), 
	  char_val(lexer_val[1])
{

}

Character::Character(const std::string& lexer_val, int first_line, int last_line, int first_column, int last_column) 
	: ConstantToken("char", first_line, last_line, first_column, last_column), 
	  char_val(lexer_val[1]) 
{

}

Character::Character(const std::string& lexer_val, const ast::nodes::NodeLocation& node_loc) 
	: ConstantToken("char", node_loc), 
	  char_val(lexer_val[1]) 
{

}

char Character::value() const
{
	return char_val;
}

Integer::Integer(const std::string& lexer_val) : 
	: ConstantToken("integer"), 
	  int_val(stoi(lexer_val))
{

}

Integer::Integer(const std::string& lexer_val, int first_line, int last_line, int first_column, int last_column) 
	: ConstantToken("integer", first_line, last_line, first_column, last_column), 
	  int_val(stoi(lexer_val)) 
{

}

Integer::Integer(const std::string& lexer_val, const ast::nodes::NodeLocation& node_loc) : 
	: ConstantToken("integer", node_loc), 
	  int_val(stoi(lexer_val)) 
{

}

int Integer::value() const
{
	return int_val;
}

Float::Float(const std::string& lexer_val) 
	: ConstantToken("float"), 
	  float_val(stof(lexer_val))
{

}

Float::Float(const std::string& lexer_val, int first_line, int last_line, int first_column, int last_column) 
	: ConstantToken("float", first_line, last_line, first_column, last_column), 
	  float_val(stof(lexer_val))
{

}

Float::Float(const std::string& lexer_val, const ast::nodes::NodeLocation& node_loc) : 
	: ConstantToken("float", node_loc),
	  float_val(stof(lexer_val)) 
{

}

float Float::value() const
{
	return float_val;
}

Bool::Bool(const std::string& lexer_val) 
	: ConstantToken("bool"), 
	  bool_val(Bool::stob(lexer_val))
{

}

Bool::Bool(const std::string& lexer_val, int first_line, int last_line, int first_column, int last_column) 
	: ConstantToken("bool", first_line, last_line, first_column, last_column), 
	  bool_val(Bool::stob(lexer_val)) 
{

}

Bool::Bool(const std::string& lexer_val, const ast::nodes::NodeLocation& node_loc) 
	: ConstantToken("bool"), 
	  bool_val(Bool::stob(lexer_val)) 
{

}

bool Bool::value() const
{
	return bool_val;
}