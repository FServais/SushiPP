#ifndef SPP_COMPILER_HPP_DEFINED
#define SPP_COMPILER_HPP_DEFINED

#include "settings/CompilerSettings.hpp"
#include "settings/BuiltInFunctions.hpp"
#include "ast/AbstractSyntaxTree.hpp"
#include "ast/nodes/ASTNode.hpp"
#include "symb/SymbolTable.hpp"
#include "symb/SymbolInfo.hpp"
#include "errors/ErrorHandler.hpp"
#include "inference/TypeSymbolTable.hpp"
#include "inference/TypeGen.hpp"

namespace compiler
{
	/**
	 * @class SppCompiler
	 * @brief Main class of the compiler : coordinates the actions of the different compilation phases. Contains the data 
	 * accumulated during the various phases
	 */
	class SppCompiler
	{
	public:
		/**
		 * @brief Construct a spp compiler object with the user inputs
		 * @param int argc Does it need to be explained? 
		 * @param char** argv Does it need to be explained? 
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
		/**
		 * config : compiler settings of the current execution
		 * built_in : datastructure containing all the built in functions descriptions
		 * syntax_tree : as soon as it is build (afterparsing), contains the abstract syntax tree
		 * functions_table : symbol table containing the functions info
		 * variable_table : symbol table containing the functions info
		 * error_handler : object for emitting compilation error
		 * type_table : table containing the information about the types of the language
		 * generated_llvm : the generated llvm
		 */
		settings::CompilerSettings config;
		settings::BuiltInFunctions built_in;
		ast::AbstractSyntaxTree syntax_tree;
		symb::SymbolTable<symb::FunctionInfo> function_table;
		symb::SymbolTable<symb::VariableInfo> variable_table;
		errors::ErrorHandler error_handler;
		inference::TypeSymbolTable type_table;
		std::string generated_llvm;
		std::string optimization_flags;// contains the 'opt' optimization passes flags 

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

		/**
		 * @brief Generate an executable
		 */
		void executable_generation();

		/**
		 * @brief Execute the given command with `system`
		 * @retval int The return of `system` 
		 */
		int execute_cmd(const std::string&);

		/**
		 * @brief Write the llvm generated in the code gen visitor into the given file
		 * @param const std::string& filepath The file path
		 * @retval bool true on success, false on error
		 */
		bool write_llvm_to_file(const std::string&);
	};
}

#endif // SPP_COMPILER_HPP_DEFINED
