#ifndef TYPES_HPP_DEFINED
#define TYPES_HPP_DEFINED

namespace inference
{
	/**
	 * @brief SPP types
	 */
	enum ShallowType 
	{
		NO_TYPE = 0, // can be used for indicating that no type were specified
		BOOL = 1, 
		INT = 2,
		FLOAT = 4,
		STRING = 8,
		CHAR = 16,
		ARRAY = 32,
		LIST = 64,
		FUNCTION = 128,
		VOID = 256
	};
}

#endif // TYPES_HPP_DEFINED