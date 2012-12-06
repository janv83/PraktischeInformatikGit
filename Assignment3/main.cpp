#include "Skiplist.h"
#include <iostream>


int main()
{
	std::cout << "Creating empty Skiplist..." << std::endl;
	Skiplist s1(100000);

	std::cout << "Print Skiplist" << std::endl;
	s1.print();

	std::cout << "Searching for value 33 | Result: " << s1.search(33) << std::endl;

	std::cout << "Inserting value 3 ..." << std::endl;
	s1.insert(3);

	std::cout << "Print Skiplist" << std::endl;
	s1.print();

	std::cout << "Searching for value 3 | Result: " << s1.search(33) << std::endl;
	std::cout << "Searching for value 33 | Result: " << s1.search(33) << std::endl;

	std::cout << "Inserting values (4, 33, 324, 23, 42, 1337) ..." << std::endl;

	s1.insert(4);
	s1.insert(33);
	s1.insert(324);
	s1.insert(23);
	s1.insert(42);
	s1.insert(1337);

	std::cout << "Searching for value 33 | Result: " << s1.search(33) << std::endl;
	std::cout << "Searching for value 6 | Result: " << s1.search(6) << std::endl;

	std::cout << "Print Skiplist" << std::endl;
	s1.print();

	return EXIT_SUCCESS;
}