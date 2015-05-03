#include "InferenceExceptions.hpp"

using namespace std;
using namespace except;
using namespace inference;

UnificationException::UnificationException(const string& details)
  : runtime_error(details)
{

}

FunctionTypeUnificationException::FunctionTypeUnificationException(const Function& symb1, const TypeSymbol& symb2) 
  : UnificationException("function type `" + symb1.str() + "´ expected, type `" + symb2.str() + "´ given")
{

}

UniparameterTypesUnificationException::UniparameterTypesUnificationException(const UniparameterType& symb1, 
																			 const TypeSymbol& symb2)
  : UnificationException("datastructure type `" + symb1.str() + "´ expected, type `" + symb2.str() + "´ given")
{

}

FlatTypesUnificationException::FlatTypesUnificationException(const FlatType& flat, const TypeSymbol& symb)
  : UnificationException("flat type `" + symb.str() + "´ expected, type `" + flat.str() + "´ given")
{

}

HintsUnificationException::HintsUnificationException(TypesHint hint1, TypesHint hint2)
  : UnificationException("element expected a type among `" + hint1.str() + "´, given `" + hint2.str() + "´")
{

}

ParameterNumberMismatchException::ParameterNumberMismatchException(size_t number1, size_t number2)
  : UnificationException("function should have " + to_string(number1) + " parameter(s), " + to_string(number2) + " parameter(s) given")
{

}


ExistingTypeSymbolException::ExistingTypeSymbolException(const string& symbol)
  : logic_error("Attempting to add the existing symbol '" + symbol + "' in the type symbol table")
{

}

UnresolvableTypeException::UnresolvableTypeException(const string& symbol)
  : runtime_error("The type of the type symbol '" + symbol + "' cannot be resolved")
{

}

NoSuchTypeSymbolException::NoSuchTypeSymbolException(const string& symbol)
  : runtime_error("Unable to find the type symbol '" + symbol + "'")
{

}