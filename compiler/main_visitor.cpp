#include <iostream>
#include <cstdio>

#include "ASTNode.hpp"

int main(int argc, char** argv)
{
	
	Program *tree = new ast::Program();
	ProgramElement *pe = new ast::ProgramElement();
	SoyFunc *soy = new ast::SoyFunc();
	Expression *exp = new ast::Expression();

	K_Maki *maki = new ast::K_Maki();
	exp.add_child(maki);

	tree.add_child(pe);
	tree.add_child(soy);
	tree.add_child(exp);

	PrintASTVisitor printV;
	tree->accept(printV);
}