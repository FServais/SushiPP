#include "NT_Datastructure.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;

/** Constant base class */
NT_Datastructure::NT_Datastructure(const std::string& node_name) : NonTerminal(node_name) {}

NT_Datastructure::NT_Datastructure(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Datastructure::NT_Datastructure(const std::string& node_name, const NodeLocation& node_loc)
	: NonTerminal(node_name, node_loc)
{

}

void NT_Datastructure::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/** (NT_)Datastructure derived classes **/
/* Datastructure */
Datastructure::Datastructure() : NT_Datastructure("Datastructure") { }

Datastructure::Datastructure(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Datastructure", first_line, last_line, first_column, last_column)
{

}

Datastructure::Datastructure(const NodeLocation& node_loc) : NT_Datastructure("Datastructure", node_loc)
{

}

void Datastructure::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Array */
Array::Array() : NT_Datastructure("Array") { }

Array::Array(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Array", first_line, last_line, first_column, last_column)
{

}

Array::Array(const NodeLocation& node_loc) : NT_Datastructure("Array", node_loc)
{

}

void Array::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* List */
List::List() : NT_Datastructure("List") { }

List::List(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("List", first_line, last_line, first_column, last_column)
{

}

List::List(const NodeLocation& node_loc) : NT_Datastructure("List", node_loc)
{

}

void List::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* MakeSequence */
MakeSequence::MakeSequence() : NT_Datastructure("Make sequence") { }

MakeSequence::MakeSequence(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Make sequence", first_line, last_line, first_column, last_column)
{

}

MakeSequence::MakeSequence(const NodeLocation& node_loc) : NT_Datastructure("Make sequence", node_loc)
{

}

void MakeSequence::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* MakeSequenceList */
MakeSequenceList::MakeSequenceList() : NT_Datastructure("Make sequence (list)") { }

MakeSequenceList::MakeSequenceList(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Make sequence (list)", first_line, last_line, first_column, last_column)
{

}

MakeSequenceList::MakeSequenceList(const NodeLocation& node_loc) : NT_Datastructure("Make sequence (list)", node_loc)
{

}

void MakeSequenceList::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* MakeSequenceArray */
MakeSequenceArray::MakeSequenceArray() : NT_Datastructure("Make sequence (array)") { }

MakeSequenceArray::MakeSequenceArray(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Make sequence (array)", first_line, last_line, first_column, last_column)
{

}

MakeSequenceArray::MakeSequenceArray(const NodeLocation& node_loc) : NT_Datastructure("Make sequence (array)", node_loc)
{

}

void MakeSequenceArray::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* SeqExpression */
SeqExpression::SeqExpression() : NT_Datastructure("Sequence expression") { }

SeqExpression::SeqExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Sequence expression", first_line, last_line, first_column, last_column)
{

}

SeqExpression::SeqExpression(const NodeLocation& node_loc) : NT_Datastructure("Sequence expression", node_loc)
{

}

void SeqExpression::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


