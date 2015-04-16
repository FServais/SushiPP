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
	 
}

/** Keyword derived classes */
<<<<<<< HEAD
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
	 
}

=======
>>>>>>> origin/ro_vm
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
	 
}

Type::Type(const std::string& node_name) : Keyword(node_name) { }

Type::Type(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Keyword(node_name, first_line, last_line, first_column, last_column)
{

}

Type::Type(const std::string& node_name, const NodeLocation& node_loc) : Keyword(node_name, node_loc)
{

}

<<<<<<< HEAD
void K_Foreach::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : as */
K_As::K_As() : Keyword("as") { }
=======
/* Keyword : type_int */
Type_Int::Type_Int() : Type("Type (int)") { }
>>>>>>> origin/ro_vm

Type_Int::Type_Int(int first_line, int last_line, int first_column, int last_column)
	: Type("Type (int)", first_line, last_line, first_column, last_column)
{

}

Type_Int::Type_Int(const NodeLocation& node_loc) : Type("Type (int)", node_loc)
{

}

<<<<<<< HEAD
void K_As::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : if */
K_If::K_If() : Keyword("if") { }

K_If::K_If(int first_line, int last_line, int first_column, int last_column)
	: Keyword("if", first_line, last_line, first_column, last_column)
=======
symb::Type Type_Int::get_type() const
>>>>>>> origin/ro_vm
{
	return symb::INT;
}

void Type_Int::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : type_float */
Type_Float::Type_Float() : Type("Type (float)") { }

Type_Float::Type_Float(int first_line, int last_line, int first_column, int last_column)
	: Type("Type (float)", first_line, last_line, first_column, last_column)
{

}

Type_Float::Type_Float(const NodeLocation& node_loc) : Type("Type (float)", node_loc)
{

}

<<<<<<< HEAD
void K_Elseif::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : else */
K_Else::K_Else() : Keyword("else") { }

K_Else::K_Else(int first_line, int last_line, int first_column, int last_column)
	: Keyword("else", first_line, last_line, first_column, last_column)
=======
symb::Type Type_Float::get_type() const
>>>>>>> origin/ro_vm
{
	return symb::FLOAT;
}


void Type_Float::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : type_bool */
Type_Bool::Type_Bool() : Type("Type (bool)") { }

Type_Bool::Type_Bool(int first_line, int last_line, int first_column, int last_column)
	: Type("Type (bool)", first_line, last_line, first_column, last_column)
{

}

Type_Bool::Type_Bool(const NodeLocation& node_loc) : Type("Type (bool)", node_loc)
{

}

<<<<<<< HEAD
void Type_Int::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : type_float */
Type_Float::Type_Float() : Keyword("Type (float)") { }

Type_Float::Type_Float(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (float)", first_line, last_line, first_column, last_column)
=======
symb::Type Type_Bool::get_type() const
>>>>>>> origin/ro_vm
{
	return symb::BOOL;
}


void Type_Bool::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : type_bool */
Type_Char::Type_Char() : Type("Type (char)") { }

Type_Char::Type_Char(int first_line, int last_line, int first_column, int last_column)
	: Type("Type (char)", first_line, last_line, first_column, last_column)
{

}

Type_Char::Type_Char(const NodeLocation& node_loc) : Type("Type (char)", node_loc)
{

}

<<<<<<< HEAD
void Type_Bool::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : type_bool */
Type_Char::Type_Char() : Keyword("Type (char)") { }

Type_Char::Type_Char(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (char)", first_line, last_line, first_column, last_column)
=======
symb::Type Type_Char::get_type() const
>>>>>>> origin/ro_vm
{
	return symb::CHAR;
}

void Type_Char::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : type_string */
Type_String::Type_String() : Type("Type (string)") { }

Type_String::Type_String(int first_line, int last_line, int first_column, int last_column)
	: Type("Type (string)", first_line, last_line, first_column, last_column)
{

}

Type_String::Type_String(const NodeLocation& node_loc) : Type("Type (string)", node_loc)
{

}

symb::Type Type_String::get_type() const
{
	return symb::STRING;
}

void Type_String::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : ] */
Type_Array::Type_Array() : Type("Type (array)") { }

Type_Array::Type_Array(int first_line, int last_line, int first_column, int last_column)
	: Type("Type (array)", first_line, last_line, first_column, last_column)
{

}

Type_Array::Type_Array(const NodeLocation& node_loc) : Type("Type (array)", node_loc)
{

}

symb::Type Type_Array::get_type() const
{
	return symb::ARRAY;
}

void Type_Array::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : type_list */
Type_List::Type_List() : Type("Type (list)") { }

Type_List::Type_List(int first_line, int last_line, int first_column, int last_column)
	: Type("Type (list)", first_line, last_line, first_column, last_column)
{

}

Type_List::Type_List(const NodeLocation& node_loc) : Type("Type (list)", node_loc)
{

}

<<<<<<< HEAD
void Type_List::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

/* Keyword : type_tuple */
Type_Tuple::Type_Tuple() : Keyword("Type (tuple)") { }

Type_Tuple::Type_Tuple(int first_line, int last_line, int first_column, int last_column)
	: Keyword("Type (tuple)", first_line, last_line, first_column, last_column)
=======
symb::Type Type_List::get_type() const
>>>>>>> origin/ro_vm
{
	return symb::LIST;
}


void Type_List::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}
