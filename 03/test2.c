#include <string.h>

int main(void) {
	volatile int array[8];
	//memset(array, 0, sizeof(int)*8);

	array[5] = 5;

	return *array;
}
