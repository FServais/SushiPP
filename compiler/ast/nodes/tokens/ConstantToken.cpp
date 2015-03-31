#include "ConstantToken.hpp"

#include <iterator>
#include <cstdlib>
#include <iostream>

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

String::String(const std::string& lexer_val, const NodeLocation& node_loc)
	: ConstantToken("string", node_loc),
	  str_val(next(lexer_val.begin()), prev(lexer_val.end())) // remove the double quotes
{

}

void String::print(int depth)
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

std::string& String::value()
{
	return str_val;
}

const std::string& String::value() const
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

Character::Character(const std::string& lexer_val, const NodeLocation& node_loc)
	: ConstantToken("char", node_loc),
	  char_val(lexer_val[1])
{

}

void Character::print(int depth)
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

char Character::value() const
{
	return char_val;
}

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

int Integer::value() const
{
	return int_val;
}

void Integer::print(int depth)
{
	string s("");
	string t("");
	if(depth > 2)
		 s = string((depth-1)*3, ' ');
	
	if(depth > 1)
		t = string("|___");
	
	std::cout<<s<<t<<node_name_<<std::endl;

	for( auto it = children.begin(); it != children.end(); it++)
		(*it)->print(depth+1);
}

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

float Float::value() const
{
	return float_val;
}

void Float::print(int depth)
{
	string s("");
	string t("");
	if(depth > 2)
		 s = string((depth-1)*3, ' ');
	
	if(depth > 1)
		t = string("|___");
	
	std::cout<<s<<t<<node_name_<<std::endl;

	for( auto it = children.begin(); it != children.end(); it++)
			(*it)->print(depth+1);
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

Bool::Bool(const std::string& lexer_val, const NodeLocation& node_loc)
	: ConstantToken("bool"),
	  bool_val(Bool::stob(lexer_val))
{

}

void Bool::print(int depth)
{
	string s("");
	string t("");
	if(depth > 2)
		 s = string((depth-1)*3, ' ');
	
	if(depth > 1)
		t = string("|___");
	
	std::cout<<s<<t<<node_name_<<std::endl;

	for( auto it = children.begin(); it != children.end(); it++)
		(*it)->print(depth+1);
}

bool Bool::value() const
{
	return bool_val;
}
