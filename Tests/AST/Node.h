/*
 * Node.h
 *
 *  Created on: 27 mars 2015
 *      Author: Floriane
 */

#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include <algorithm>

class Node {
public:
	Node();
	Node(Node& tree);
	virtual ~Node();
	Node& getFather();
	std::vector<Node*>& getChildren();
	void addChild(Node&);
	void deleteChild(Node&);
	bool hasChild();
	bool hasFather();

private:
	Node* father;
	std::vector<Node*> children;


};

#endif /* NODE_H_ */
