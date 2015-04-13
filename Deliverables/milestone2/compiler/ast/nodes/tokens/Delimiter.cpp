#include "Delimiter.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;

/** Delimiter token base class */
Delimiter::Delimiter(const std::string& node_name) : Token(node_name) {}

Delimiter::Delimiter(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Token(node_name, first_line, last_line, first_column, last_column)
{

}

Delimiter::Delimiter(const std::string& node_name, const NodeLocation& node_loc)
	: Token(node_name, node_loc)
{

}

void Delimiter::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/** Delimiter derived classes
 Delimiter : DelimEol */
DelimEol::DelimEol() : Delimiter("eol") { }

DelimEol::DelimEol(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("eol", first_line, last_line, first_column, last_column)
{

}

DelimEol::DelimEol(const NodeLocation& node_loc) : Delimiter("eol", node_loc)
{

}

void DelimEol::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : eos */
DelimEos::DelimEos() : Delimiter(";;") { }

DelimEos::DelimEos(int first_line, int last_line, int first_column, int last_column)
	: Delimiter(";;", first_line, last_line, first_column, last_column)
{

}

DelimEos::DelimEos(const NodeLocation& node_loc) : Delimiter(";;", node_loc)
{

}

void DelimEos::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : TupleBeg */
TupleBeg::TupleBeg() : Delimiter("#{") { }

TupleBeg::TupleBeg(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("#{", first_line, last_line, first_column, last_column)
{

}

TupleBeg::TupleBeg(const NodeLocation& node_loc) : Delimiter("#{", node_loc)
{

}

void TupleBeg::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : TupleEnd */
TupleEnd::TupleEnd() : Delimiter("}#") { }

TupleEnd::TupleEnd(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("}#", first_line, last_line, first_column, last_column)
{

}

TupleEnd::TupleEnd(const NodeLocation& node_loc) : Delimiter("}#", node_loc)
{

}

void TupleEnd::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : #[ */
ArrayBeg::ArrayBeg() : Delimiter("#[") { }

ArrayBeg::ArrayBeg(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("#[", first_line, last_line, first_column, last_column)
{

}

ArrayBeg::ArrayBeg(const NodeLocation& node_loc) : Delimiter("#[", node_loc)
{

}

void ArrayBeg::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : ]# */
ArrayEnd::ArrayEnd() : Delimiter("]#") { }

ArrayEnd::ArrayEnd(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("]#", first_line, last_line, first_column, last_column)
{

}

ArrayEnd::ArrayEnd(const NodeLocation& node_loc) : Delimiter("]#", node_loc)
{

}

void ArrayEnd::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : -> */
Arrow::Arrow() : Delimiter("->") { }

Arrow::Arrow(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("->", first_line, last_line, first_column, last_column)
{

}

Arrow::Arrow(const NodeLocation& node_loc) : Delimiter("->", node_loc)
{

}

void Arrow::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter :, */
Virg::Virg() : Delimiter(",") { }

Virg::Virg(int first_line, int last_line, int first_column, int last_column)
	: Delimiter(",", first_line, last_line, first_column, last_column)
{

}

Virg::Virg(const NodeLocation& node_loc) : Delimiter(",", node_loc)
{

}

void Virg::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : ( */
OpenPar::OpenPar() : Delimiter("(") { }

OpenPar::OpenPar(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("(", first_line, last_line, first_column, last_column)
{

}

OpenPar::OpenPar(const NodeLocation& node_loc) : Delimiter("(", node_loc)
{

}

void OpenPar::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : ) */
ClosingPar::ClosingPar() : Delimiter(")") { }

ClosingPar::ClosingPar(int first_line, int last_line, int first_column, int last_column)
	: Delimiter(")", first_line, last_line, first_column, last_column)
{

}

ClosingPar::ClosingPar(const NodeLocation& node_loc) : Delimiter(")", node_loc)
{

}

void ClosingPar::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : [ */
OpenBrace::OpenBrace() : Delimiter("[") { }

OpenBrace::OpenBrace(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("[", first_line, last_line, first_column, last_column)
{

}

OpenBrace::OpenBrace(const NodeLocation& node_loc) : Delimiter("[", node_loc)
{

}

void OpenBrace::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : ] */
ClosingBrace::ClosingBrace() : Delimiter("]") { }

ClosingBrace::ClosingBrace(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("]", first_line, last_line, first_column, last_column)
{

}

ClosingBrace::ClosingBrace(const NodeLocation& node_loc) : Delimiter("]", node_loc)
{

}

void ClosingBrace::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : [ */
OpenChevr::OpenChevr() : Delimiter("<") { }

OpenChevr::OpenChevr(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("<", first_line, last_line, first_column, last_column)
{

}

OpenChevr::OpenChevr(const NodeLocation& node_loc) : Delimiter("<", node_loc)
{

}

void OpenChevr::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : ] */
ClosingChevr::ClosingChevr() : Delimiter(">") { }

ClosingChevr::ClosingChevr(int first_line, int last_line, int first_column, int last_column)
	: Delimiter(">", first_line, last_line, first_column, last_column)
{

}

ClosingChevr::ClosingChevr(const NodeLocation& node_loc) : Delimiter(">", node_loc)
{

}

void ClosingChevr::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* Delimiter : { */
OpenAcc::OpenAcc() : Delimiter("{") { }

OpenAcc::OpenAcc(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("{", first_line, last_line, first_column, last_column)
{

}

OpenAcc::OpenAcc(const NodeLocation& node_loc) : Delimiter("{", node_loc)
{

}

void OpenAcc::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : } */
ClosingAcc::ClosingAcc() : Delimiter("}") { }

ClosingAcc::ClosingAcc(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("}", first_line, last_line, first_column, last_column)
{

}

ClosingAcc::ClosingAcc(const NodeLocation& node_loc) : Delimiter("}", node_loc)
{

}

void ClosingAcc::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Delimiter : _ */
Underscore::Underscore() : Delimiter("_") { }

Underscore::Underscore(int first_line, int last_line, int first_column, int last_column)
	: Delimiter("_", first_line, last_line, first_column, last_column)
{

}

Underscore::Underscore(const NodeLocation& node_loc) : Delimiter("_", node_loc)
{

}

void Underscore::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

