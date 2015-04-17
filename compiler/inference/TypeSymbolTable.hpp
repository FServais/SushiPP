#ifndef TYPE_SYMBOL_TABLE_HPP_DEFINED
#define TYPE_SYMBOL_TABLE_HPP_DEFINED

#include <unordered_map>
#include <memory>
#include "TypeSymbol.hpp"

namespace inference
{
	/**
	 * Maps a type symbol name with its relative information
	 * Name must be either a type variable name or a identifier name (must be unique so need to be prefixed for avoiding
	 * collision of two identifiers of different namespaces)
	 */
	class TypeSymbolTable : public std::unordered_map<size_t, size_t>
	{
	public:
		TypeSymbolTable();
		static size_t get_unique_type_symbol_id();
	private:
		static size_t symbol_id_cnt;
	};
}
#endif // TYPE_SYMBOL_TABLE_HPP_DEFINED