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
/* Keyword : maki */
K_Maki::K_Maki() : Keyword("maki") { }

K_Maki::K_Maki(int first_line, int last_line, int first_column, int last_column)
	: Keyword("maki", first_line, last_line, first_column, last_column)
{

}

K_Maki::K_Maki(const NodeLocation& node_loc) : Keyword("maki", node_loc)
{

}

void K_Maki::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : to */
K_To::K_To() : Keyword("to") { }

K_To::K_To(int first_line, int last_line, int first_column, int last_column)
	: Keyword("to", first_line, last_line, first_column, last_column)
{

}

K_To::K_To(const NodeLocation& node_loc) : Keyword("to", node_loc)
{

}

void K_To::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : soy */
K_Soy::K_Soy() : Keyword("soy") { }

K_Soy::K_Soy(int first_line, int last_line, int first_column, int last_column)
	: Keyword("soy", first_line, last_line, first_column, last_column)
{

}

K_Soy::K_Soy(const NodeLocation& node_loc) : Keyword("soy", node_loc)
{

}

void K_Soy::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : nori */
K_Nori::K_Nori() : Keyword("nori") { }

K_Nori::K_Nori(int first_line, int last_line, int first_column, int last_column)
	: Keyword("nori", first_line, last_line, first_column, last_column)
{

}

K_Nori::K_Nori(const NodeLocation& node_loc) : Keyword("nori", node_loc)
{

}

void K_Nori::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : menu */
K_Menu::K_Menu() : Keyword("menu") { }

K_Menu::K_Menu(int first_line, int last_line, int first_column, int last_column)
	: Keyword("menu", first_line, last_line, first_column, last_column)
{

}

K_Menu::K_Menu(const NodeLocation& node_loc) : Keyword("menu", node_loc)
{

}

void K_Menu::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : for */
K_For::K_For() : Keyword("for") { }

K_For::K_For(int first_line, int last_line, int first_column, int last_column)
	: Keyword("for", first_line, last_line, first_column, last_column)
{

}

K_For::K_For(const NodeLocation& node_loc) : Keyword("for", node_loc)
{

}

void K_For::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : roll */
K_Roll::K_Roll() : Keyword("roll") { }

K_Roll::K_Roll(int first_line, int last_line, int first_column, int last_column)
	: Keyword("roll", first_line, last_line, first_column, last_column)
{

}

K_Roll::K_Roll(const NodeLocation& node_loc) : Keyword("roll", node_loc)
{

}

void K_Roll::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

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

/* Keyword : foreach */
K_Foreach::K_Foreach() : Keyword("foreach") { }

K_Foreach::K_Foreach(int first_line, int last_line, int first_column, int last_column)
	: Keyword("foreach", first_line, last_line, first_column, last_column)
{

}

K_Foreach::K_Foreach(const NodeLocation& node_loc) : Keyword("foreach", node_loc)
{

}

void K_Foreach::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : as */
K_As::K_As() : Keyword("as") { }

K_As::K_As(int first_line, int last_line, int first_column, int last_column)
	: Keyword("as", first_line, last_line, first_column, last_column)
{

}

K_As::K_As(const NodeLocation& node_loc) : Keyword("as", node_loc)
{

}

void K_As::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : if */
K_If::K_If() : Keyword("if") { }

K_If::K_If(int first_line, int last_line, int first_column, int last_column)
	: Keyword("if", first_line, last_line, first_column, last_column)
{

}

K_If::K_If(const NodeLocation& node_loc) : Keyword("if", node_loc)
{

}

void K_If::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : elseif */
K_Elseif::K_Elseif() : Keyword("elseif") { }

K_Elseif::K_Elseif(int first_line, int last_line, int first_column, int last_column)
	: Keyword("elseif", first_line, last_line, first_column, last_column)
{

}

K_Elseif::K_Elseif(const NodeLocation& node_loc) : Keyword("elseif", node_loc)
{

}

void K_Elseif::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* Keyword : else */
K_Else::K_Else() : Keyword("else") { }

K_Else::K_Else(int first_line, int last_line, int first_column, int last_column)
	: Keyword("else", first_line, last_line, first_column, last_column)
{

}

K_Else::K_Else(const NodeLocation& node_loc) : Keyword("else", node_loc)
{

}

void K_Else::accept(ASTVisitor& visitor)
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

/* Keyword : type_tuple */
Type_Tuple::Type_Tuple() : Keyword("Type (tuple)") { }

Type_Tuple::Type_Tuple(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (tuple)", first_line, last_line, first_column, last_column)
{

}

Type_Tuple::Type_Tuple(const NodeLocation& node_loc) : Keyword("Type (tuple)", node_loc)
{

}

void Type_Tuple::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

