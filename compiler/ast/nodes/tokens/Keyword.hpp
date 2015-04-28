#ifndef KEYWORD_HPP_DEFINED
#define KEYWORD_HPP_DEFINED

#include <string>
#include "Token.hpp"
#include "../../../inference/Types.hpp"
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

		virtual void accept(visitor::ASTVisitor&);
	};

	/** Keyword derived class */
	class K_Break : public Keyword
	{
	public:
		// constructors
		K_Break();
		K_Break(int,int,int,int);
		K_Break(const NodeLocation&);

		virtual void accept(visitor::ASTVisitor&);
	};

	class K_Continue : public Keyword
	{
	public:
		// constructors
		K_Continue();
		K_Continue(int,int,int,int);
		K_Continue(const NodeLocation&);

		virtual void accept(visitor::ASTVisitor&);
	};

	class Type : public Keyword 
	{
	public:
		// constructors
		Type(const std::string&);
		Type(const std::string&,int,int,int,int);
		Type(const std::string&,const NodeLocation&);

		virtual inference::ShallowType get_type() const = 0;
	};

	class Type_Int : public Type
	{
	public:
		// constructors
		Type_Int();
		Type_Int(int,int,int,int);
		Type_Int(const NodeLocation&);

		virtual inference::ShallowType get_type() const;

		virtual void accept(visitor::ASTVisitor&);
	};

	class Type_Float : public Type
	{
	public:
		// constructors
		Type_Float();
		Type_Float(int,int,int,int);
		Type_Float(const NodeLocation&);

		virtual inference::ShallowType get_type() const;

		virtual void accept(visitor::ASTVisitor&);
	};

	class Type_Char : public Type
	{
	public:
		// constructors
		Type_Char();
		Type_Char(int,int,int,int);
		Type_Char(const NodeLocation&);

		virtual inference::ShallowType get_type() const;

		virtual void accept(visitor::ASTVisitor&);
	};

	class Type_String : public Type
	{
	public:
		// constructors
		Type_String();
		Type_String(int,int,int,int);
		Type_String(const NodeLocation&);

		virtual inference::ShallowType get_type() const;

		virtual void accept(visitor::ASTVisitor&);
	};

	class Type_Array : public Type
	{
	public:
		// constructors
		Type_Array();
		Type_Array(int,int,int,int);
		Type_Array(const NodeLocation&);

		virtual inference::ShallowType get_type() const;

		virtual void accept(visitor::ASTVisitor&);
	};

	class Type_List : public Type
	{
	public:
		// constructors
		Type_List();
		Type_List(int,int,int,int);
		Type_List(const NodeLocation&);

		virtual inference::ShallowType get_type() const;

		virtual void accept(visitor::ASTVisitor&);
	};

	class Type_Bool : public Type
	{
	public:
		// constructors
		Type_Bool();
		Type_Bool(int,int,int,int);
		Type_Bool(const NodeLocation&);

		virtual inference::ShallowType get_type() const;

		virtual void accept(visitor::ASTVisitor&);
	};


	class Type_Function : public Type
	{
	public:
		// constructors
		Type_Function();
		Type_Function(int,int,int,int);
		Type_Function(const NodeLocation&);

		virtual inference::ShallowType get_type() const;
		virtual void accept(visitor::ASTVisitor&);
	};
}
#endif
