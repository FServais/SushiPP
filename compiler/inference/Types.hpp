#ifndef TYPES_HPP_DEFINED
#define TYPES_HPP_DEFINED

#include <string>
#include <vector>

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

	std::string to_string(ShallowType);

	/**
	 * @class A class for representing a set of possible types
	 */
	class TypesHint
	{
	public: 
		// default constructor : contains all the types
		TypesHint(); 
		// constructed with a mask a mask of shallow type
		explicit TypesHint(int);
		// constructured with the set of shallow types composing it
		explicit TypesHint(const std::vector<ShallowType>&);

		/**
		 * @brief Check the compatibility between the given types hint and the given ShallowType mask
		 * @param int mask The shallow type mask
		 * @retval bool True if they are compatible, false otherwise
		 * @note They are compatible if they have at least one type in common
		 */
		bool compatible(int) const;
		
		/**
		 * @brief Check the compatibility between the given types hint and another one
		 * @param TypesHint the other type hint object
		 * @retval bool True if they are compatible, false otherwise
		 * @note They are compatible if they have at least one type in common
		 */
		bool compatible(const TypesHint&) const;

		/**
		 * @brief Add some new types in the current types hint
		 * @param int mask A mask of shallow type
		 * @param TypesHint The type hint containing the new types to add
		 */
		void hints_union(int);
		void hints_union(const TypesHint&);


		/**
		 * @brief Update the set of types by taking the intersection between the current set and the given one
		 * @param int mask A mask of shallow type
		 */
		void hints_intersection(int);
		void hints_intersection(const TypesHint&);

		/**
		 * @brief Remove some types from the current types hint 
		 * @param int mask A mask of shallow types
		 * @note Can be considered as a set difference
		 */
		void remove(int); 
		void remove(const TypesHint&);

		/**
		 * @brief Convert the TypesHint objectinto a string
		 * @retval std::string The TypesHint string 
		 */
		std::string str() const;

	private:
		int hints; // a mask defining the types containing in the object
		 		   // Values taken from ShallowType
	};
}

#endif // TYPES_HPP_DEFINED