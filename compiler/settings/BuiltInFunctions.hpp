#ifndef BUILT_IN_FUNCTIONS_HPP_DEFINED
#define BUILT_IN_FUNCTIONS_HPP_DEFINED

#include <tuple>
#include <unordered_map>
#include <string>
#include <vector>

#include "../inference/Types.hpp"

namespace settings
{

	/**
	 * @brief Different runtime librairies
	 */
	enum Runtime { LIST_RUNTIME, ARRAY_RUNTIME, STRING_RUNTIME, SUPPORT };

	/**
	 * Type representing the information of a built in function
	 * 1st element : name of the function
	 * 2nd element : names of the parameters
	 * 2nd element : types of the parameters
	 * 3rd element : return type
	 * 4th element : type of the datastructure (set to NO_TYPE if not relevant)
	 * 5th element : Runtime
	 */
	typedef std::tuple<std::string,
					   std::vector<std::string>,
					   std::vector<inference::ShallowType>,
					   inference::ShallowType,
					   inference::ShallowType,
					   Runtime>
			BuiltInFunctionInfo;

	/**
	 * @class BuiltInFunctions
	 * @brief Map datastructure containing the information about the S++ built in functions
	 */
	class BuiltInFunctions : public std::unordered_map<std::string, BuiltInFunctionInfo>
	{
	public:
		/**
		 * @brief Construct BuiltInFunctions object and fill it with the Spp built in functions information
		 */
		BuiltInFunctions();

	private:
		/**
		 * @brief Insert a function into the map
		 * @param const std::string& name The function name
		 * @param const std::vector<std::string>& param_names Names of the paramters
		 * @param const std::vector<inference::ShallowType>& param_types The types of the parameters
		 * @param inference::ShallowType ret_type The return type
		 * @param inference::ShallowType ds_type Subtype of the datastructure (optional, default: NO_TYPE)
		 * @param Runtime runtime The runtime in which lies the function
		 */
		void insert_function(const std::string&,
							 const std::vector<std::string>&,
							 const std::vector<inference::ShallowType>&,
							 inference::ShallowType,
							 inference::ShallowType,
							 Runtime);
	};

}

#endif // BUILT_IN_FUNCTIONS_HPP_DEFINED
