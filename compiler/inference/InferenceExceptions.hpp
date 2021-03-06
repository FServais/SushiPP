#ifndef INFERENCE_EXCEPTIONS_HPP_DEFINED
#define INFERENCE_EXCEPTIONS_HPP_DEFINED 

#include <stdexcept>
#include <string>

#include "Types.hpp"
#include "TypeSymbol.hpp"

namespace except
{
	/** Unification exception */
	class UnificationException : public std::runtime_error
	{
	public:
		// param : some more details about the error
		explicit UnificationException(const std::string&);
	};

	/** Unification exception with a uniparameter type */
	class UniparameterTypesUnificationException : public UnificationException
	{
	public:
		/**
		 * @brief Couldn't unify the given type symbols
		 */
		UniparameterTypesUnificationException(const inference::UniparameterType&, const inference::TypeSymbol&);
	};
	
	/** Unification exception with a flat type */
	class FlatTypesUnificationException : public UnificationException
	{
	public:
		/**
		 * @brief Couldn't unify the symbol with flat type
		 */
		FlatTypesUnificationException(const inference::FlatType&, const inference::TypeSymbol&);
	};
	
	/** Unification exception with a function type */
	class FunctionTypeUnificationException : public UnificationException
	{
	public:
		/**
		 * @brief Couldn't unify the symbol function type
		 */
		FunctionTypeUnificationException(const inference::Function&, const inference::TypeSymbol&); 
	};
	
	/** Unification exception with a hints */
	class HintsUnificationException : public UnificationException
	{
	public:
		/** 
		 * @brief Unification failed because type hints mismatch
		 * @param TypesHint hint1 The first hint (exptected)
		 * @param TypesHint hint2 The second hint (given)
		 */
		HintsUnificationException(inference::TypesHint, inference::TypesHint);
	};

	
	/** Unification exception with a paraemter mismatch in a function */
	class ParameterNumberMismatchException : public UnificationException
	{
	public:
		/** 
		 * @brief Unification failed because two function hadn't the same number of parameters
		 * @param size_t number1 The first number of parameters
		 * @param size_t number2 The second number of parameters
		 */
		ParameterNumberMismatchException(size_t, size_t);
	};
	
	/** Trying to a variable name in the table which already exists */
	class ExistingTypeSymbolException : public std::logic_error
	{
	public:
		// param : the name of the type symbol 
		explicit ExistingTypeSymbolException(const std::string&);
	};

	/** Trying to access an unexisting variable name in table  */
	class NoSuchTypeSymbolException : public std::runtime_error
	{
	public:
		// param : the name of the type symbol 
		explicit NoSuchTypeSymbolException(const std::string&);
	};

	/** Trying to get a complete type out of a unresolved type variable */
	class UnresolvableTypeException : public std::runtime_error
	{
	public:
		// param : the name of the type symbol 
		explicit UnresolvableTypeException(const std::string&);
	};
}

#endif // EXCEPTIONS_HPP_DEFINED