#include "merge_lists.cpp"
#include <iostream>

using namespace std;

void printList(intlist lToPrint)
{
	int size = lToPrint.size();
	for( int i = 0; i < size; i++)
	{
		cout << lToPrint.front() << endl;
		lToPrint.pop_front();
	}
}


int main()
{
	intlist lTest1;
	lTest1.push_back(7);
	lTest1.push_back(5);
	lTest1.push_back(3);
	
	intlist lTest2;
	lTest2.push_back(8);
	lTest2.push_back(6);
	lTest2.push_back(4);
	printList(lTest1);
	printList(lTest2);
	intlist* alSortThis = new intlist[2];
	alSortThis[0] = lTest1;
	alSortThis[1] = lTest2;
	
	intlist lSortedList = merge_lists(alSortThis, 2);
	
	printList(lSortedList);
	
	delete [] alSortThis;
}
