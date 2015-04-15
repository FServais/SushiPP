#include "Keyword.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;

/** Keyword base class */
Keyword::Keyword(const std::string& node_name) : Token(node_name) {}

Keyword::Keyword(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Token(node_name, first_line, last_line, first_column, last_column)
{

}

Keyword::Keyword(const std::string& node_name, const NodeLocation& node_loc)
	: Token(node_name, node_loc)
{

}

void Keyword::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/** Keyword derived classes */
/* Keyword :break */
K_Break::K_Break() : Keyword("break") { }

K_Break::K_Break(int first_line, int last_line, int first_column, int last_column)
	: Keyword("break", first_line, last_line, first_column, last_column)
{

}

K_Break::K_Break(const NodeLocation& node_loc) : Keyword("break", node_loc)
{

}

void K_Break::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : continue */
K_Continue::K_Continue() : Keyword("continue") { }

K_Continue::K_Continue(int first_line, int last_line, int first_column, int last_column)
	: Keyword("continue", first_line, last_line, first_column, last_column)
{

}

K_Continue::K_Continue(const NodeLocation& node_loc) : Keyword("continue", node_loc)
{

}

void K_Continue::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : type_int */
Type_Int::Type_Int() : Keyword("Type (int)") { }

Type_Int::Type_Int(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (int)", first_line, last_line, first_column, last_column)
{

}

Type_Int::Type_Int(const NodeLocation& node_loc) : Keyword("Type (int)", node_loc)
{

}

void Type_Int::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : type_float */
Type_Float::Type_Float() : Keyword("Type (float)") { }

Type_Float::Type_Float(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (float)", first_line, last_line, first_column, last_column)
{

}

Type_Float::Type_Float(const NodeLocation& node_loc) : Keyword("Type (float)", node_loc)
{

}

void Type_Float::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : type_bool */
Type_Bool::Type_Bool() : Keyword("Type (bool)") { }

Type_Bool::Type_Bool(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (bool)", first_line, last_line, first_column, last_column)
{

}

Type_Bool::Type_Bool(const NodeLocation& node_loc) : Keyword("Type (bool)", node_loc)
{

}

void Type_Bool::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : type_bool */
Type_Char::Type_Char() : Keyword("Type (char)") { }

Type_Char::Type_Char(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (char)", first_line, last_line, first_column, last_column)
{

}

Type_Char::Type_Char(const NodeLocation& node_loc) : Keyword("Type (char)", node_loc)
{

}

void Type_Char::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : type_string */
Type_String::Type_String() : Keyword("Type (string)") { }

Type_String::Type_String(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (string)", first_line, last_line, first_column, last_column)
{

}

Type_String::Type_String(const NodeLocation& node_loc) : Keyword("Type (string)", node_loc)
{

}

void Type_String::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : ] */
Type_Array::Type_Array() : Keyword("Type (array)") { }

Type_Array::Type_Array(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (array)", first_line, last_line, first_column, last_column)
{

}

Type_Array::Type_Array(const NodeLocation& node_loc) : Keyword("Type (array)", node_loc)
{

}

void Type_Array::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : type_list */
Type_List::Type_List() : Keyword("Type (list)") { }

Type_List::Type_List(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (list)", first_line, last_line, first_column, last_column)
{

}

Type_List::Type_List(const NodeLocation& node_loc) : Keyword("Type (list)", node_loc)
{

}

void Type_List::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}
