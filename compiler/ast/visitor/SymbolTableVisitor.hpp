
#ifndef SymbolTableVisitor_HPP_DEFINED
#define SymbolTableVisitor_HPP_DEFINED



#include "../../symb/SymbolTable.hpp"
#include "../../symb/SymbolInfo.hpp"
#include "../../exceptions/Exceptions.hpp"
#include "../../util.hpp"
#include "ASTVisitor.hpp"

using namespace symb;

class SymbolTableVisitor : public ASTVisitor
{
public:

	SymbolTableVisitor(SymbolTable<FunctionInfo>& , SymbolTable<VariableInfo>& );
	~SymbolTableVisitor(){};

	virtual void visit( ast::ASTNode& );
	virtual void visit( ast::DeclVar& );
	virtual void visit( ast::FuncCall&  );
	virtual void visit( ast::Identifier& );
	virtual void visit( ast::Scope& );



private:
	SymbolTable<FunctionInfo> function_table;
	SymbolTable<VariableInfo> variable_table;
	
};

#endif

