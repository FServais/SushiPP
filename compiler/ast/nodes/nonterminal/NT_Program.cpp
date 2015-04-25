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

void NT_Program::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/** (NT_)Program derived classes **/
/* Program */
Program::Program(Scope* scope) : NT_Program("Program") 
{ 
	if(scope)
		add_child(scope);
}

Program::Program(Scope* scope, int first_line, int last_line, int first_column, int last_column)
	: NT_Program("Program", first_line, last_line, first_column, last_column)
{
	if(scope)
		add_child(scope);
}

Program::Program(Scope* scope, const NodeLocation& node_loc) : NT_Program("Program", node_loc)
{
	if(scope)
		add_child(scope);
}

void Program::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Scope */
Scope::Scope(ASTNode* program_elem) : NT_Program("Scope") 
{
	add_child(program_elem);
}

Scope::Scope(ASTNode* program_elem, int first_line, int last_line, int first_column, int last_column)
	: NT_Program("Scope", first_line, last_line, first_column, last_column)
{
	add_child(program_elem);
}

Scope::Scope(ASTNode* program_elem, const NodeLocation& node_loc) : NT_Program("Scope", node_loc)
{
	add_child(program_elem);
}

void Scope::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

void Scope::add_program_element(ASTNode* program_element)
{
	add_child_first(program_element);
}

size_t Scope::nb_elements() const
{
	return children.size();
}