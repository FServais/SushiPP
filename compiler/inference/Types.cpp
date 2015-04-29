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
	case BOOL : return string("BOOL"); 
	case INT : return string("INT");
	case FLOAT : return string("FLOAT");
	case STRING : return string("STRING");
	case CHAR : return string("CHAR");
	case ARRAY : return string("ARRAY");
	case LIST : return string("LIST");
	case FUNCTION : return string("FUNCTION");
	case VOID : return string("VOID");	
	default: return string();
	}
}