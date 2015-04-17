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


/* Keyword : type_int */
Type_Int::Type_Int() : Type("Type (int)") { }

Type_Int::Type_Int(int first_line, int last_line, int first_column, int last_column)
	: Type("Type (int)", first_line, last_line, first_column, last_column)
{

}

Type_Int::Type_Int(const NodeLocation& node_loc) : Type("Type (int)", node_loc)
{

}


symb::Type Type_Int::get_type() const
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


symb::Type Type_Float::get_type() const
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


symb::Type Type_Bool::get_type() const
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


symb::Type Type_Char::get_type() const
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


symb::Type Type_List::get_type() const
{
	return symb::LIST;
}


void Type_List::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}
