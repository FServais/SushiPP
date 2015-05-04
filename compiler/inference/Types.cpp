#include "Types.hpp"

#include <sstream>
#include <numeric>

#include "../util.hpp"

using namespace std;
using namespace inference;

TypesHint::TypesHint() 
{
	hints = BOOL | INT | FLOAT | STRING |
			CHAR | ARRAY | LIST | FUNCTION | VOID;
}

TypesHint::TypesHint(int mask) : hints(mask)
{

}

TypesHint::TypesHint(const std::vector<ShallowType>& types) 
{
	hints = accumulate(types.begin(), types.end(), 0, [](int acc, ShallowType s) { return acc |= s; });
}

bool TypesHint::compatible(int mask) const
{
	return mask & hints;
}

bool TypesHint::compatible(const TypesHint& hints_) const
{
	return hints_.hints & hints;
}

void TypesHint::hints_union(int mask)
{
	hints |= mask;
}

void TypesHint::hints_union(const TypesHint& hints_)
{
	hints |= hints_.hints;
}

void TypesHint::hints_intersection(int mask)
{
	hints &= mask;
}

void TypesHint::hints_intersection(const TypesHint& hints_)
{
	hints &= hints_.hints;
}

void TypesHint::remove(int mask)
{
	hints &= ~mask;
}

void TypesHint::remove(const TypesHint& hints_)
{
	hints &= ~hints_.hints;
}

string TypesHint::str() const
{
	vector<ShallowType> types = { NO_TYPE, BOOL, INT, FLOAT, STRING, 
								  CHAR, ARRAY, LIST, FUNCTION, VOID };
	vector<string> hints_elements; 
	for(ShallowType s_type : types)
		if(hints & s_type)
			hints_elements.push_back(to_string(s_type));
	return util::implode(hints_elements.begin(), hints_elements.end(), ", ");
}

string inference::to_string(ShallowType s_type)
{
	switch(s_type)
	{
	case NO_TYPE : return string("NO_TYPE");
	case BOOL : return string("bool"); 
	case INT : return string("int");
	case FLOAT : return string("float");
	case STRING : return string("string");
	case CHAR : return string("char");
	case ARRAY : return string("array");
	case LIST : return string("list");
	case FUNCTION : return string("function");
	case VOID : return string("void");	
	default: return string();
	}
}