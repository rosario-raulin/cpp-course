#include <map>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void fillMap(map<string,int>& m) {
	for (int i = 0; i < 10000000; ++i) {
		string key = "foobar" + to_string(i);
		m[key] = i;
	}
}

int getSum(const map<string,int>& m) {
	int sum = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		sum += it->second;
	}
	return sum;
}

int main(void) {
	//map<string,int> m;
	map<string,int> m;

	fillMap(m);
	int sum = getSum(m);

	cout << sum << endl;

	return 0;
}