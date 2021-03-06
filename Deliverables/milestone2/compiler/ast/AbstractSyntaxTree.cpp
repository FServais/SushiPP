#include "AbstractSyntaxTree.hpp"

#include <cstddef>

using namespace std;
using namespace ast;

AbstractSyntaxTree::AbstractSyntaxTree() : root_(nullptr)
{
 
}

AbstractSyntaxTree::AbstractSyntaxTree(ASTNode* node) : root_(node)
{

}

// accessors
bool AbstractSyntaxTree::empty() const
{
	return root_ == nullptr;
}

const ASTNode& AbstractSyntaxTree::root() const
{
	return *root_;
}

ASTNode& AbstractSyntaxTree::root()
{
	return *root_;
}

// modifiers
void AbstractSyntaxTree::set_root(ASTNode* node)
{
	if(!empty()) // clear the previously allocated memory if there was some
		clear();

	root_ = node;
}

void AbstractSyntaxTree::clear()
{
	delete root_;
}
