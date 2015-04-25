#ifndef TYPE_SYMBOL_HPP_DEFINED
#define TYPE_SYMBOL_HPP_DEFINED

#include <string>
#include <vector>
#include <memory>

#include "../types/Type.hpp"

namespace inference
{
	/**
	 * @class TypeSymbol
	 * @brief Base class for any type symbol. A type symbol can be :
	 *  - a flat type (Char, String, Bool, Int, Float, Void)
	 *  - the array type
	 *  - the list type
	 *  - the function type
	 *  - a type variable
	 *  - a link to a TypeSymbol
	 */
	class TypeSymbol
	{
	public:
		// predicates
		virtual bool is_link() const = 0;
		virtual bool is_variable() const = 0;
		virtual bool is_type() const = 0;
		virtual bool is_flat_type() const = 0;
		virtual bool is_function_type() const = 0;
		virtual bool is_structure_type() const = 0; // true if the TypeSymbol is the array or list type
		virtual bool equals(const TypeSymbol&) const = 0; // return true if the given type symbol is equal to the one given as argument
													// if one of the element is a link it is resolved before comparison
		/**
		 * @brief Return the actual type of the type symbol
		 * @throw TypeSymbolResolutionException If an actual type cannot be returned (if the link is not resolvable
		 * to a complete type, if the type symbol is a variable)
		 */
		//virtual void get_type(types::Type*) const = 0;

		/**
		 * @brief Unify the current type symbol with the given one
		 * @param TypeSymbol& symb The symbol to unify the current one with
		 * @throw UnificationException if the unification is impossible to perform during the unification
		 */
		//virtual void unify(std::shared_ptr<TypeLink>) = 0;
	};

	/**
	 * @class TypeVariable
	 * @brief A type variable
	 */
	class TypeVariable : public TypeSymbol
	{
	public:
		explicit TypeVariable(const std::string&);

		virtual bool is_link() const { return false; }
		virtual bool is_variable() const { return true; }
		virtual bool is_type() const { return false; }
		virtual bool is_flat_type() const { return false; }
		virtual bool is_function_type() const { return false; }
		virtual bool is_structure_type() const { return false; }
		virtual bool equals(const TypeSymbol&) const;

	private:
		std::string varname;
	};

	/**Type
	 * @class TypeLink
	 * @brief Represent a link to a type symbol
	 */
	class TypeLink : public TypeSymbol
	{
	public:
		TypeLink(std::shared_ptr<TypeSymbol>);

		TypeSymbol& resolve();
		const TypeSymbol& resolve() const;

		virtual bool is_link() const { return true; }
		virtual bool is_variable() const { return false; }
		virtual bool is_type() const { return false; }
		virtual bool is_flat_type() const { return false; }
		virtual bool is_function_type() const { return false; }
		virtual bool is_structure_type() const { return false; }
		virtual bool equals(const TypeSymbol&) const;

	private:
		std::shared_ptr<TypeSymbol> symbol; // the symbol linked by the object
	};

	/**
	 * @class Type
	 * @brief Base class for any actual type
	 */
	class Type : public TypeSymbol
	{
	public:
		virtual bool is_link() const { return false; }
		virtual bool is_variable() const { return false; }
		virtual bool is_type() const { return true; }
	};

	/**
	 * @class FlatType
	 * @brief Base class for any base type
	 */
	class FlatType : public Type
	{
	public:
		virtual bool is_flat_type() const { return true; };
		virtual bool is_function_type() const { return false; };
		virtual bool is_structure_type() const { return false; };
	};

	/**
	 * @class Bool
	 * @brief Bool flat type
	 */
	class Bool : public FlatType
	{
	public:
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class String
	 * @brief String flat type
	 */
	class String : public FlatType
	{
	public:
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Int
	 * @brief Int flat type
	 */
	class Int : public FlatType
	{
	public:
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Float
	 * @brief Float flat type
	 */
	class Float : public FlatType
	{
	public:
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Void
	 * @brief Void flat type
	 */
	class Void : public FlatType
	{
	public:
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Char
	 * @brief Char flat type
	 */
	class Char : public FlatType
	{
	public:
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Function
	 * @brief Function type
	 */
	class Function : public Type
	{
	public:
		Function(const std::vector<std::shared_ptr<TypeLink>>&, std::shared_ptr<TypeLink>);

		virtual bool is_flat_type() const { return false; };
		virtual bool is_function_type() const { return true; };
		virtual bool is_structure_type() const { return false; };
		virtual bool equals(const TypeSymbol&) const;
/*
		types::Type get_return_type() const;
		types::Type get_parameter_type(size_t) const;
		void get_parameter_types(std::vector<types::Type>&) const;
		*/

	private:
		std::shared_ptr<TypeLink> return_type;
		std::vector<std::shared_ptr<TypeLink>> parameters;
	};

	/**
	 * @class Array
	 * @brief Array type
	 */
	class Array : public Type
	{
	public:
		/** A type link to the structure elements' type */
		Array(std::shared_ptr<TypeLink>);

		virtual bool is_flat_type() const { return false; };
		virtual bool is_function_type() const { return false; };
		virtual bool is_structure_type() const { return true; };
		virtual bool equals(const TypeSymbol&) const;

	private:
		std::shared_ptr<TypeLink> items_type;
	};

	/**
	 * @class List
	 * @brief List type
	 */
	class List : public Type
	{
	public:
		/** A type link to the structure elements' type */
		List(std::shared_ptr<TypeLink>);

		virtual bool is_flat_type() const { return false; };
		virtual bool is_function_type() const { return false; };
		virtual bool is_structure_type() const { return true; };
		virtual bool equals(const TypeSymbol&) const;

	private:
		std::shared_ptr<TypeLink> items_type;
	};
}

#endif // TYPE_SYMBOL_HPP_DEFINED