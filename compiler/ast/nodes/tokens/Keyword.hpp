#ifndef KEYWORD_HPP_DEFINED
#define KEYWORD_HPP_DEFINED

#include "Token.hpp"

namespace ast::nodes::tokens::keywords
{
	/** Keyword derived class */
	class Maki : public Keyword
	{
	public: 
		// constructors
		Maki();
		Maki(int,int,int,int);
		Maki(const ast::nodes::NodeLocation&);
	};

	class To : public Keyword
	{
	public: 
		// constructors
		To();
		To(int,int,int,int);
		To(const ast::nodes::NodeLocation&);
	};

	class Soy : public Keyword
	{
	public: 
		// constructors
		Soy();
		Soy(int,int,int,int);
		Soy(const ast::nodes::NodeLocation&);
	};

	class Nori: public Keyword
	{
	public: 
		// constructors
		Nori();
		Nori(int,int,int,int);
		Nori(const ast::nodes::NodeLocation&);
	};

	class Menu : public Keyword
	{
	public: 
		// constructors
		Menu();
		Menu(int,int,int,int);
		Menu(const ast::nodes::NodeLocation&);
	};

	class For : public Keyword
	{
	public: 
		// constructors
		For();
		For(int,int,int,int);
		For(const ast::nodes::NodeLocation&);
	};

	class Roll : public Keyword
	{
	public: 
		// constructors
		Roll();
		Roll(int,int,int,int);
		Roll(const ast::nodes::NodeLocation&);
	};

	class Break : public Keyword
	{
	public: 
		// constructors
		Break();
		Break(int,int,int,int);
		Break(const ast::nodes::NodeLocation&);
	};
	
	class Continue : public Keyword
	{
	public: 
		// constructors
		Continue();
		Continue(int,int,int,int);
		Continue(const ast::nodes::NodeLocation&);
	};
	
	class Foreach : public Keyword
	{
	public:
		// constructors
		Foreach();
		Foreach(int,int,int,int);
		Foreach(const ast::nodes::NodeLocation&);
	};
	
	class As : public Keyword
	{
	public: 
		// constructors
		As();
		As(int,int,int,int);
		As(const ast::nodes::NodeLocation&);
	};
	
	class If : public Keyword
	{
	public: 
		// constructors
		If();
		If(int,int,int,int);
		If(const ast::nodes::NodeLocation&);
	};
	
	class Elseif : public Keyword
	{
	public: 
		// constructors
		Elseif();
		Elseif(int,int,int,int);
		Elseif(const ast::nodes::NodeLocation&);
	};
	
	class Else : public Keyword
	{
	public: 
		// constructors
		Else();
		Else(int,int,int,int);
		Else(const ast::nodes::NodeLocation&);
	};
	
}
#endif