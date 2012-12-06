/**
 * Content Node Class
 *
 * Geiﬂ, Kowar, Veit 
 */

#include <vector>

#ifndef NODE_H
#define NODE_H

class Node {

public:
	Node(double d, int new_level);
	~Node();

	double get_content() { return content; }
	Node* get_next( int level );
	void set_next( int level, Node* next_pointer );
	int get_level() { return node_level; }

private:
	double content;
	int node_level;
	std::vector<Node*> ptr;
};

#endif