
#ifndef __visitor__NodeVisitor__
#define __visitor__NodeVisitor__

#include <stdio.h>
#inclde "../nodes/ASTNode.hpp"

#include "../nodes/tokens/ConstantToken.cpp"
#include "../nodes/tokens/Delimiter.cpp"
#include "../nodes/tokens/Keyword.cpp"
#include "../nodes/tokens/Operator.cpp"
#include "../nodes/tokens/Token.cpp"

#include "../nodes/nonterminal/NT_Constant.cpp"
#include "../nodes/nonterminal/NT_Datastructure.cpp"
#include "../nodes/nonterminal/NT_Declaration.cpp"
#include "../nodes/nonterminal/NT_Expression.cpp"
#include "../nodes/nonterminal/NT_FunctionCall.cpp"
#include "../nodes/nonterminal/NT_Program.cpp"
#include "../nodes/nonterminal/NT_Statement.cpp"
#include "../nodes/nonterminal/NonTerminal.cpp"

class NodeVisitor {
    
public:
	/**************************
	 * 		Basic (Parent)    *
	 **************************/
    virtual void visit(ast::nodes::ASTNode);

    /******************************
	 * 		Token/Non-terminal    *
	 ******************************/
	virtual void visit(ast::nodes::tokens::Token);
	virtual void visit(ast::nodes::nonterminals::NonTerminal);

	/******************************
	 * 		Intermediate token    *
	 ******************************/
	virtual void visit(ast::nodes::tokens::ConstantToken);
	virtual void visit(ast::nodes::tokens::Identifier);

	/**************************
	 * 		Constant token    *
	 **************************/

    virtual void visit(ast::nodes::tokens::);
    virtual void visit(ast::nodes::tokens::constanttoken::ConstantToken);


	virtual void visit(ast::nodes::tokens::delimiter);
	virtual void visit(ast::nodes::tokens::keyword);
	virtual void visit(ast::nodes::tokens::operator);
	virtual void visit(ast::nodes::tokens::token);
	virtual void visit(ast::nodes::tokens::nonterminals::nt_constant);
	virtual void visit(ast::nodes::tokens::nonterminals::nt_datastructure);
	virtual void visit(ast::nodes::tokens::nonterminals::nt_declaration);
	virtual void visit(ast::nodes::tokens::nonterminals::nt_expression);
	virtual void visit(ast::nodes::tokens::nonterminals::nt_functioncall);
	virtual void visit(ast::nodes::tokens::nonterminals::nt_program);
	virtual void visit(ast::nodes::tokens::nonterminals::nt_statement);
	virtual void visit(ast::nodes::tokens::nonterminals::nonterminal);
};

#endif
