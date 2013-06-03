#include "List.hpp"
#include "LinkedList.hpp"

#include <iostream>
#include <exception>

void dump(const List<int>& l) {
	std::cout << l.get() << std::endl;
}

int main(void) {
	LinkedList<int> l;

	try {
		l.add(5);
		dump(l);
		l.add(2);
		dump(l);
		l.add(42);
		dump(l);	
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}