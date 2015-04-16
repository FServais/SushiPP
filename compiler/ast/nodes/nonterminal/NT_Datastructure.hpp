#ifndef NT_DATASTRUCTURE_HPP_DEFINED
#define NT_DATASTRUCTURE_HPP_DEFINED

#include "NonTerminal.hpp"

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
	class Datastructure : public NT_Datastructure
	{
	public:
		// Constructors
		Datastructure();
		Datastructure(int,int,int,int);
		Datastructure(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Array : public NT_Datastructure
	{
	public:
		// Constructors
		Array();
		Array(int,int,int,int);
		Array(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class List : public NT_Datastructure
	{
	public:
		// Constructors
		List();
		List(int,int,int,int);
		List(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class MakeSequence : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequence();
		MakeSequence(int,int,int,int);
		MakeSequence(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class MakeSequenceList : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequenceList();
		MakeSequenceList(int,int,int,int);
		MakeSequenceList(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class MakeSequenceArray : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequenceArray();
		MakeSequenceArray(int,int,int,int);
		MakeSequenceArray(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class SeqExpression : public NT_Datastructure
	{
	public:
		// Constructors
		SeqExpression();
		SeqExpression(int,int,int,int);
		SeqExpression(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}

#endif
