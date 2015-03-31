/*
 * ASTNode.cpp
 *
 *  Created on: 27 mars 2015
 *      Author: Floriane
 */

#include "ASTNode.hpp"

#include <algorithm> // for_each
#include <memory> // default_delete
#include <iterator> //
#include <iostream>

using namespace ast;
using namespace std;

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

ASTNode::ASTNode(const std::string& name) : father(nullptr), node_name_(name) {}

ASTNode::ASTNode(const std::string& name, const NodeLocation& node_loc)
	: father(nullptr), loc(node_loc), node_name_(name)
{

}

ASTNode::ASTNode(const std::string& name, int first_line, int last_line, int first_column, int last_column)
	: father(nullptr), loc(first_line, last_line, first_column, last_column), node_name_(name)
{

}

ASTNode::ASTNode(const ASTNode& copy) : loc(copy.loc),node_name_(copy.node_name_)
{
	for(auto it = copy.get_children().begin(); it != copy.get_children().end(); it++) {
		
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
	
	for(auto it = copy.get_children().begin(); it !=  copy.get_children().end(); it++) {
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

const std::vector<ASTNode*>& ASTNode::get_children() const
{
	return children;
}

std::vector<ASTNode*>& ASTNode::get_children()
{
	return children;
}

void ASTNode::add_child(ASTNode* child)
{
	if(child == nullptr)
		return;
	children.push_back(child);
	child->father = this;
}

void ASTNode::delete_child(size_t index)
{
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

std::string& ASTNode::node_name()
{

}

const std::string& ASTNode::node_name() const
{

}

void ASTNode::print(int depht){
	string s(depht*3, ' ');
	std::cout<<s<<"name : "<<node_name_<<std::endl;
	std::cout<<s<<"nb sons : "<<children.size()<<std::endl;
	std::cout<<s<<"root's father :"<<father<<std::endl;
	for( auto it = children.begin(); it != children.end(); it++){
		(*it)->print(depht+1);
	}
}
