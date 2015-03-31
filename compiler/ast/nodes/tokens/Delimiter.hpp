#ifndef DELIMITER_HPP_DEFINED
#define DELIMITER_HPP_DEFINED

#include "Token.hpp"

namespace ast::nodes::tokens::Delimiters
{
	
	
	/** Delimiter derived class */
	class Delimeol : public Delimiter
	{
	public: 
		// constructors
		Delimeol();
		Delimeol(int,int,int,int);
		Delimeol(const ast::nodes::NodeLocation&);
	};

	class Delimeos : public Delimiter
	{
	public: 
		// constructors
		Delimeos();
		Delimeos(int,int,int,int);
		Delimeos(const ast::nodes::NodeLocation&);
	};

	class TupleBeg : public Delimiter
	{
	public: 
		// constructors
		TupleBeg();
		TupleBeg(int,int,int,int);
		TupleBeg(const ast::nodes::NodeLocation&);
	};

	class TupleEnd: public Delimiter
	{
	public: 
		// constructors
		TupleEnd();
		TupleEnd(int,int,int,int);
		TupleEnd(const ast::nodes::NodeLocation&);
	};

	class ArrayBeg : public Delimiter
	{
	public: 
		// constructors
		ArrayBeg();
		ArrayBeg(int,int,int,int);
		ArrayBeg(const ast::nodes::NodeLocation&);
	};

	class ArrayEnd : public Delimiter
	{
	public: 
		// constructors
		ArrayEnd();
		ArrayEnd(int,int,int,int);
		ArrayEnd(const ast::nodes::NodeLocation&);
	};

	class Arrow : public Delimiter
	{
	public: 
		// constructors
		Arrow();
		Arrow(int,int,int,int);
		Arrow(const ast::nodes::NodeLocation&);
	};

	class Virg : public Delimiter
	{
	public: 
		// constructors
		Virg();
		Virg(int,int,int,int);
		Virg(const ast::nodes::NodeLocation&);
	};
	
	class OpenPar : public Delimiter
	{
	public: 
		// constructors
		OpenPar();
		OpenPar(int,int,int,int);
		OpenPar(const ast::nodes::NodeLocation&);
	};
	
	class ClosingPar : public Delimiter
	{
	public:
		// constructors
		ClosingPar();
		ClosingPar(int,int,int,int);
		ClosingPar(const ast::nodes::NodeLocation&);
	};
	
	class OpenBrace : public Delimiter
	{
	public: 
		// constructors
		OpenBrace();
		OpenBrace(int,int,int,int);
		OPenBrace(const ast::nodes::NodeLocation&);
	};
	
	class ClosingBrace : public Delimiter
	{
	public: 
		// constructors
		ClosingBrace();
		ClosingBrace(int,int,int,int);
		ClosingBrace(const ast::nodes::NodeLocation&);
	};
	
	class OpenAcc : public Delimiter
	{
	public: 
		// constructors
		OpenAcc();
		OpenAcc(int,int,int,int);
		OpenAcc(const ast::nodes::NodeLocation&);
	};
	
	class ClosingAcc : public Delimiter
	{
	public: 
		// constructors
		ClosingAcc();
		ClosingAcc(int,int,int,int);
		ClosingAcc(const ast::nodes::NodeLocation&);
	};
	
	class Underscore : public Delimiter
	{
	public: 
		// constructors
		Underscore();
		Underscore(int,int,int,int);
		Underscore(const ast::nodes::NodeLocation&);
	};
	
	
}
#endif