#ifndef NT_DATASTRUCTURE_HPP_DEFINED
#define NT_DATASTRUCTURE_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_datastructure
{
	/*************************************************
	 * Intermediate NT_Datastructure node base class *
	 *************************************************/
	class NT_Datastructure : public NonTerminal
	{
	public:
		// Constructors
		NT_Datastructure();
		NT_Datastructure(int,int,int,int);
		NT_Datastructure(const ast::nodes::NodeLocation&);
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
		Datastructure(const ast::nodes::NodeLocation&);
	};

	class Array : public NT_Datastructure
	{
	public:
		// Constructors
		Array();
		Array(int,int,int,int);
		Array(const ast::nodes::NodeLocation&);
	};

	class List : public NT_Datastructure
	{
	public:
		// Constructors
		List();
		List(int,int,int,int);
		List(const ast::nodes::NodeLocation&);
	};

	class Tuple : public NT_Datastructure
	{
	public:
		// Constructors
		Tuple();
		Tuple(int,int,int,int);
		Tuple(const ast::nodes::NodeLocation&);
	};

	class MakeSequence : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequence();
		MakeSequence(int,int,int,int);
		MakeSequence(const ast::nodes::NodeLocation&);
	};

	class MakeSequenceList : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequenceList();
		MakeSequenceList(int,int,int,int);
		MakeSequenceList(const ast::nodes::NodeLocation&);
	};

	class MakeSequenceArray : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequenceArray();
		MakeSequenceArray(int,int,int,int);
		MakeSequenceArray(const ast::nodes::NodeLocation&);
	};

	class SeqExpression : public NT_Datastructure
	{
	public:
		// Constructors
		SeqExpression();
		SeqExpression(int,int,int,int);
		SeqExpression(const ast::nodes::NodeLocation&);
	};
}

#endif
