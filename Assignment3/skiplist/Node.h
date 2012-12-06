/**
 * Content Node Class
 *
 * Geiﬂ, Kowar, Veit 
 */

#include <vector>

#ifndef NODE_H
#define NODE_H

template <typename my_type>
class Node {

public:
	Node(my_type d, int new_level);

	my_type get_content() { return content; }
	Node<my_type>* get_next( int level );
	void set_next( int level, Node<my_type>* next_pointer );
	int get_level() { return node_level; }

private:
	my_type content;
	int node_level;
	std::vector<Node<my_type>*> ptr;
};

#endif

