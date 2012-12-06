all: aufgabe4

aufgabe4: 
	$(CXX) -Wall -g -o $@ main.cpp Node.h Node.cpp Skiplist.cpp Skiplist.h

clean:
	rm -f aufgabe4

test: aufgabe4
	valgrind --leak-check=full ./aufgabe4
