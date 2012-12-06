/**
 * Content Node Class
 *
 * Geiﬂ, Kowar, Veit 
 */

#include <vector>
#include "Node.h"

#ifndef CONTENTNODE_H
#define CONTENTNODE_H

class Content_Node : public Node {

public:
	Content_Node(double d, int new_level) : Node(new_level), content(d) {}
	//~Content_Node();

protected:
	
};

//Content_Node::~Content_Node()
//{
//	for (int i = 0; i < ptr.size(); ++i)
//		delete ptr[i];
//}

#endif