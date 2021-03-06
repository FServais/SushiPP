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
Program::Program() : NT_Program("program") { }

Program::Program(int first_line, int last_line, int first_column, int last_column)
	: NT_Program("program", first_line, last_line, first_column, last_column)
{

}

Program::Program(const NodeLocation& node_loc) : NT_Program("program", node_loc)
{

}

void Program::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* ScopeBody */
ScopeBody::ScopeBody() : NT_Program("scopebody") { }

ScopeBody::ScopeBody(int first_line, int last_line, int first_column, int last_column)
	: NT_Program("scopebody", first_line, last_line, first_column, last_column)
{

}

ScopeBody::ScopeBody(const NodeLocation& node_loc) : NT_Program("scopebody", node_loc)
{

}

void ScopeBody::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}
/* ProgramElement */
ProgramElement::ProgramElement() : NT_Program("programelement") { }

ProgramElement::ProgramElement(int first_line, int last_line, int first_column, int last_column)
	: NT_Program("programelement", first_line, last_line, first_column, last_column)
{

}

ProgramElement::ProgramElement(const NodeLocation& node_loc) : NT_Program("programelement", node_loc)
{

}

void ProgramElement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Scope */
Scope::Scope() : NT_Program("scope") { }

Scope::Scope(int first_line, int last_line, int first_column, int last_column)
	: NT_Program("scope", first_line, last_line, first_column, last_column)
{

}

Scope::Scope(const NodeLocation& node_loc) : NT_Program("scope", node_loc)
{

}

void Scope::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}
