#ifndef TYPES_DEFINED_HPP
#define TYPES_DEFINED_HPP 

namespace types 
{
	/**
	 * @class Type
	 * @brief Base class for any types
	 */
	class Type 
	{
	public:
		virtual void accept(TypeVisitor&);
	};

	/**
	 * @class FlatType
	 * @brief Base class for the flat types (int, char, bool, float, string)
	 */
	class FlatType
	{
	public:
		virtual void accept(TypeVisitor&);
	};

	/**
	 * @class Bool
	 * @brief Bool type
	 */
	class Bool
	{
	public:
		virtual void accept(TypeVisitor&);
	};

	/**
	 * @class Char
	 * @brief Char type
	 */
	class Char
	{
	public:
		virtual void accept(TypeVisitor&);
	};

	/**
	 * @class String
	 * @brief String type
	 */
	class String
	{
	public:
		virtual void accept(TypeVisitor&);
	};

	/**
	 * @class Int
	 * @brief Int type
	 */
	class Int
	{
	public:
		virtual void accept(TypeVisitor&);
	};

	/**
	 * @class Float
	 * @brief Float type
	 */
	class Float
	{
	public:
		virtual void accept(TypeVisitor&);
	};

	/**
	 * @class Void
	 * @brief Void type
	 */
	class Void
	{
	public:
		virtual void accept(TypeVisitor&);
	};

	/**
	 * @class Array
	 * @brief Array type
	 */
	class Array
	{
	public:
		/** Build an array of which the elements have the given type */
		Array(const FlatType& elements_type);
		const FlatType& get_elements_type() const; 

		virtual void accept(TypeVisitor&);

	private:
		FlatType elements_type;
	};

	/**
	 * @class List
	 * @brief List type
	 */
	class List
	{
	public:
		/** Build a list of which the elements have the given type */
		List(const FlatType& elements_type);
		const FlatType& get_elements_type() const; 

		virtual void accept(TypeVisitor&);

	private:
		FlatType elements_type;
	};

	/**
	 * @class Function
	 * @brief Function type
	 */
	class Function
	{
	public:
		/** Build a list of which the elements have the given type */
		Function(const std::vector<Type>&, Type);
		

		virtual void accept(TypeVisitor&);

	private:
		std::vector<Type> parameters;
		Type return_type;

	};
}

#endif // TYPES_DEFINED_HPP