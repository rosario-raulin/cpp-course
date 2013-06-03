#ifndef HAVE_CSVParser_HPP
#define HAVE_CSVParser_HPP

#include <string>
#include <vector>
#include <regex>

const std::regex OUTER_REGEX("(\r\n|\n)");

// Source: http://www.programmersheaven.com/user/Jonathan/blog/73-Splitting-CSV-with-regex/
const std::regex INNER_REGEX(";(?!(?:[^\";]|[^\"];[^\"])+\")");

typedef std::vector<std::vector<std::string>> Table;

class CSVParser {
	std::string input;
public:
	CSVParser(const std::string& path);
	std::string raw();
	void toVector(Table& v);
	void print(const Table& v);
};

#endif
