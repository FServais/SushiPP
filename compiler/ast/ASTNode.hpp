/*
 * ASTNode.h
 *
 *  Created on: 27 mars 2015
 *      Author: Floriane
 */

#ifndef NODE_HPP_DEFINED
#define NODE_HPP_DEFINED
#include <vector>


namespace ast
{
	class ASTNode {
	public:
		// initialize an empty node
		ASTNode();
		ASTNode(Location);
		// copy constructor : deep copy 
		ASTNode(ASTNode& tree);
		// assignment operator 
		ASTNode& operator=(const ASTNode&);
		// destructor
		virtual ~ASTNode();

		// return the a reference to the father node
		const ASTNode& get_father() const;
		ASTNode& get_father();

		// return a vector of pointer to the children of then nodes
		std::vector<ASTNode*>& get_children();
		const std::vector<ASTNode*>& get_children() const;

		// add a child to the node
		void add_child(ASTNode&);

		// delete a child at the given index 
		void delete_child(size_t);

		// check wheter the node has at least a child
		bool has_child() const;

		// check whether the node has a parent
		bool has_father() const;

		// function for accepting a visitor
		virtual accept(ASTVisitor& v) = 0;

	protected:
		ASTNode* father;
		std::vector<ASTNode*> children;
		Location loc;
	};
}

#endif /* NODE_HPP_DEFINED */
