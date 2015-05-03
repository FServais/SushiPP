#ifndef SPP_COMPILER_HPP_DEFINED
#define SPP_COMPILER_HPP_DEFINED

#include "settings/CompilerSettings.hpp"
#include "ast/AbstractSyntaxTree.hpp"
#include "ast/nodes/ASTNode.hpp"
#include "symb/SymbolTable.hpp"
#include "symb/SymbolInfo.hpp"
#include "errors/ErrorHandler.hpp"

namespace compiler
{
	class SppCompiler
	{
	public:
		/**
		 *
		 */
		SppCompiler(int argc, char** argv);

		/** Launch the compiler */
		void execute();

		/**
		 * @brief Initialize a new syntax tree with the given node as root
		 * @param ASTNode* root A pointer to the root node of the syntax tree to create
		 * @note Any node previously given to this function is freed
		 */
		void set_syntax_tree_root(ast::ASTNode*);

		/**
		 * @brief Get the error handler.
		 * @return Error handler.
		 */
		errors::ErrorHandler& get_error_handler();


	private:
		settings::CompilerSettings config;
		ast::AbstractSyntaxTree syntax_tree;
		symb::SymbolTable<symb::FunctionInfo> function_table;
		symb::SymbolTable<symb::VariableInfo> variable_table;
		errors::ErrorHandler error_handler;

		/**
		 * @brief Initialize the compiler for execution
		 */
		void init();

		/**
		 * @brief Terminate the execution of the compiler by cleaning memory or freeing ressources
		 * @note This is not done by the destructor so that we can possibly call execute a second time withouth
		 * creating memory or ressource leak
		 * @note Acts on memory or ressources allocated in 'init()' only
		 */
		void terminate();

		/**
		 * @brief Run the parser to build the abstract syntax tree
		 * @note The resulting parse tree can be found in the public member syntax_tree
		 * @throw ParsingException If the parsing fails
		 */
		void parse();

		/**
		 * @brief Run the type inference on the abstract syntax tree
		 * @note The resulting type table can be found in the private member
		 */
		void inference();

		/**
		 * @brief Print the abstract syntax tree according to the configuration (file or stdin)
		 * @brief The syntax_tree variable should contain a valid syntax tree (with at least a root node)
		 */
		void print_ast();

		/**
		 * @brief Perform the scope checking and fills the symbol tables (functions and variables)
		 */
		void scope_checking();

		/**
		* @brief Generate the code corresponding the program.
		*/
		void export_llvm();
	};
}

#endif // SPP_COMPILER_HPP_DEFINED
