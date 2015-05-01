/*
 * ASTNode.cpp
 *
 *  Created on: 27 mars 2015
 *      Author: Floriane
 */

#include <algorithm> // for_each
#include <memory> // default_delete
#include <iterator> // next

#include "ASTNode.hpp"
#include "NodeLocation.hpp"
#include "../visitor/ASTVisitor.hpp"

using namespace ast;
using namespace std;
using namespace visitor;

ASTNode::ASTNode() : father(nullptr)
{

}

ASTNode::ASTNode(const NodeLocation& node_loc) : father(nullptr), loc(node_loc)
{

}

ASTNode::ASTNode(int first_line, int last_line, int first_column, int last_column)
	: father(nullptr), loc(first_line, last_line, first_column, last_column)
{

}

ASTNode::ASTNode(const string& name) : father(nullptr), node_name_(name) {}

ASTNode::ASTNode(const string& name, const NodeLocation& node_loc)
	: father(nullptr), loc(node_loc), node_name_(name)
{

}

ASTNode::ASTNode(const string& name, int first_line, int last_line, int first_column, int last_column)
	: father(nullptr), loc(first_line, last_line, first_column, last_column), node_name_(name)
{

}

ASTNode::ASTNode(const ASTNode& copy) : loc(copy.loc), node_name_(copy.node_name_)
{
	for(ASTNode* node : copy.get_children()) 
	{
		ASTNode* new_child = new ASTNode(*node);
		add_child(new_child);
	}
}

ASTNode& ASTNode::operator=(const ASTNode& copy)
{
	// free the memory previously allocated to the current node
	clear_children();

	// copy the properties
	node_name_ = copy.node_name_;
	loc = copy.loc;
	
	// and the child
	for(ASTNode* node : copy.get_children()) 
	{
		ASTNode* new_child = new ASTNode(*node);
		add_child(new_child);
	}

	return *this;
}

ASTNode::~ASTNode()
{
	free_node();
}

const ASTNode& ASTNode::get_father() const
{
	return *father;
}

ASTNode&  ASTNode::get_father()
{
	return *father;
}

const vector<ASTNode*>& ASTNode::get_children() const
{
	return children;
}

vector<ASTNode*>& ASTNode::get_children()
{
	return children;
}

void ASTNode::add_child(ASTNode* child)
{
	if(!child)
		return;

	children.push_back(child);
	child->father = this;
}

void ASTNode::add_child_first(ASTNode* child)
{
	add_child_at(0, child);
}

void ASTNode::add_child_at(size_t pos, ASTNode* child)
{
	if(!child)
		return;

	children.insert(next(children.begin(), pos), child);
	child->father = this;
}

void ASTNode::add_children(const std::vector<ASTNode*>& new_children)
{
	for(ASTNode* child : new_children)
		add_child(child);
}



ASTNode* ASTNode::delete_child(size_t index)
{
	if(index >= children.size())
		return nullptr; 
	
	ASTNode* child_to_remove = children[index];
	children.erase(next(children.begin(), index));
	return child_to_remove;
}

std::vector<ASTNode*> ASTNode::delete_children()
{
	std::vector<ASTNode*> children_to_return(children);
	children.clear();
	return children_to_return;
}

bool ASTNode::has_child() const
{
	return children.size() > 0;
}

bool ASTNode::has_father() const
{
	return father != nullptr;
}

string& ASTNode::node_name()
{
	return node_name_;
}

const string& ASTNode::node_name() const
{
	return node_name_;
}

void ASTNode::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}


void ASTNode::free_node()
{
	for_each(children.begin(), children.end(), default_delete<ASTNode>());
}

void ASTNode::clear_children()
{
	free_node();
	children.clear();
}

NodeLocation ASTNode::get_location()
{
	return loc;
}