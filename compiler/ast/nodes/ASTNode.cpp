/*
 * ASTNode.cpp
 *
 *  Created on: 27 mars 2015
 *      Author: Floriane
 */

#include "ASTNode.h"

#include <algorithm> // for_each
#include <memory> // default_delete
#include <iterator> // 

using namespace ast::nodes;
using namespace std;

ASTNode::ASTNode() : parent(nullptr)
{
	std::vector<ASTNode*> children();
}

ASTNode(const NodeLocation& node_loc) : father(nullptr), loc(node_loc)
{

}

ASTNode(int first_line, int last_line, int first_column, int last_column) 
	: father(nullptr), loc(first_line, last_line, first_column, last_column)
{

}

ASTNode(const std::string& name) : parent(nullptr), node_name(name) {}

ASTNode(const std::string& name, const NodeLocation& node_loc) 
	: parent(nullptr), loc(node_loc), node_name(name)
{

}

ASTNode(const std::string& name, int first_line, int last_line, int first_column, int last_column)
	: father(nullptr), loc(first_line, last_line, first_column, last_column), node_name(name)
{
	
}

ASTNode::ASTNode(const ASTNode& copy) 
{
	for(auto it = copy.getChildren().begin(); it != copy.getChildren().end(); it++) {
		if(*it != NULL){
			Node* ch = new Node(**it);
			addChild(*ch);
		}	
	}
}

ASTNode& ASTNode::operator=(const ASTNode&)
{
	children.clear();
	
	for(auto it = copy.getChildren().begin(); it !=  copy.getChildren().end(); it++) {
			Node* ch = new Node(**it);
			addChild(*ch);
	}

}

ASTNode::~ASTNode()
{
	delete father;
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

void ASTNode::add_child(const ASTNode& child)
{
	children.push_back(&child);
}

void ASTNode::delete_child(size_t index)
{
	children.erase(std::advance(children.begin(), index));
}

bool ASTNode::has_child() const
{
	return children.size() > 0;
}

bool ASTNode::has_father() const
{
	return father != nullptr;
}

