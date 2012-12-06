/**
 * Skiplist
 * 
 * Geiﬂ, Kowar, Veit 
 */

#include "Node.h"
#include "math.h"

#ifndef SKIPLIST_H
#define SKIPLIST_H
template <typename my_type>
class Skiplist {

public:
	
	Skiplist(int size);
	~Skiplist();

	bool insert(my_type insert_val);
	Node<my_type>* search(my_type search_val);
	void print();
	void print_vis();

	Node<my_type>* root;

public:

	int max_level;
	double p;

	std::vector<Node<my_type>*> get_next_vector(int new_level, my_type insert_val);
	int calc_random_level();
};

#endif