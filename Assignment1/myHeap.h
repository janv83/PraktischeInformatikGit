#ifndef MYHEAP_H
#define MYHEAP_H

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>

template <typename myType>
class myHeap
{
	public:
		myHeap(unsigned n);
		~myHeap();
		bool empty() const;
		myType top() const;
		void push(myType d);
		void pop();
		void print() const;
		unsigned getElements();
		myType* sort();
	
	private:
		unsigned elements;
		unsigned size;
		myType *data;
	
		unsigned left_index(unsigned idx) const;
		unsigned right_index(unsigned idx) const;
		unsigned parent_index(unsigned idx) const;
		unsigned children(unsigned idx) const;
		
};

#endif