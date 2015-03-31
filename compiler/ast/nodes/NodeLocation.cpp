#include "NodeLocation.hpp"
#include <exception>

using namespace ast;
using namespace std;

NodeLocation::NodeLocation() : first_line_(0), last_line_(0), first_column_(0), last_column_(0) { }

NodeLocation::NodeLocation(int first_line, int last_line, int first_column, int last_column)
	: first_line_(first_line_), last_line_(last_line_), 
	  first_column_(first_column_), last_column_(last_column_) 
{
	if(first_line_ > last_line_)
		throw logic_error::domain_error("NodeLocation: first line should be less or equal than last_line");
}

int NodeLocation::first_line() const
{
	return first_line_;
}

int NodeLocation::last_line() const
{
	return last_line_;
}

int NodeLocation::first_column() const
{
	return first_column_;
}

int NodeLocation::last_column() const
{
	return last_column_;
}

void NodeLocation::set_first_line(int first_line)
{
	if(first_line > last_line_)
		throw logic_error::domain_error("NodeLocation: first line should be less or equal than last_line");

	first_line_ = first_line;
}

void NodeLocation::set_last_line(int last_line)
{
	if(first_line_ > last_line)
		throw logic_error::domain_error("NodeLocation: first line should be less or equal than last_line");

	last_line_ = last_line;
}

void NodeLocation::set_first_column(int first_column)
{
	first_column_ = first_column;
}

void NodeLocation::set_last_column(int last_column)
{
	last_column_ = last_column;
}

void NodeLocation::set_lines(int first_line, int last_line)
{
	if(first_line > last_line)
		throw logic_error::domain_error("NodeLocation: first line should be less or equal than last_line");

	first_line_ = first_line;
	last_line_ = last_line;
}