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

using namespace ast;
using namespace std;

ASTNode::ASTNode() : parent(nullptr)
{

}

ASTNode::ASTNode(const ASTNode& tree) {


}

ASTNode& ASTNode::operator=(const ASTNode&)
{

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

