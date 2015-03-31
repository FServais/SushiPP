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
		// copy constructor : deep copy
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

		// add a child to the node
		void add_child(ASTNode*);

		// delete a child at the given index
		void delete_child(size_t);

		// check wheter the node has at least a child
		bool has_child() const;

		// check whether the node has a parent
		bool has_father() const;

		// print the node name
		std::string& node_name();
		const std::string& node_name() const;
		
		void print(int);

		// function for accepting a visitor
//virtual accept(ASTVisitor& v) = 0;

	protected:
		ASTNode* father; /* Points to the current node father, nullptr if there is none */
		std::vector<ASTNode*> children; /* Children of the node, empty for a leaf */
		NodeLocation loc; /* Node location */
		std::string node_name_; /* Node name */
	};
}

#endif /* NODE_HPP_DEFINED */
