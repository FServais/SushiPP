#ifndef ERROR_HANDLER_HPP_DEFINED
#define ERROR_HANDLER_HPP_DEFINED

#include <vector>
#include <memory>

#include "ErrorItem.hpp"
#include "LexicalError.hpp"
#include "../settings/CompilerSettings.hpp"

namespace errors
{
	class ErrorHandler
	{
	private:
		std::vector<std::unique_ptr<ErrorItem>> errors;
		settings::CompilerSettings settings;

	public:

		ErrorHandler(settings::CompilerSettings);

		/**
		 * Get the nth error in the list.
		 * @param  int Number of the error.
		 * @return     Error at place n.
		 */
		const ErrorItem& get_nth_error(int) const;

		/**
		 * Print the errors contained by the error handler.
		 */
		void print_errors() const;

		/**
		 * Add a lexical error.
		 * @param   const std::string&  Line where the error occur.
		 * @param   int					Line number.
		 * @param   int					Column number.
		 * @param   const std::string&  File name.
		 * @param   const std::string&  Description of the error.
		 */
		void add_lex_error(const std::string&, int, int, const std::string&, const std::string&);
		
		void add_lex_error(LexicalError&);
		
		/*
		void add_synt_error(const std::string&, int, int, const std::string&, const std::string&);
		void add_synt_error(ErrorItem);

		void add_sem_error(const std::string&, int, int, const std::string&, const std::string&);
		void add_sem_error(ErrorItem);

		void add_io_error(const std::string&, int, int, const std::string&, const std::string&);
		void add_io_error(ErrorItem);

		void add_mem_error(const std::string&, int, int, const std::string&, const std::string&);
		void add_mem_error(ErrorItem);
		*/

	};
}


#endif // ERROR_HANDLER_HPP_DEFINED
