#ifndef TYPE_GEN_HPP_DEFINED
#define TYPE_GEN_HPP_DEFINED

#include "../exceptions/Exceptions.hpp"
#include <vector>
#include "Types.hpp"
#include <memory>

namespace typegen
{
	

	class Type 
	{
	public:
		virtual inference::ShallowType get_type() = 0;
		virtual std::string to_str() = 0;
	};


	class Int : public Type
	{
	public:
		virtual inference::ShallowType get_type(){return inference::INT;};
		virtual std::string to_str();
	};

	class Float : public Type
	{
	public:
		virtual inference::ShallowType get_type(){return inference::FLOAT;};
		virtual std::string to_str();
	};

	class Char : public Type
	{
	public:
		virtual inference::ShallowType get_type(){return inference::CHAR;};
		virtual std::string to_str();
	};

	class Bool : public Type
	{
	public:
		virtual inference::ShallowType get_type(){return inference::BOOL;};
		virtual std::string to_str();
	};

	class String : public Type
	{
	public:
		virtual inference::ShallowType get_type(){return inference::STRING;};
		virtual std::string to_str();
	};

	class Void : public Type
	{
	public:
		virtual inference::ShallowType get_type(){return inference::VOID;};
		virtual std::string to_str();
	};

	class List : public Type
	{
	public:
		List(std::shared_ptr<Type>);
		virtual inference::ShallowType get_type(){return inference::LIST;};
		std::shared_ptr<Type> get_param_type(){return param_type;};
		virtual std::string to_str();

	private:
		std::shared_ptr<Type> param_type;
	};

	class Array : public Type
	{
	public:
		Array(std::shared_ptr<Type>);
		virtual inference::ShallowType get_type(){return inference::ARRAY;};
		std::shared_ptr<Type> get_param_type(){return param_type;};
		virtual std::string to_str();


	private:
		std::shared_ptr<Type> param_type;
	};

	class Function : public Type
	{
	public:
		Function(std::shared_ptr<Type> ret_type, std::vector<std::shared_ptr<Type>> arg_type);
		virtual inference::ShallowType get_type(){return inference::FUNCTION;};
		int nb_param(){return args_types.size();};
		std::shared_ptr<Type> get_ret_type(){return return_type;};
		std::shared_ptr<Type> get_arg(size_t );
		virtual std::string to_str();

	private:
		std::shared_ptr<Type> return_type;
		std::vector<std::shared_ptr<Type>> args_types;

	};
}



#endif // TYPE_GEN_HPP_DEFINED