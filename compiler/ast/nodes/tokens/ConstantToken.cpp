#include "ConstantToken.hpp"
#include "../../visitor/ASTVisitor.hpp"

#include <iterator>
#include <cstdlib>

using namespace std;
using namespace ast;

/** Constant token base class */
ConstantToken::ConstantToken(const std::string& node_name) : Token(node_name) {}

ConstantToken::ConstantToken(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Token(node_name, first_line, last_line, first_column, last_column)
{

}

ConstantToken::ConstantToken(const std::string& node_name, const NodeLocation& node_loc)
	: Token(node_name, node_loc)
{

}

void ConstantToken::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/** Constant token derived classes */
// String
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

String::String(const std::string& lexer_val, const NodeLocation& node_loc)
	: ConstantToken("string", node_loc),
	  str_val(next(lexer_val.begin()), prev(lexer_val.end())) // remove the double quotes
{

}

void String::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

std::string& String::value()
{
	return str_val;
}

const std::string& String::value() const
{
	return str_val;
}


// Character
Character::Character(const std::string& lexer_val)
  : ConstantToken("char"),
	char_val(extract_char(lexer_val))
{
}

Character::Character(const std::string& lexer_val, int first_line, int last_line, int first_column, int last_column)
  : ConstantToken("char", first_line, last_line, first_column, last_column),
	char_val(extract_char(lexer_val))
{
}

Character::Character(const std::string& lexer_val, const NodeLocation& node_loc)
  : ConstantToken("char", node_loc),
	char_val(extract_char(lexer_val))
{
}

void Character::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

char Character::value() const
{
	return char_val;
}

char Character::extract_char(const std::string& char_str) const
{
	if(char_str.size() == 3)
		return char_str[1];

	if(char_str.size() != 4)
		return '\0';

	switch(char_str[2])
	{
	case '0' : return '\0';
	case 'r' : return '\r';
	case 'n' : return '\n';
	case 't' : return '\t';
	case 'f' : return '\f';
	default: return '\0';
	}
}

// Integer
Integer::Integer(const std::string& lexer_val)
	: ConstantToken("integer"),
	  int_val(atoi(lexer_val.c_str()))
{

}

Integer::Integer(const std::string& lexer_val, int first_line, int last_line, int first_column, int last_column)
	: ConstantToken("integer", first_line, last_line, first_column, last_column),
	  int_val(atoi(lexer_val.c_str()))
{

}

Integer::Integer(const std::string& lexer_val, const NodeLocation& node_loc)
	: ConstantToken("integer", node_loc),
	  int_val(atoi(lexer_val.c_str()))
{

}

void Integer::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

int Integer::value() const
{
	return int_val;
}


// Float
Float::Float(const std::string& lexer_val)
	: ConstantToken("float"),
	  float_val(atof(lexer_val.c_str()))
{

}

Float::Float(const std::string& lexer_val, int first_line, int last_line, int first_column, int last_column)
	: ConstantToken("float", first_line, last_line, first_column, last_column),
	  float_val(atof(lexer_val.c_str()))
{

}

Float::Float(const std::string& lexer_val, const NodeLocation& node_loc)
	: ConstantToken("float", node_loc),
	  float_val(atof(lexer_val.c_str()))
{

}

void Float::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

float Float::value() const
{
	return float_val;
}


// Bool
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

Bool::Bool(const std::string& lexer_val, const NodeLocation& node_loc)
	: ConstantToken("bool"),
	  bool_val(Bool::stob(lexer_val))
{

}

void Bool::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

bool Bool::value() const
{
	return bool_val;
}
