#include "NT_Datastructure.hpp"

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

/** (NT_)Datastructure derived classes **/
/* Datastructure */
Datastructure::Datastructure() : NT_Datastructure("datastructure") { }

Datastructure::Datastructure(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("datastructure", first_line, last_line, first_column, last_column)
{

}

Datastructure::Datastructure(const NodeLocation& node_loc) : NT_Datastructure("datastructure", node_loc)
{

}

/* Array */
Array::Array() : NT_Datastructure("array") { }

Array::Array(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("array", first_line, last_line, first_column, last_column)
{

}

Array::Array(const NodeLocation& node_loc) : NT_Datastructure("array", node_loc)
{

}

/* List */
List::List() : NT_Datastructure("list") { }

List::List(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("list", first_line, last_line, first_column, last_column)
{

}

List::List(const NodeLocation& node_loc) : NT_Datastructure("list", node_loc)
{

}

/* Tuple */
Tuple::Tuple() : NT_Datastructure("tuple") { }

Tuple::Tuple(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("tuple", first_line, last_line, first_column, last_column)
{

}

Tuple::Tuple(const NodeLocation& node_loc) : NT_Datastructure("tuple", node_loc)
{

}

/* MakeSequence */
MakeSequence::MakeSequence() : NT_Datastructure("makesequence") { }

MakeSequence::MakeSequence(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("makesequence", first_line, last_line, first_column, last_column)
{

}

MakeSequence::MakeSequence(const NodeLocation& node_loc) : NT_Datastructure("makesequence", node_loc)
{

}

/* MakeSequenceList */
MakeSequenceList::MakeSequenceList() : NT_Datastructure("makesequencelist") { }

MakeSequenceList::MakeSequenceList(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("makesequencelist", first_line, last_line, first_column, last_column)
{

}

MakeSequenceList::MakeSequenceList(const NodeLocation& node_loc) : NT_Datastructure("makesequencelist", node_loc)
{

}

/* MakeSequenceArray */
MakeSequenceArray::MakeSequenceArray() : NT_Datastructure("makesequencearray") { }

MakeSequenceArray::MakeSequenceArray(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("makesequencearray", first_line, last_line, first_column, last_column)
{

}

MakeSequenceArray::MakeSequenceArray(const NodeLocation& node_loc) : NT_Datastructure("makesequencearray", node_loc)
{

}

/* SeqExpression */
SeqExpression::SeqExpression() : NT_Datastructure("seqexpression") { }

SeqExpression::SeqExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("seqexpression", first_line, last_line, first_column, last_column)
{

}

SeqExpression::SeqExpression(const NodeLocation& node_loc) : NT_Datastructure("seqexpression", node_loc)
{

}


