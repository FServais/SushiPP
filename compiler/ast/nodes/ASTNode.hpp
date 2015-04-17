/*
 * ASTNode.hpp
 *
 * Author: Floriane Magera, Fabrice Servais, Romain Mormont
 */

#ifndef NODE_HPP_DEFINED
#define NODE_HPP_DEFINED

#include <vector>
#include <string>

#include "NodeLocation.hpp"

class ASTVisitor;

namespace ast
{
	class ASTNode {
	public:
		/** Empty node name constructors */
		// initialize an empty node
		ASTNode();

		// initialize a node with the given location info
		ASTNode(const NodeLocation&);

		// params : first_line, last_line, first_column, last_column
		// throws a domain_error exception if the location data are invalid
		ASTNode(int, int, int, int);

		/** Node with name constructors */
		// initialize a node with the given name
		ASTNode(const std::string&);

		// initialize a node with the given location info
		ASTNode(const std::string&, const NodeLocation&);

		// params : first_line, last_line, first_column, last_column
		// throws a domain_error exception if the location data are invalid
		ASTNode(const std::string&, int, int, int, int);

		/** Rule of the Big Three */
		/**
		 * @brief Copy constructor
		 * The new node is constructed as a standalone one : depth 0 and has therefore no parent (then considered as root). 
		 * To change these properties it has to be added as a child of another node.
		 */
		ASTNode(const ASTNode&);

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

		// check wheter the node has at least a child
		bool has_child() const;

		// check whether the node has a parent
		bool has_father() const;

		// print the node name
		std::string& node_name();
		const std::string& node_name() const;

		// function for accepting a visitor
		virtual void accept(ASTVisitor&);

	protected:
		// add a child(ren) to the node
		void add_child(ASTNode*);
		void add_children(const std::vector<ASTNode*>&);
		void add_child_first(ASTNode*); // add a child at the first position
		void add_child_at(size_t, ASTNode*); // insert the child at the given position
		// delete a child at the given index
		// the ownership of the memory allocated for the child node and its descendents
		// is tranferred to the calling context
		ASTNode* delete_child(size_t);
		std::vector<ASTNode*> delete_children();

		ASTNode* father; /* Points to the current node father, nullptr if there is none */
		std::vector<ASTNode*> children; /* Children of the node, empty for a leaf */
		NodeLocation loc; /* Node location */
		std::string node_name_; /* Node name */
		
		// free recursively  the memory associated to the current node (memory of the children is freed too)
		void free_node();

		// free the memory allocated to the children and remove them from the children vector
		void clear_children();
	};
}


#endif /* NODE_HPP_DEFINED */
