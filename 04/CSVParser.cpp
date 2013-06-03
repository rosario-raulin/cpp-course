#include "CSVParser.hpp"

#include <fstream>
#include <iostream>

CSVParser::CSVParser(const std::string& path) {
	std::ifstream in(path, std::ios::in | std::ios::binary);
    if (in) {
        in.seekg(0, std::ios::end);
        (this->input).resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&(this->input)[0], (this->input).size());
        in.close();
    }
}

std::string CSVParser::raw() {
	return input;
}

void CSVParser::toVector(Table& v) {
	std::regex_token_iterator<std::string::iterator> oit(input.begin(), input.end(), OUTER_REGEX, -1);
	std::regex_token_iterator<std::string::iterator> end;

	while (oit != end) {
		std::string curr(oit->str());
		std::regex_token_iterator<std::string::iterator> iit(curr.begin(), curr.end(), INNER_REGEX, -1);

		std::vector<std::string> next;
		while (iit != end) {
			next.push_back(iit->str());
			++iit;
		}
		v.push_back(next);
		++oit;
	}
}

void CSVParser::print(const Table& v) {
	for (auto outer = v.begin(); outer != v.end(); ++outer) {
		std::cout << "| ";
		auto inner = outer->begin();
		while (inner != outer->end()) {
			std::cout << *inner << " | ";
			++inner;
		}
		std::cout << std::endl;
	}
}