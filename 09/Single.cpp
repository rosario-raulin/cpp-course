#include "Single.hpp"

extern Single* Single::instance;

Single::Single() {}

Single* Single::getInstance() {
	if (instance == nullptr) {
		instance = new Single();
	}
	return instance;
}

int main(void) {
	return 0;
}