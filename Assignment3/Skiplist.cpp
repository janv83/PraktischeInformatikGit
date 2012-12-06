/**
 * Skiplist
 *
 * Geiﬂ, Kowar, Veit 
 */

#include "skiplist.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Skiplist.h"

int Skiplist::calc_random_level()
{
	int lvl = 1;

	while (rand() % 100 < p && lvl < max_level) 
	{
		++lvl;
	}

	return lvl;
}

bool Skiplist::insert( double val )
{
	int new_level = calc_random_level();

	std::vector<Node*> next_vec = get_next_vector(new_level, val);

	if(next_vec.empty())
	{
		return false;
	}

	Node* new_node = new Node(val, new_level);

	for(int i = 0; i < next_vec.size(); ++i)
	{
		Node* tmp = next_vec[i]->get_next(i) != NULL ? next_vec[i]->get_next(i) : NULL;
		
		next_vec[i]->set_next(i, new_node);
		new_node->set_next(i, tmp);
	}

	return true;
}

std::vector<Node*> Skiplist::get_next_vector(int new_level, double insert_val)
{
	Node* node = root;
	std::vector<Node*> next_vec;

	for (int i = new_level; i > 0; --i)
	{
		while (node->get_next(i) != NULL && node->get_next(i)->get_content() < insert_val)
		{
			node = node->get_next(i);
		}
		
		if (node->get_next(i) == NULL)
		{
			next_vec.push_back(node);
		}

		if (node->get_content() == insert_val)
		{
			next_vec.clear();
			return next_vec;
		}
	}	

	return next_vec;
}

Node* Skiplist::search(double search_val)
{

	if (root != NULL && root->get_next(0) != NULL)
	{
		Node* node = (Node*)root;
	
		for (int i = max_level; i > 0; --i)
		{
			while (node->get_next(i) != NULL && ((Node*)node->get_next(i))->get_content() < search_val)
			{
				node = node->get_next(i);
			}
		
			if (node->get_content() == search_val)
			{
				return node;
			}
		}	
	}

	return NULL;
}

void Skiplist::print()
{
	Node* print_node = root;
	int cnt = 0;

	while (print_node->get_next(0) != NULL)
	{
		print_node = print_node->get_next(0);
		std::cout << "Node " << cnt++ << " Value: " << print_node->get_content() << " Height: " << print_node->get_level() << std::endl;
	}
}

Skiplist::Skiplist( int size )
{
	srand(time(NULL));
	p = 50;
	max_level = (int)log((double)size);
	root = new Node(-1, max_level);
}
