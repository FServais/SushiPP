#ifndef NT_DATASTRUCTURE_HPP_DEFINED
#define NT_DATASTRUCTURE_HPP_DEFINED

#include "NonTerminal.hpp"
#include "NT_Expression.hpp"

namespace ast
{
	/*************************************************
	 * Intermediate NT_Datastructure node base class *
	 *************************************************/
	class NT_Datastructure : public NonTerminal
	{
	public:
		// Constructors
		NT_Datastructure(const std::string&);
		NT_Datastructure(const std::string&,int,int,int,int);
		NT_Datastructure(const std::string&,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	/***************************************
	 * Datastructure rules node base class *
	 ***************************************/

	class Array : public NT_Datastructure
	{
	public:
		// Constructors
		Array();
		Array(int,int,int,int);
		Array(const NodeLocation&);

		// Child : item(s)
		Array(ASTNode*);
		Array(ASTNode*, int,int,int,int);
		Array(ASTNode*, const NodeLocation&);

		bool empty_items() const;
		ASTNode& get_items();

		virtual void accept(ASTVisitor&);
	};

	class List : public NT_Datastructure
	{
	public:
		// Constructors
		List();
		List(int,int,int,int);
		List(const NodeLocation&);

		// Child : item(s)
		List(ASTNode*);
		List(ASTNode*, int,int,int,int);
		List(ASTNode*, const NodeLocation&);

		bool empty_items() const;
		ASTNode& get_items();

		virtual void accept(ASTVisitor&);
	};

	class MakeSequenceList : public NT_Datastructure
	{
	public:
		// Constructors
		// Children : begin ("to") end
		MakeSequenceList(Expression*,Expression*);
		MakeSequenceList(Expression*,Expression*,int,int,int,int);
		MakeSequenceList(Expression*,Expression*,const NodeLocation&);

		Expression& get_begin();
		Expression& get_end();

		virtual void accept(ASTVisitor&);
	};

	class MakeSequenceArray : public NT_Datastructure
	{
	public:
		// Constructors
		// Children : begin ("to") end
		MakeSequenceArray(Expression*,Expression*);
		MakeSequenceArray(Expression*,Expression*,int,int,int,int);
		MakeSequenceArray(Expression*,Expression*,const NodeLocation&);

		Expression& get_begin();
		Expression& get_end();

		virtual void accept(ASTVisitor&);
	};

	class SeqExpression : public NT_Datastructure
	{
	public:
		// Constructors
		// Children : begin ("to") end
		SeqExpression(Expression*,Expression*);
		SeqExpression(Expression*,Expression*,int,int,int,int);
		SeqExpression(Expression*,Expression*,const NodeLocation&);

		Expression& get_begin();
		Expression& get_end();

		virtual void accept(ASTVisitor&);
	};
}

#endif
