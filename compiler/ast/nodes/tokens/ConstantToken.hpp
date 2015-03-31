#ifndef CONSTANT_TOKEN
#define CONSTANT_TOKEN

namespace ast::nodes::tokens::constants
{ 
	/** Constant token base class */
	class ConstantToken : public Token
	{
	public: 
		// constructors
		ConstantToken(const std::string&);
		ConstantToken(const std::string&,int,int,int,int);
		ConstantToken(const std::string&,const ast::nodes::NodeLocation&);
	};

	/** Constant token derived class */
	class String : public ConstantToken
	{
	public:
		// constructors
		// the string field is the value of the string literal as matched by the lexer (i.e. with double quotes)
		String(const std::string&);
		String(const std::string&,int,int,int,int);
		String(const std::string&,const ast::nodes::NodeLocation&);

		// accessor
		std::string& value() const;
		const std::string& value() const;

	private:
		std::string str_val;
	};

	class Character : public ConstantToken
	{
	public:
		// constructors
		// the string field is the value of the char literal as matched by the lexer (i.e. with quotes)
		Character(const std::string&);
		Character(const std::string&,int,int,int,int);
		Character(const std::string&,const ast::nodes::NodeLocation&);

		// accessor
		char value() const;
		
	private:
		char char_val;
	};

	class Integer : public ConstantToken
	{
	public:
		// constructors
		// the string field is the value of the integer literal as matched by the lexer
		Integer(const std::string&);
		Integer(const std::string&,int,int,int,int);
		Integer(const std::string&,const ast::nodes::NodeLocation&);

		// accessor
		int value() const;
		
	private:
		int int_val;
	};

	class Float : public ConstantToken
	{
	public:
		// constructors
		// the string field is the value of the float literal as matched by the lexer
		Float(const std::string&);
		Float(const std::string&,int,int,int,int);
		Float(const std::string&,const ast::nodes::NodeLocation&);

		// accessor
		float value() const;
		
	private:
		float float_val;
	};

	class Bool : public ConstantToken
	{
	public:
		// constructors
		// the string field is the value of the float literal as matched by the lexer
		Bool(const std::string&);
		Bool(const std::string&,int,int,int,int);
		Bool(const std::string&,const ast::nodes::NodeLocation&);

		// accessor
		bool value() const;
		
	private:
		bool bool_val;
	};
}

#endif // CONSTANT_TOKEN 