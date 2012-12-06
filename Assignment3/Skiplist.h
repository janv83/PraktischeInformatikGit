/**
 * Skiplist
 * 
 * Geiﬂ, Kowar, Veit 
 */

#include "Node.h"
#include "math.h"

#ifndef SKIPLIST_H
#define SKIPLIST_H

class Skiplist {

public:
	
	Skiplist(int size);
	~Skiplist() { delete root; }

	bool insert(double val);
	Node* search(double search_val);
	void print();

	Node* root;

public:

	int max_level;
	double p;

	std::vector<Node*> get_next_vector(int new_level, double insert_val);
	int calc_random_level();
};

#endif