#include "Node.h"

Node::Node( double val, int new_level )
{
	node_level = new_level;
	content = val;
	for (int i = 0; i < new_level; ++i)
		ptr.push_back(NULL);
}

Node::~Node()
{
	for (int i = 0; i < ptr.size(); ++i)
		delete ptr[i];
}

Node* Node::get_next( int level )
{
	if (level < node_level) 
		return ptr[level];

	return NULL;
}

void Node::set_next( int level, Node* next_pointer )
{
	if (level < node_level) 
		ptr[level] = next_pointer;
}
