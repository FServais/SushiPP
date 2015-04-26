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
		/** Return the type in a string format (in one line without EOL) */
		virtual std::string str() const = 0;
		// predicates
		virtual bool is_link() const = 0;
		virtual bool is_variable() const = 0;
		virtual bool is_type() const = 0;
		virtual bool is_flat_type() const = 0;
		virtual bool is_function_type() const = 0;
		virtual bool is_structured_type() const = 0; // true if the TypeSymbol is the array, list or function type
		virtual bool is_uniparameter_type() const = 0;  // true if the TypeSymbol is the array or list type
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

		virtual std::string str() const { return varname; };
		virtual bool is_link() const { return false; }
		virtual bool is_variable() const { return true; }
		virtual bool is_type() const { return false; }
		virtual bool is_flat_type() const { return false; }
		virtual bool is_function_type() const { return false; }
		virtual bool is_structured_type() const { return false; }
		virtual bool is_uniparameter_type() const { return false; }
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

		/**
		 * @brief Get the actual type object or type linked to the current link
		 */
		TypeSymbol& resolve();
		const TypeSymbol& resolve() const;

		/**
		 * @brief Set the symbol linked by the type link
		 */
		void set_symbol(std::shared_ptr<TypeSymbol>);

		/**
		 * @brief Get the last link before the an actual type object or type variable
		 */
		TypeLink& resolve_last_link();
		const TypeLink& resolve_last_link() const;

		virtual std::string str() const;
		virtual bool is_link() const { return true; }
		virtual bool is_variable() const { return false; }
		virtual bool is_type() const { return false; }
		virtual bool is_flat_type() const { return false; }
		virtual bool is_function_type() const { return false; }
		virtual bool is_structured_type() const { return false; }
		virtual bool is_uniparameter_type() const { return false; }
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
		virtual bool is_structured_type() const { return false; }
		virtual bool is_uniparameter_type() const { return false; }
	};

	/**
	 * @class Bool
	 * @brief Bool flat type
	 */
	class Bool : public FlatType
	{
	public:
		virtual std::string str() const { return "BOOL"; }
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class String
	 * @brief String flat type
	 */
	class String : public FlatType
	{
	public:
		virtual std::string str() const { return "STRING"; }
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Int
	 * @brief Int flat type
	 */
	class Int : public FlatType
	{
	public:
		virtual std::string str() const { return "INT"; }
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Float
	 * @brief Float flat type
	 */
	class Float : public FlatType
	{
	public:
		virtual std::string str() const { return "FLOAT"; }
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Void
	 * @brief Void flat type
	 */
	class Void : public FlatType
	{
	public:
		virtual std::string str() const { return "VOID"; }
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class Char
	 * @brief Char flat type
	 */
	class Char : public FlatType
	{
	public:
		virtual std::string str() const { return "CHAR"; }
		virtual bool equals(const TypeSymbol&) const;
	};

	/**
	 * @class StructuredType
	 * @brief A class for complex type that could be composed of other types
	 */
	class StructuredType : public Type
	{
	public:
		virtual bool is_flat_type() const { return false; }
		virtual bool is_structured_type() const { return true; }
	};

	/**
	 * @class Function
	 * @brief Function type
	 */
	class Function : public StructuredType
	{
	public:
		Function(const std::vector<std::shared_ptr<TypeLink>>&, std::shared_ptr<TypeLink>);

		virtual std::string str() const;
		virtual bool is_function_type() const { return true; };
		virtual bool is_uniparameter_type() const { return false; }
		virtual bool equals(const TypeSymbol&) const;
/*
		types::Type get_return_type() const;
		types::Type get_parameter_type(size_t) const;
		void get_parameter_types(std::vector<types::Type>&) const;
		*/

		/** Getters for the return type */
		std::shared_ptr<TypeLink> get_return_type() { return return_type; };
		const std::shared_ptr<TypeLink> get_return_type() const { return return_type; };

		/** Getters for the parameters */
		std::vector<std::shared_ptr<TypeLink>>& get_parameters() { return parameters; };
		const std::vector<std::shared_ptr<TypeLink>>& get_parameters() const { return parameters; };

	private:
		std::shared_ptr<TypeLink> return_type;
		std::vector<std::shared_ptr<TypeLink>> parameters;
	};

	/**
	 * @class UniparameterType
	 * @brief A base class for any structured type containing one type parameter
 	 */
	class UniparameterType : public StructuredType
	{
	public:
		UniparameterType(std::shared_ptr<TypeLink>);

		virtual bool is_function_type() const { return false; };
		virtual bool is_uniparameter_type() const { return true; };

		virtual bool is_array() const = 0;
		virtual bool is_list() const = 0;

		// parameter type getters
		std::shared_ptr<TypeLink> get_param_type() { return parameter_type };
		const std::shared_ptr<TypeLink> get_param_type() const { return parameter_type };

	protected:
		std::shared_ptr<TypeLink> parameter_type; 
	};

	/**
	 * @class Array
	 * @brief Array type
	 */
	class Array : public UniparameterType
	{
	public:
		/** A type link to the structure elements' type */
		Array(std::shared_ptr<TypeLink>);

		virtual std::string str() const;
		virtual bool equals(const TypeSymbol&) const;

		virtual bool is_array() const { return true; };
		virtual bool is_list() const { return false; };
	};

	/**
	 * @class List
	 * @brief List type
	 */
	class List : public UniparameterType
	{
	public:
		/** A type link to the structure elements' type */
		List(std::shared_ptr<TypeLink>);

		virtual std::string str() const;
		virtual bool equals(const TypeSymbol&) const;

		virtual bool is_array() const { return false; };
		virtual bool is_list() const { return true; };
	};
}

#endif // TYPE_SYMBOL_HPP_DEFINED