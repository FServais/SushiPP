
#ifndef __visitor__PrintASTVisitor__
#define __visitor__PrintASTVisitor__

#include <iostream>
#include <string>

#include "ASTVisitor.hpp"

class PrintASTVisitor : public ASTVisitor
{
public:
	// Print the pair <type_of_token, value>
	void visit( ast::Token& );

	// Print 'name_of_the_rule'
	void visit( ast::NonTerminal& );

private:
	int length_line;
};

#endif

