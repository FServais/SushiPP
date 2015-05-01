#ifndef SYMBOL_INFO_HPP_DEFINED
#define SYMBOL_INFO_HPP_DEFINED

#include <string>
#include <vector>
#include "../ast/nodes/NodeLocation.hpp"
namespace symb
{


	/**
	 * @class VariableInfo
	 */
	class VariableInfo
	{
	public:
		/**
		 * @brief Construct a VariableInfo having for a vriable having the given name
		 * @param const std::string& name The variable name
		 * @note The type is left undefined
		 */
		VariableInfo(const std::string&, ast::NodeLocation);

		// getters 
		const std::string& name() const { return name_; };
		void is_used(){used = true;};

		bool get_used(){return used;};
		size_t get_line(){return location.first_line();};
		size_t get_column(){return location.last_line();};


		// setters

	private:
		std::string name_;
		bool used;
		ast::NodeLocation location;
	};


	/**
	 * @class FunctionInfo
	 */
	class FunctionInfo 
	{
	public:
		/**
		 * @brief Construct an object containing the information of a NAMED function
		 * @param const std::string& name The function name
		 * @param std::vector<VariableInfo>& params The functions VariableInfos info
		 * @param Type return_type The return type of the function
		 */
		FunctionInfo(const std::string&, std::vector<VariableInfo>&, ast::NodeLocation);

		/**
		 * @brief Construct an object containing the information of an ANONYMOUS (soy) function
		 * @param std::vector<VariableInfo>& params The functions VariableInfos info
		 * @param Type return_type The return type of the function
		 * @note A random name is generated. It can be obtained after construction with the 'name()' function
		 */
		FunctionInfo(std::vector<VariableInfo>&, ast::NodeLocation);

		// getters
		const std::string& name() const { return name_; };
		const std::vector<VariableInfo>& params() const { return params_; };
		const VariableInfo& param(size_t i) const { return params_[i]; }; // get the ith VariableInfo
		size_t nb_params() const { return params_.size(); };
		bool is_anonymous() const { return anonymous_; };
		void is_used(){used = true;};
		bool get_used(){return used;};
		size_t get_line(){return location.first_line();};
		size_t get_column(){return location.last_line();};


		// setters

		
	private:
		std::string name_;
		std::vector<VariableInfo>& params_;
		bool anonymous_;
		bool used;
		ast::NodeLocation location;
	};

	
}

#endif // FUNCTION_INFO_HPP_DEFINED