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
		NT_Datastructure(const std::string&);
		NT_Datastructure(const std::string&,int,int,int,int);
		NT_Datastructure(const std::string&,const ast::nodes::NodeLocation&);
	};

	/***************************************
	 * Datastructure rules node base class *
	 ***************************************/
	class Datastructure : public NT_Datastructure
	{
	public:
		// Constructors
		Datastructure(const std::string&);
		Datastructure(const std::string&,int,int,int,int);
		Datastructure(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Array : public NT_Datastructure
	{
	public:
		// Constructors
		Array(const std::string&);
		Array(const std::string&,int,int,int,int);
		Array(const std::string&,const ast::nodes::NodeLocation&);
	};

	class List : public NT_Datastructure
	{
	public:
		// Constructors
		List(const std::string&);
		List(const std::string&,int,int,int,int);
		List(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Tuple : public NT_Datastructure
	{
	public:
		// Constructors
		Tuple(const std::string&);
		Tuple(const std::string&,int,int,int,int);
		Tuple(const std::string&,const ast::nodes::NodeLocation&);
	};

	class MakeSequence : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequence(const std::string&);
		MakeSequence(const std::string&,int,int,int,int);
		MakeSequence(const std::string&,const ast::nodes::NodeLocation&);
	};

	class MakeSequenceList : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequenceList(const std::string&);
		MakeSequenceList(const std::string&,int,int,int,int);
		MakeSequenceList(const std::string&,const ast::nodes::NodeLocation&);
	};

	class MakeSequenceArray : public NT_Datastructure
	{
	public:
		// Constructors
		MakeSequenceArray(const std::string&);
		MakeSequenceArray(const std::string&,int,int,int,int);
		MakeSequenceArray(const std::string&,const ast::nodes::NodeLocation&);
	};

	class SeqExpression : public NT_Datastructure
	{
	public:
		// Constructors
		SeqExpression(const std::string&);
		SeqExpression(const std::string&,int,int,int,int);
		SeqExpression(const std::string&,const ast::nodes::NodeLocation&);
	};
}

#endif
