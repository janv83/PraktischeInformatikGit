#include "Node.h"
#include <iostream>

template <typename my_type>
Node<my_type>::Node( my_type val, int new_level )
{
	node_level = new_level - 1;
	content = val;
	for (int i = 0; i < new_level; ++i)
		ptr.push_back(NULL);
}

//returns the next node on level level
template <typename my_type>
Node<my_type>* Node<my_type>::get_next( int level )
{
	if (level <= node_level) 
		return ptr[level];

	return NULL;
}

//set the nextpointer on level level to next_pointer
template <typename my_type>
void Node<my_type>::set_next( int level, Node* next_pointer )
{
	if (level <= node_level) 
	{
		ptr[level] = next_pointer;
	}
}
