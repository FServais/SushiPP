#ifndef SYMBOL_INFO_HPP_DEFINED
#define SYMBOL_INFO_HPP_DEFINED

#include <string>
#include <vector>

namespace symb
{
	enum Type { INT, FLOAT, STRING, BOOL, ARRAY, LIST, TUPLE, UNDEFINED };
	
	class Parameter
	{
	public:
		/**
		 * @brief Construct a Parameter having the given name
		 * @param const std::string& name The parameter name
		 * @note The type is left undefined
		 */
		Parameter(const std::string&);

		/**
		 * @brief Construct a Parameter having the given name and type
		 * @param const std::string& name The parameter name
		 * @param Type The type of the parameter
		 */
		Parameter(const std::string&, Type);

		// getters 
		const std::string& name() const { return name_; };
		Type type() const { return type_; };

		// setters
		void set_type(Type type) { type_ = type; };

	private:
		std::string name_;
		Type type_;
	};

	class FunctionInfo 
	{
	public:
		/**
		 * @brief Construct an object containing the information of a NAMED function
		 * @param const std::string& name The function name
		 * @param std::vector<Parameter>& params The functions parameters info
		 * @param Type return_type The return type of the function
		 */
		FunctionInfo(const std::string&, std::vector<Parameter>&, Type);

		/**
		 * @brief Construct an object containing the information of an ANONYMOUS (soy) function
		 * @param std::vector<Parameter>& params The functions parameters info
		 * @param Type return_type The return type of the function
		 * @note A random name is generated. It can be obtained after construction with the 'name()' function
		 */
		FunctionInfo(std::vector<Parameter>&, Type);

		// getters
		const std::string& name() const { return name_; };
		const std::vector<Parameter>& params() const { return params_; };
		const Parameter& param(size_t i) const { return params_[i]; }; // get the ith parameter
		size_t nb_params() const { return params_.size(); };
		bool is_anonymous() const { return anonymous_; };
		Type return_type() const { return return_type_; };	

		// setters
		void set_return_type(Type type) { return_type_ = type; };
		void set_param_type(size_t i, Type type) { params_[i].set_type(type); };
		
	private:
		std::string name_;
		std::vector<Parameter>& params_;
		Type return_type_;
		bool anonymous_;
	};

	class VariableInfo
	{
	public:
		/**
		 * @brief Construct a VariableInfo having for a vriable having the given name
		 * @param const std::string& name The variable name
		 * @note The type is left undefined
		 */
		VariableInfo(const std::string&);

		/**
		 * @brief Construct a VariableInfo having the given name and type
		 * @param const std::string& name The variable name
		 * @param Type The type of the variable
		 */
		VariableInfo(const std::string&, Type);

		// getters 
		const std::string& name() const { return name_; };
		Type type() const { return type_; };

		// setters
		void set_type(Type type) { type_ = type; };

	private:
		std::string name_;
		Type type_;
	};
}


#endif // FUNCTION_INFO_HPP_DEFINED