/*
 * ASTNode.cpp
 *
 *  Created on: 27 mars 2015
 *      Author: Floriane
 */


#include <algorithm> // for_each
#include <memory> // default_delete
#include <iterator> //
#include <iostream>

#include "ASTNode.hpp"
#include "NodeLocation.hpp"
#include "../visitor/ASTVisitor.hpp"

using namespace ast;
using namespace std;

ASTNode::ASTNode() : father(nullptr), depth_(0)
{

}

ASTNode::ASTNode(const NodeLocation& node_loc) : father(nullptr), loc(node_loc), depth_(0)
{

}

ASTNode::ASTNode(int first_line, int last_line, int first_column, int last_column)
	: father(nullptr), loc(first_line, last_line, first_column, last_column), depth_(0)
{

}

ASTNode::ASTNode(const string& name) : father(nullptr), node_name_(name), depth_(0) {}

ASTNode::ASTNode(const string& name, const NodeLocation& node_loc)
	: father(nullptr), loc(node_loc), node_name_(name), depth_(0)
{

}

ASTNode::ASTNode(const string& name, int first_line, int last_line, int first_column, int last_column)
	: father(nullptr), loc(first_line, last_line, first_column, last_column), node_name_(name), depth_(0)
{

}

ASTNode::ASTNode(const ASTNode& copy) : loc(copy.loc),node_name_(copy.node_name_), depth_(copy.depth())
{
	for(auto it = copy.get_children().begin(); it != copy.get_children().end(); it++) 
	{
      	ASTNode* ch = new ASTNode(**it);
		add_child(ch);
	}
}

ASTNode& ASTNode::operator=(const ASTNode& copy)
{
	for_each(children.begin(), children.end(), default_delete<ASTNode>());
	children.clear();
	node_name_ = copy.node_name_;
	loc = copy.loc;
	
	for(auto it = copy.get_children().begin(); it != copy.get_children().end(); it++) {
		ASTNode* ch = new ASTNode(**it);
		add_child(ch);
	}
    return *this;
}

ASTNode::~ASTNode()
{
	for_each(children.begin(), children.end(), default_delete<ASTNode>());
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
	if(child == nullptr)
		return;
	children.push_back(child);
	child->father = this;

	child->incr_depth();
}

void ASTNode::delete_child(size_t index)
{
	ASTNode* ch = children.at(index);
	ch->decr_depth();
	children.erase(next(children.begin(), index));
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

void ASTNode::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

int ASTNode::depth()
{
	return depth_;
}

const int ASTNode::depth() const
{
	return depth_;
}

void ASTNode::incr_depth()
{
	++depth_;
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->incr_depth();
}

void ASTNode::decr_depth()
{
	--depth_;
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->decr_depth();
}

