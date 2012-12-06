#include "Node.cpp"
#include "Skiplist.cpp"
#include <iostream>

int main()
{
	std::cout << "Creating empty Skiplist..." << std::endl;
	Skiplist<double> s1(100000);

	std::cout << "\nprint_vis Skiplist" << std::endl;
	s1.print_vis();

	std::cout << "\nSearching for value 33 | Result: " << (s1.search(33) != NULL) << std::endl;

	std::cout << "\nInserting value 3 ..." << std::endl;
	s1.insert(3);

	std::cout << "\nprint_vis Skiplist" << std::endl;
	s1.print_vis();

	std::cout << "\nSearching for value 3 | Result: " << (s1.search(3) != NULL) << std::endl;
	std::cout << "\nSearching for value 33 | Result: " << (s1.search(33) != NULL) << std::endl;

	std::cout << "\nInserting value 4 ..." << std::endl;

	s1.insert(4);
	std::cout << "\nprint_vis Skiplist" << std::endl;
	s1.print_vis();

	std::cout << "\nInserting value 33 ..." << std::endl;
	s1.insert(33);
	std::cout << "\nprint_vis Skiplist" << std::endl;
	s1.print_vis();


	std::cout << "\nInserting value 100 ..." << std::endl;
	s1.insert(100);
	std::cout << "\nprint_vis Skiplist" << std::endl;
	s1.print_vis();

	std::cout << "\nInserting value 1 ..." << std::endl;
	s1.insert(1);
	std::cout << "\nprint_vis Skiplist" << std::endl;
	s1.print_vis();
	s1.insert(324);
	s1.insert(23);
	s1.insert(42);
	s1.insert(1337);

	std::cout << "\nSearching for first, middle and last node in the list..." << std::endl;
	std::cout << "\nSearching for value 1 | Result: " << (s1.search(1) != NULL) << std::endl;
	std::cout << "\nSearching for value 33 | Result: " << (s1.search(33) != NULL) << std::endl;
	std::cout << "\nSearching for value 1337 | Result: " <<(s1.search(1337) != NULL) << std::endl;

	std::cout << "\nprint_vis Skiplist" << std::endl;
	s1.print_vis();

	return EXIT_SUCCESS;
}
