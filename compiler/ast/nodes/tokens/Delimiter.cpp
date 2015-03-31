#include "DelimiterToken.hpp"

using namespace ast::nodes::tokens::Delimiters;
using ast::nodes::tokens::Token;

/** Delimiter token base class */
DelimiterToken::DelimiterToken(const std::string& node_name) : Token(node_name) {}

DelimiterToken::DelimiterToken(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Token(node_name, first_line, last_line, first_column, last_column)
{

}

DelimiterToken::DelimiterToken(const std::string& node_name, const NodeLocation& loc)
	: Token(node_name, node_loc)
{

}

/** Delimiter derived classes
 Delimiter : Delimeol */
Delimeol::Delimeol() : Delimiter("eol") { }

Delimeol::Delimeol(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("eol", first_line, last_line, first_column, last_column)
{

}

Delimeol::Delimeol(const ast::nodes::NodeLocation& node_loc) : Delimiter("eol", node_loc)
{

}

/* Delimiter : eos */
Delimeos::Delimeos() : Delimiter(";;") { }

Delimeos::Delimeos(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter(";;", first_line, last_line, first_column, last_column)
{

}

Delimeos::Delimeos(const ast::nodes::NodeLocation& node_loc) : Delimiter(";;", node_loc)
{

}

/* Delimiter : TupleBeg */
TupleBeg::TupleBeg() : Delimiter("#{") { }

TupleBeg::TupleBeg(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("#{", first_line, last_line, first_column, last_column)
{

}

TupleBeg::TupleBeg(const ast::nodes::NodeLocation& node_loc) : Delimiter("#{", node_loc)
{

}

/* Delimiter : TupleEnd */
TupleEnd::TupleEnd() : Delimiter("}#") { }

TupleEnd::TupleEnd(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("}#", first_line, last_line, first_column, last_column)
{

}

TupleEnd::TupleEnd(const ast::nodes::NodeLocation& node_loc) : Delimiter("}#", node_loc)
{

}

/* Delimiter : #[ */
ArrayBeg::ArrayBeg() : Delimiter("#[") { }

ArrayBeg::ArrayBeg(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("#[", first_line, last_line, first_column, last_column)
{

}

ArrayBeg::ArrayBeg(const ast::nodes::NodeLocation& node_loc) : Delimiter("#[", node_loc)
{

}

/* Delimiter : ]# */
ArrayEnd::ArrayEnd() : Delimiter("]#") { }

ArrayEnd::ArrayEnd(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("]#", first_line, last_line, first_column, last_column)
{

}

ArrayEnd::ArrayEnd(const ast::nodes::NodeLocation& node_loc) : Delimiter("]#", node_loc)
{

}

/* Delimiter : -> */
Arrow::Arrow() : Delimiter("->") { }

Arrow::Arrow(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("->", first_line, last_line, first_column, last_column)
{

}

Arrow::Arrow(const ast::nodes::NodeLocation& node_loc) : Delimiter("->", node_loc)
{

}

/* Delimiter :, */
Virg::Virg() : Delimiter(",") { }

Virg::Virg(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter(",", first_line, last_line, first_column, last_column)
{

}

Virg::Virg(const ast::nodes::NodeLocation& node_loc) : Delimiter(",", node_loc)
{

}

/* Delimiter : ( */
OpenPar::OpenPar() : Delimiter("(") { }

OpenPar::OpenPar(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("(", first_line, last_line, first_column, last_column)
{

}

OpenPar::OpenPar(const ast::nodes::NodeLocation& node_loc) : Delimiter("(", node_loc)
{

}

/* Delimiter : ) */
ClosingPar::ClosingPar() : Delimiter(")") { }

ClosingPar::ClosingPar(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter(")", first_line, last_line, first_column, last_column)
{

}

ClosingPar::ClosingPar(const ast::nodes::NodeLocation& node_loc) : Delimiter(")", node_loc)
{

}

/* Delimiter : [ */
OpenBrace::OpenBrace() : Delimiter("[") { }

OpenBrace::OpenBrace(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("[", first_line, last_line, first_column, last_column)
{

}

OpenBrace::OpenBrace(const ast::nodes::NodeLocation& node_loc) : Delimiter("[", node_loc)
{

}

/* Delimiter : ] */
ClosingBrace::ClosingBrace() : Delimiter("]") { }

ClosingBrace::ClosingBrace(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("]", first_line, last_line, first_column, last_column)
{

}

ClosingBrace::ClosingBrace(const ast::nodes::NodeLocation& node_loc) : Delimiter("]", node_loc)
{

}

/* Delimiter : { */
OpenAcc::OpenAcc() : Delimiter("{") { }

OpenAcc::OpenAcc(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("{", first_line, last_line, first_column, last_column)
{

}

OpenAcc::OpenAcc(const ast::nodes::NodeLocation& node_loc) : Delimiter("{", node_loc)
{

}

/* Delimiter : } */
ClosingAcc::ClosingAcc() : Delimiter("}") { }

ClosingAcc::ClosingAcc(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("}", first_line, last_line, first_column, last_column)
{

}

ClosingAcc::ClosingAcc(const ast::nodes::NodeLocation& node_loc) : Delimiter("}", node_loc)
{

}

/* Delimiter : _ */
Underscore::Underscore() : Delimiter("_") { }

Underscore::Underscore(int first_line, int last_line, int first_column, int last_column) 
	: Delimiter("_", first_line, last_line, first_column, last_column)
{

}

Underscore::Underscore(const ast::nodes::NodeLocation& node_loc) : Delimiter("_", node_loc)
{

}

