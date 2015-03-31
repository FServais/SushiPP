#include "Keyword.hpp"

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

/* Keyword : to */
K_To::K_To() : Keyword("to") { }

K_To::K_To(int first_line, int last_line, int first_column, int last_column)
	: Keyword("to", first_line, last_line, first_column, last_column)
{

}

K_To::K_To(const NodeLocation& node_loc) : Keyword("to", node_loc)
{

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

/* Keyword : nori */
K_Nori::K_Nori() : Keyword("nori") { }

K_Nori::K_Nori(int first_line, int last_line, int first_column, int last_column)
	: Keyword("nori", first_line, last_line, first_column, last_column)
{

}

K_Nori::K_Nori(const NodeLocation& node_loc) : Keyword("nori", node_loc)
{

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

/* Keyword : for */
K_For::K_For() : Keyword("for") { }

K_For::K_For(int first_line, int last_line, int first_column, int last_column)
	: Keyword("for", first_line, last_line, first_column, last_column)
{

}

K_For::K_For(const NodeLocation& node_loc) : Keyword("for", node_loc)
{

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

/* Keyword :break */
K_Break::K_Break() : Keyword("break") { }

K_Break::K_Break(int first_line, int last_line, int first_column, int last_column)
	: Keyword("break", first_line, last_line, first_column, last_column)
{

}

K_Break::K_Break(const NodeLocation& node_loc) : Keyword("break", node_loc)
{

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

/* Keyword : foreach */
K_Foreach::K_Foreach() : Keyword("foreach") { }

K_Foreach::K_Foreach(int first_line, int last_line, int first_column, int last_column)
	: Keyword("foreach", first_line, last_line, first_column, last_column)
{

}

K_Foreach::K_Foreach(const NodeLocation& node_loc) : Keyword("foreach", node_loc)
{

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

/* Keyword : if */
K_If::K_If() : Keyword("if") { }

K_If::K_If(int first_line, int last_line, int first_column, int last_column)
	: Keyword("if", first_line, last_line, first_column, last_column)
{

}

K_If::K_If(const NodeLocation& node_loc) : Keyword("if", node_loc)
{

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

/* Keyword : else */
K_Else::K_Else() : Keyword("else") { }

K_Else::K_Else(int first_line, int last_line, int first_column, int last_column)
	: Keyword("else", first_line, last_line, first_column, last_column)
{

}

K_Else::K_Else(const NodeLocation& node_loc) : Keyword("else", node_loc)
{

}

/* Keyword : type_int */
Type_Int::Type_Int() : Keyword("type_int") { }

Type_Int::Type_Int(int first_line, int last_line, int first_column, int last_column)
	: Keyword("type_int", first_line, last_line, first_column, last_column)
{

}

Type_Int::Type_Int(const NodeLocation& node_loc) : Keyword("type_int", node_loc)
{

}

/* Keyword : type_float */
Type_Float::Type_Float() : Keyword("type_float") { }

Type_Float::Type_Float(int first_line, int last_line, int first_column, int last_column)
	: Keyword("type_float", first_line, last_line, first_column, last_column)
{

}

Type_Float::Type_Float(const NodeLocation& node_loc) : Keyword("type_float", node_loc)
{

}

/* Keyword : type_bool */
Type_Bool::Type_Bool() : Keyword("type_bool") { }

Type_Bool::Type_Bool(int first_line, int last_line, int first_column, int last_column)
	: Keyword("type_bool", first_line, last_line, first_column, last_column)
{

}

Type_Bool::Type_Bool(const NodeLocation& node_loc) : Keyword("type_bool", node_loc)
{

}

/* Keyword : type_bool */
Type_Char::Type_Char() : Keyword("type_char") { }

Type_Char::Type_Char(int first_line, int last_line, int first_column, int last_column)
	: Keyword("type_char", first_line, last_line, first_column, last_column)
{

}

Type_Char::Type_Char(const NodeLocation& node_loc) : Keyword("type_char", node_loc)
{

}

/* Keyword : type_string */
Type_String::Type_String() : Keyword("type_string") { }

Type_String::Type_String(int first_line, int last_line, int first_column, int last_column)
	: Keyword("type_string", first_line, last_line, first_column, last_column)
{

}

Type_String::Type_String(const NodeLocation& node_loc) : Keyword("type_string", node_loc)
{

}

/* Keyword : ] */
Type_Array::Type_Array() : Keyword("type_array") { }

Type_Array::Type_Array(int first_line, int last_line, int first_column, int last_column)
	: Keyword("type_array", first_line, last_line, first_column, last_column)
{

}

Type_Array::Type_Array(const NodeLocation& node_loc) : Keyword("type_array", node_loc)
{

}

/* Keyword : type_list */
Type_List::Type_List() : Keyword("type_list") { }

Type_List::Type_List(int first_line, int last_line, int first_column, int last_column)
	: Keyword("type_list", first_line, last_line, first_column, last_column)
{

}

Type_List::Type_List(const NodeLocation& node_loc) : Keyword("type_list", node_loc)
{

}

/* Keyword : type_tuple */
Type_Tuple::Type_Tuple() : Keyword("type_tuple") { }

Type_Tuple::Type_Tuple(int first_line, int last_line, int first_column, int last_column)
	: Keyword("type_tuple", first_line, last_line, first_column, last_column)
{

}

Type_Tuple::Type_Tuple(const NodeLocation& node_loc) : Keyword("type_tuple", node_loc)
{

}
