#include "NT_Datastructure.hpp"
#include "../../visitor/ASTVisitor.hpp"
#include "../../../exceptions/Exceptions.hpp"

using namespace ast;
using namespace except;

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

/* Array */
Array::Array() : NT_Datastructure("Array") { }

Array::Array(int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Array", first_line, last_line, first_column, last_column)
{

}

Array::Array(const NodeLocation& node_loc) : NT_Datastructure("Array", node_loc)
{

}

Array::Array(ASTNode* items) : NT_Datastructure("Array")
{
	add_child(items);
}

Array::Array(ASTNode* items, int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Array", first_line, last_line, first_column, last_column)
{
	add_child(items);
}

Array::Array(ASTNode* items, const NodeLocation& node_loc) : NT_Datastructure("Array", node_loc)
{
	add_child(items);
}

bool Array::empty_items() const
{
	return children.size() == 0;
}

ASTNode& Array::get_items()
{
	if(empty_items())
		throw NoSuchChildException("this array is empty");
	return *children[0];
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

List::List(ASTNode* items) : NT_Datastructure("List")
{ 
	add_child(items);
}

List::List(ASTNode* items, int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("List", first_line, last_line, first_column, last_column)
{
	add_child(items);
}

List::List(ASTNode* items, const NodeLocation& node_loc) : NT_Datastructure("List", node_loc)
{
	add_child(items);
}

bool List::empty_items() const
{
	return children.size() == 0;
}

ASTNode& List::get_items()
{
	if(empty_items())
		throw NoSuchChildException("this list is empty");
	return *children[0];
}

void List::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* MakeSequenceList */
MakeSequenceList::MakeSequenceList(Expression* begin, Expression* end) : NT_Datastructure("Make sequence (list)")
{
	add_child(begin);
	add_child(end);
}

MakeSequenceList::MakeSequenceList(Expression* begin, Expression* end, int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Make sequence (list)", first_line, last_line, first_column, last_column)
{
	add_child(begin);
	add_child(end);
}

MakeSequenceList::MakeSequenceList(Expression* begin, Expression* end, const NodeLocation& node_loc) : NT_Datastructure("Make sequence (list)", node_loc)
{
	add_child(begin);
	add_child(end);
}

Expression& MakeSequenceList::get_begin()
{
	return *dynamic_cast<Expression*>(children[0]);
}

Expression& MakeSequenceList::get_end()
{
	return *dynamic_cast<Expression*>(children[1]);
}

void MakeSequenceList::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* MakeSequenceArray */
MakeSequenceArray::MakeSequenceArray(Expression* begin, Expression* end) : NT_Datastructure("Make sequence (array)")
{
	add_child(begin);
	add_child(end);
}

MakeSequenceArray::MakeSequenceArray(Expression* begin, Expression* end, int first_line, int last_line, int first_column, int last_column)
	: NT_Datastructure("Make sequence (array)", first_line, last_line, first_column, last_column)
{
	add_child(begin);
	add_child(end);
}

MakeSequenceArray::MakeSequenceArray(Expression* begin, Expression* end, const NodeLocation& node_loc) : NT_Datastructure("Make sequence (array)", node_loc)
{
	add_child(begin);
	add_child(end);
}

Expression& MakeSequenceArray::get_begin()
{
	return *dynamic_cast<Expression*>(children[0]);
}

Expression& MakeSequenceArray::get_end()
{
	return *dynamic_cast<Expression*>(children[1]);
}

void MakeSequenceArray::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}
