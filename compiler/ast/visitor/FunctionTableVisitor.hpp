
#ifndef FunctionTableVisitor_HPP_DEFINED
#define FunctionTableVisitor_HPP_DEFINED

#include <iostream>
#include <string>

#include "ASTVisitor.hpp"
#include "../../symb/SymbolTable.hpp"
#include "../../util.hpp"

class FunctionTableVisitor : public ASTVisitor
{
public:

	FunctionTableVisitor(symb::SymbolTable<symb::FunctionInfo>&);

	virtual void visit( ast::ASTNode& );

	void visit( ast::SoyFunc& token );
	void visit( ast::Scope& token );
	void visit( ast::DeclFunc& token );


private:
	symb::SymbolTable<symb::FunctionInfo> function_table;
	
};

#endif

