#include <iostream>
#include <cstdio>

#include "nodes/ASTNode.hpp"
#include "nodes/nonterminal/NT_Program.hpp"
#include "nodes/nonterminal/NT_FunctionCall.hpp"
#include "nodes/nonterminal/NT_Expression.hpp"
#include "nodes/tokens/Keyword.hpp"

#include "visitor/PrintASTVisitor.hpp"

using namespace ast;

int main(int argc, char** argv)
{
	
	Program *tree = new ast::Program();
	ProgramElement *pe = new ast::ProgramElement();
	SoyFunc *soy = new ast::SoyFunc();
	Expression *exp = new ast::Expression();

	K_Maki *maki = new ast::K_Maki();
	soy->add_child(maki);

	tree->add_child(pe);
	tree->add_child(soy);
	tree->add_child(exp);

	PrintASTVisitor printV;
	tree->accept(printV);
}