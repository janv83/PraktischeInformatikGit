#include "myHeap.h"
#include "myHeap.cpp"
#include "Tree.cpp"
#include "AvlTree.cpp"
#include <stdlib.h>

void insertRandom(int n, Tree& tree, int numberMaximum)
{
	for(int i = 0; i < n; i++)
	{
		tree.insert((double)(rand()%numberMaximum));
	}
}

void insertRandom(int n, AvlTree& tree, int numberMaximum)
{
	for(int i = 0; i < n; i++)
	{
		tree.insert((double)(rand()%numberMaximum));
	}
}


int main()
{
	myHeap<int> testHeap1(15);
	testHeap1.push(2);
	testHeap1.push(1);
	testHeap1.push(8);
	testHeap1.push(5);
	testHeap1.push(3);
	testHeap1.push(4);
	testHeap1.print();
	
	myHeap<ComparableClass> testHeap2(15);
	ComparableClass cc1(13);
	ComparableClass cc2(11);
	ComparableClass cc3(18);
	ComparableClass cc4(15);
	testHeap2.push(cc1);
	testHeap2.push(cc2);
	testHeap2.push(cc3);
	testHeap2.push(cc4);
	

	
	testHeap2.print();
	
	
	//Aufgabe 1.2 Heapsort
	std::cout << "Aufgabe 1.2." << std::endl;
	
	int* sortedArray = testHeap1.sort();
	
	for(int i = 0; i < testHeap1.getElements(); i++)
	{
		std::cout << sortedArray[i] << std::endl;
	}
	
	
	//Aufgabe 1.3 Binary Tree
	
	std::cout << "Aufgabe 1.3." << std::endl;
	
	//Tree* myTree = new Tree(); 
	Tree myTree;
	
	insertRandom(10000, myTree, 1000000000);
	
	unsigned height = myTree.treeHeight();
	
	std::cout << height << std::endl;
	
	insertRandom(10000, myTree, 1000000000);   // now 20k in tree 
	height = myTree.treeHeight();
	
	std::cout << height << std::endl;
	
	
	insertRandom(10000, myTree, 1000000000);   // now 30k in tree
	height = myTree.treeHeight();
	
	std::cout << height << std::endl;
	
	
	//Aufgabe 1.3. AVL Tree
	
	std::cout << "Aufgabe 1.3. AVLTree" << std::endl;
	
	AvlTree myAvlTree;
	insertRandom(10000, myAvlTree, 1000000000);
	
	unsigned heightAvl = myAvlTree.treeHeight();
	
	std::cout << heightAvl << std::endl;
	
	insertRandom(10000, myAvlTree, 1000000000);   // now 20k in tree 
	heightAvl = myAvlTree.treeHeight();
	
	std::cout << heightAvl << std::endl;
	
	
	insertRandom(10000, myAvlTree, 1000000000);   // now 30k in tree
	heightAvl = myAvlTree.treeHeight();
	
	std::cout << heightAvl << std::endl;

}