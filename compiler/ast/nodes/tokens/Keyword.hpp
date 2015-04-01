#ifndef KEYWORD_HPP_DEFINED
#define KEYWORD_HPP_DEFINED

#include <string>
#include "Token.hpp"
#include "../NodeLocation.hpp"

namespace ast
{
    /** Keyword derived class */
	class Keyword : public Token
	{
	public:
		// constructors
		Keyword(const std::string&);
		Keyword(const std::string&,int,int,int,int);
		Keyword(const std::string&,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	/** Keyword derived class */
	class K_Maki : public Keyword
	{
	public:
		// constructors
		K_Maki();
		K_Maki(int,int,int,int);
		K_Maki(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_To : public Keyword
	{
	public:
		// constructors
		K_To();
		K_To(int,int,int,int);
		K_To(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Soy : public Keyword
	{
	public:
		// constructors
		K_Soy();
		K_Soy(int,int,int,int);
		K_Soy(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Nori: public Keyword
	{
	public:
		// constructors
		K_Nori();
		K_Nori(int,int,int,int);
		K_Nori(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Menu : public Keyword
	{
	public:
		// constructors
		K_Menu();
		K_Menu(int,int,int,int);
		K_Menu(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_For : public Keyword
	{
	public:
		// constructors
		K_For();
		K_For(int,int,int,int);
		K_For(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Roll : public Keyword
	{
	public:
		// constructors
		K_Roll();
		K_Roll(int,int,int,int);
		K_Roll(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Break : public Keyword
	{
	public:
		// constructors
		K_Break();
		K_Break(int,int,int,int);
		K_Break(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Continue : public Keyword
	{
	public:
		// constructors
		K_Continue();
		K_Continue(int,int,int,int);
		K_Continue(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Foreach : public Keyword
	{
	public:
		// constructors
		K_Foreach();
		K_Foreach(int,int,int,int);
		K_Foreach(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_As : public Keyword
	{
	public:
		// constructors
		K_As();
		K_As(int,int,int,int);
		K_As(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_If : public Keyword
	{
	public:
		// constructors
		K_If();
		K_If(int,int,int,int);
		K_If(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Elseif : public Keyword
	{
	public:
		// constructors
		K_Elseif();
		K_Elseif(int,int,int,int);
		K_Elseif(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class K_Else : public Keyword
	{
	public:
		// constructors
		K_Else();
		K_Else(int,int,int,int);
		K_Else(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Type_Int : public Keyword
	{
	public:
		// constructors
		Type_Int();
		Type_Int(int,int,int,int);
		Type_Int(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Type_Float : public Keyword
	{
	public:
		// constructors
		Type_Float();
		Type_Float(int,int,int,int);
		Type_Float(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Type_Char : public Keyword
	{
	public:
		// constructors
		Type_Char();
		Type_Char(int,int,int,int);
		Type_Char(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Type_String : public Keyword
	{
	public:
		// constructors
		Type_String();
		Type_String(int,int,int,int);
		Type_String(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Type_Array : public Keyword
	{
	public:
		// constructors
		Type_Array();
		Type_Array(int,int,int,int);
		Type_Array(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Type_List : public Keyword
	{
	public:
		// constructors
		Type_List();
		Type_List(int,int,int,int);
		Type_List(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Type_Tuple : public Keyword
	{
	public:
		// constructors
		Type_Tuple();
		Type_Tuple(int,int,int,int);
		Type_Tuple(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Type_Bool : public Keyword
	{
	public:
		// constructors
		Type_Bool();
		Type_Bool(int,int,int,int);
		Type_Bool(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}
#endif
