#include "NT_Program.hpp"

using namespace ast::nodes::nonterminals::nt_program;
using ast::nodes::nonterminals::NonTerminal;

/** Constant base class */
NT_Program::NT_Program(const std::string& node_name) : NonTerminal(node_name) {}

NT_Program::NT_Program(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Program::NT_Program(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}

/** (NT_)FunctionCall derived classes **/

/* Program */
Program::Program() : NT_FunctionCall("program") { }

Program::Program(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("program", first_line, last_line, first_column, last_column)
{

}

Program::Program(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("program", node_loc)
{

}

/* ScopeBody */
ScopeBody::ScopeBody() : NT_FunctionCall("scopebody") { }

ScopeBody::ScopeBody(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("scopebody", first_line, last_line, first_column, last_column)
{

}

ScopeBody::ScopeBody(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("scopebody", node_loc)
{

}

/* ProgramElement */
ProgramElement::ProgramElement() : NT_FunctionCall("programelement") { }

ProgramElement::ProgramElement(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("programelement", first_line, last_line, first_column, last_column)
{

}

ProgramElement::ProgramElement(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("programelement", node_loc)
{

}

/* Scope */
Scope::Scope() : NT_FunctionCall("scope") { }

Scope::Scope(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("scope", first_line, last_line, first_column, last_column)
{

}

Scope::Scope(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("scope", node_loc)
{

}

