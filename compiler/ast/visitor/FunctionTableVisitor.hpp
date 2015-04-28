
#ifndef FunctionTableVisitor_HPP_DEFINED
#define FunctionTableVisitor_HPP_DEFINED


#include "../../symb/SymbolTable.hpp"
#include "../../symb/SymbolInfo.hpp"
#include "../../util.hpp"
#include "ASTVisitor.hpp"

class FunctionTableVisitor  : public ASTVisitor
{
public:
	FunctionTableVisitor( symb::SymbolTable<symb::FunctionInfo>& );

	virtual void visit( ast::ASTNode& );
	virtual void visit( ast::SoyFunc&  );
	virtual void visit( ast::Scope&  );
	virtual void visit( ast::DeclFunc&  );


private:
	symb::SymbolTable<symb::FunctionInfo> function_table;
	
};

#endif

