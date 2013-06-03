#include "CSVParser.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
	if (argc > 1) {
		CSVParser p(argv[1]);

		// std::cout << p.raw() << std::endl;

		Table t;
		p.toVector(t);
		p.print(t);
	}

	return 0;
}
