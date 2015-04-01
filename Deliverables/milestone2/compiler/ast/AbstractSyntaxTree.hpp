#ifndef ABSTRACT_SYNTAX_TREE_HPP_DEFINED
#define ABSTRACT_SYNTAX_TREE_HPP_DEFINED

#include "nodes/ASTNode.hpp"

namespace ast
{
	// takes ownership of the root node pointer and of the associated memory management
	class AbstractSyntaxTree
	{
	public:
		// constructors
		AbstractSyntaxTree();
		AbstractSyntaxTree(ASTNode* node);

		// accessors
		bool empty() const;
		const ASTNode& root() const;
		ASTNode& root();

		// modifiers
		// clear the possible previous tree
		void set_root(ASTNode* node);
		void clear();

	private:
		ASTNode* root_;
	};
}

#endif // ABSTRACT_SYNTAX_TREE_HPP_DEFINED
