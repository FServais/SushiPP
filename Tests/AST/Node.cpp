/*
 * Node.cpp
 *
 *  Created on: 27 mars 2015
 *      Author: Floriane
 */

#include "Node.h"

Node::Node() {


}

Node::Node(Node& tree) {


}


Node& Node::getFather(){
	return father;
}

std::vector<Node*>& Node::getChildren(){
	return children;
}

void Node::addChild(Node& child){
	children.push_back(&child);
}

void Node::deleteChild(Node& child){
	children.erase(find(children.begin(), children.end(), child));
}

bool Node::hasChild(){
	return !children.empty();
}

bool Node::hasFather(){
	if(father == nullptr){
		return false;
	}
	return true;
}

Node::~Node() {
}

