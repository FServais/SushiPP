#include "NT_Program.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;

/** Constant base class */
NT_Program::NT_Program(const std::string& node_name) : NonTerminal(node_name) {}

NT_Program::NT_Program(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Program::NT_Program(const std::string& node_name, const NodeLocation& node_loc)
	: NonTerminal(node_name, node_loc)
{

}

void NT_Program::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/** (NT_)Program derived classes **/
/* Program */
Program::Program() : NT_Program("Program") { }

Program::Program(int first_line, int last_line, int first_column, int last_column)
	: NT_Program("Program", first_line, last_line, first_column, last_column)
{

}

Program::Program(const NodeLocation& node_loc) : NT_Program("Program", node_loc)
{

}

void Program::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* ProgramElement */
ProgramElement::ProgramElement() : NT_Program("Program element") { }

ProgramElement::ProgramElement(int first_line, int last_line, int first_column, int last_column)
	: NT_Program("Program element", first_line, last_line, first_column, last_column)
{

}

ProgramElement::ProgramElement(const NodeLocation& node_loc) : NT_Program("Program element", node_loc)
{

}

void ProgramElement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Scope */
Scope::Scope() : NT_Program("Scope") { }

Scope::Scope(int first_line, int last_line, int first_column, int last_column)
	: NT_Program("Scope", first_line, last_line, first_column, last_column)
{

}

Scope::Scope(const NodeLocation& node_loc) : NT_Program("Scope", node_loc)
{

}

void Scope::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}
