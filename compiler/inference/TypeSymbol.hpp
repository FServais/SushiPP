#ifndef TYPE_SYMBOL_HPP_DEFINED
#define TYPE_SYMBOL_HPP_DEFINED

#include <string>
#include <vector>
#include <memory>

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
		virtual ~TypeSymbol() {};
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
	 * @class TypeLink
	 * @brief Represent a link to a type symbol
	 * A typelink has two modes :
	 * 1) Either it is linked type link which was allocated in another context
	 * 2) Or it is linked to an actual type (functio, array, list or flat) or a type variable. In this case, 
	 *   the type link object has the ownership of the underlying object (which must be dynamically allocated)
	 */
	class TypeLink : public TypeSymbol
	{
	public:
		/**
		 * @brief Construct a type link object
		 * @param Symbol* link A pointer to the symbol type owned by the link
		 * @note The object acquire the ownership
		 */
		TypeLink(TypeSymbol*);

		// disable copy constructor, and assignment operator
		TypeLink(const TypeLink&) = delete;
		TypeLink& operator=(const TypeLink&) = delete;

		virtual ~TypeLink();

		/**
		 * @brief Set the symbol linked by the type link
		 * @param TypeLink* link A pointer to a link object (must not be allocated dynamically)
		 * @note The object acquire the ownership
		 */
		void set_symbol(TypeSymbol*);

		/**
		 * @brief Get the actual type object or type linked to the current link
		 */
		TypeSymbol& resolve();
		const TypeSymbol& resolve() const;

		/**
		 * @brief Get the last link before the an actual type object or type variable
		 */
		TypeLink& resolve_last_link();
		const TypeLink& resolve_last_link() const;

		/**
		 * @brief Get the type symbol pointed by the object
		 */
		TypeSymbol& symbol();
		const TypeSymbol& symbol() const;

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
		TypeSymbol* linked_symbol; // underlying link object, nullptr if (*this) does not point to a type link object
		bool symbol_is_link; // true if the linked symbol points to a link, false otherwise
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
		Function(const std::vector<std::reference_wrapper<TypeLink>>&, TypeLink&);

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
		TypeLink& get_return_type() { return return_type; };
		const TypeLink& get_return_type() const { return return_type; };

		/** Getters for the parameters */
		std::vector<std::reference_wrapper<TypeLink>>& get_parameters() { return parameters; };
		const std::vector<std::reference_wrapper<TypeLink>>& get_parameters() const { return parameters; };

	private:
		TypeLink& return_type;
		std::vector<std::reference_wrapper<TypeLink>> parameters;
	};

	/**
	 * @class UniparameterType
	 * @brief A base class for any structured type containing one type parameter
 	 */
	class UniparameterType : public StructuredType
	{
	public:
		UniparameterType(TypeLink&);

		virtual bool is_function_type() const { return false; };
		virtual bool is_uniparameter_type() const { return true; };

		virtual bool is_array() const = 0;
		virtual bool is_list() const = 0;

		// parameter type getters
		TypeLink& get_param_type() { return parameter_type; };
		const TypeLink& get_param_type() const { return parameter_type; };

	protected:
		TypeLink& parameter_type;
	};

	/**
	 * @class Array
	 * @brief Array type
	 */
	class Array : public UniparameterType
	{
	public:
		/** A type link to the structure elements' type */
		Array(TypeLink&);

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
		List(TypeLink&);

		virtual std::string str() const;
		virtual bool equals(const TypeSymbol&) const;

		virtual bool is_array() const { return false; };
		virtual bool is_list() const { return true; };
	};
}

#endif // TYPE_SYMBOL_HPP_DEFINED