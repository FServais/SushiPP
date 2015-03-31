#ifndef DELIMITER_HPP_DEFINED
#define DELIMITER_HPP_DEFINED

#include <string>
#include "Token.hpp"
#include "../NodeLocation.hpp"

namespace ast
{
	/** Delimiter derived class */
	class Delimiter : public Token
	{
	public:
		// constructors
		Delimiter(const std::string&);
		Delimiter(const std::string&,int,int,int,int);
		Delimiter(const std::string&,const NodeLocation&);
	};

	/** Delimiter derived class */
	class DelimEol : public Delimiter
	{
	public:
		// constructors
		DelimEol();
		DelimEol(int,int,int,int);
		DelimEol(const NodeLocation&);
	};

	class DelimEos : public Delimiter
	{
	public:
		// constructors
		DelimEos();
		DelimEos(int,int,int,int);
		DelimEos(const NodeLocation&);
	};

	class TupleBeg : public Delimiter
	{
	public:
		// constructors
		TupleBeg();
		TupleBeg(int,int,int,int);
		TupleBeg(const NodeLocation&);
	};

	class TupleEnd: public Delimiter
	{
	public:
		// constructors
		TupleEnd();
		TupleEnd(int,int,int,int);
		TupleEnd(const NodeLocation&);
	};

	class ArrayBeg : public Delimiter
	{
	public:
		// constructors
		ArrayBeg();
		ArrayBeg(int,int,int,int);
		ArrayBeg(const NodeLocation&);
	};

	class ArrayEnd : public Delimiter
	{
	public:
		// constructors
		ArrayEnd();
		ArrayEnd(int,int,int,int);
		ArrayEnd(const NodeLocation&);
	};

	class Arrow : public Delimiter
	{
	public:
		// constructors
		Arrow();
		Arrow(int,int,int,int);
		Arrow(const NodeLocation&);
	};

	class Virg : public Delimiter
	{
	public:
		// constructors
		Virg();
		Virg(int,int,int,int);
		Virg(const NodeLocation&);
	};

	class OpenPar : public Delimiter
	{
	public:
		// constructors
		OpenPar();
		OpenPar(int,int,int,int);
		OpenPar(const NodeLocation&);
	};

	class ClosingPar : public Delimiter
	{
	public:
		// constructors
		ClosingPar();
		ClosingPar(int,int,int,int);
		ClosingPar(const NodeLocation&);
	};

	class OpenBrace : public Delimiter
	{
	public:
		// constructors
		OpenBrace();
		OpenBrace(int,int,int,int);
		OpenBrace(const NodeLocation&);
	};

	class ClosingBrace : public Delimiter
	{
	public:
		// constructors
		ClosingBrace();
		ClosingBrace(int,int,int,int);
		ClosingBrace(const NodeLocation&);
	};

	class OpenChevr : public Delimiter
	{
	public:
		// constructors
		OpenChevr();
		OpenChevr(int,int,int,int);
		OpenChevr(const NodeLocation&);
	};

	class ClosingChevr : public Delimiter
	{
	public:
		// constructors
		ClosingChevr();
		ClosingChevr(int,int,int,int);
		ClosingChevr(const NodeLocation&);
	};

	class OpenAcc : public Delimiter
	{
	public:
		// constructors
		OpenAcc();
		OpenAcc(int,int,int,int);
		OpenAcc(const NodeLocation&);
	};

	class ClosingAcc : public Delimiter
	{
	public:
		// constructors
		ClosingAcc();
		ClosingAcc(int,int,int,int);
		ClosingAcc(const NodeLocation&);
	};

	class Underscore : public Delimiter
	{
	public:
		// constructors
		Underscore();
		Underscore(int,int,int,int);
		Underscore(const NodeLocation&);
	};
}
#endif
