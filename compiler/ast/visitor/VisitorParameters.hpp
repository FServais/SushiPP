#ifndef VISITOR_PARAMETER_HPP_DEFINED
#define VISITOR_PARAMETER_HPP_DEFINED

#include <stack>
#include <vector>
#include <iterator>
#include "../../exceptions/Exceptions.hpp"

namespace visitor
{
	template <class P>
	class VisitorParameters
	{
	public:
		VisitorParameters() : curr_nb_params(0) {}

		/**
		 * @brief function call : the added parameters are pushed onto the parameters stack so that they
		 * are available to the called context
		 */
		void call();
		/**
		 * @brief function return : the parameters of the current context are popped off the parameters
		 * stack and the parameters of the initial caller are made available again 
		 */
		void ret();

		/** 
		 * @brief get the nth parameter of the current context
		 * @param size_t n The number of the parameter to get (in [1, nb_params()])
		 * @retval A (const) reference to the parameter
		 * @throw NoSuchParameterException If the parameters does not exist
		 */
		P& get_param(size_t);
		const P& get_param(size_t) const;

		/**
		 * @brief Get the number of parameters available for the current context
		 */
		size_t nb_params() const;

		/**
		 * @brief Add a paramter to be made available for the next called context
		 * @param P& param The new parameter to do
		 */
		void add_param(P&);

		/**
		 * @brief Clear the parameters that were added in the current context
		 */
		void clear_params();

	private:
		/**
		 * parameters     -> stack of parameters
		 * nb_params      -> stack containing the numbers of parameters for each context, at the top 
		 *					 is the number of parameters given to the current context
		 * curr_nb_params -> The number of parameters added in the current context
		 */
		std::vector<P&> parameters;
		std::stack<size_t> number_params;
		size_t curr_nb_params;
	};

	template <class P>
	void VisitorParameters<P>::call()
	{
		number_params.push(curr_nb_params);
		curr_nb_params = 0;
	}

	template <class P>
	void VisitorParameters<P>::ret()
	{
		// delete possible parameters that were added in the 
		// current context but not registered on the number_params stack
		clear_params(); 

		// clean the parameters made available from the current context
		if(!number_params.empty())
		{
			parameters.erase(std::prev(parameters.end(), nb_params()), parameters.end());
			number_params.pop();
		}
	}

	template <class P>
	P& VisitorParameters<P>::get_param(size_t n)
	{
		if(n == 0 || nb_params() < n)
			throw except::NoSuchParameterException(n);

		size_t index = parameters.size() - curr_nb_params - nb_params() + n - 1;
		return parameters[index];
	}

	template <class P>
	const P& VisitorParameters<P>::get_param(size_t n) const
	{
		if(n == 0 || nb_params() < n)
			throw except::NoSuchParameterException(n);

		size_t index = parameters.size() - curr_nb_params - nb_params() + n - 1;
		return parameters[index];
	}

	template <class P>
	size_t VisitorParameters<P>::nb_params() const
	{
		if(number_params.empty()) 
			return 0;
		return number_params.top();
	}

	template <class P>
	void VisitorParameters<P>::add_param(P& param)
	{
		curr_nb_params++;
		parameters.push_back(param);
	}

	template <class P>
	void VisitorParameters<P>::clear_params()
	{
		parameters.erase(std::prev(parameters.end(), curr_nb_params), parameters.end());
		curr_nb_params = 0;
	}

}

#endif // VISITOR_PARAMETER_HPP_DEFINED