#include <iostream>

using namespace std;

typedef int stupid;

class A {
public:
	int foo(stupid x) {
		return x;
	}
	int foo(char x) {
		return x+1;
	}
};

int main(void) {
	A ex;
	cout << ex.foo(23) << endl;
	cout << ex.foo('A') << endl;
	return 0;
}