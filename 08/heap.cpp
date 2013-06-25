#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

bool compare(const std::pair<char*,int>& p1, const std::pair<char*,int>& p2) {
	return p1.second <= p2.second;
}

int main(int argc, char** argv) {
	srand(time(nullptr));

	std::vector<std::pair<char*,int> > m;
	for (int i = 0; i < argc; ++i) {
		char* next = argv[i];
		m.push_back(std::pair<char*,int>(next, rand() % 100 + 1));
	}

	std::sort(m.begin(), m.end(), compare);

	for (auto it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}

	return 0;
}
