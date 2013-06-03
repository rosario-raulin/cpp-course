#include <string>
#include <iostream>
#include <cassert>

#include "bitarray.hpp"

using namespace std;
using namespace BiA;

int getIndex(int pos) {
	return (pos / (sizeof(uint32_t) * 8)) + 1;
}

int getOffset(int pos) {
	return (pos % (sizeof(uint32_t) * 8));
}

int getNumInts(int size) {
	return ((size + 31) / 32);
}

BitArray BiA::create(int size) {
	int numInts = 1 + getNumInts(size);
	BitArray array = new uint32_t[numInts];
	array[0] = size;
	memset(&(array[1]), 0, (numInts-1) * sizeof(uint32_t));

	return array;
}

int BiA::getSize(const BitArray& array) {
	return array[0];
}

bool BiA::get(const BitArray& array, int pos) {
	return array[getIndex(pos)] & (1 << getOffset(pos));
}

void BiA::set(BitArray& array, int pos, bool value) {
	if (value) {
		array[getIndex(pos)] |= (1 << getOffset(pos));
	} else {
		array[getIndex(pos)] &= ~(1 << getOffset(pos));
	}
}

void BiA::toggle(BitArray& array, int pos) {
	array[getIndex(pos)] ^= (1 << getOffset(pos));
}

BitArray BiA::concatenate(const BitArray& array1, const BitArray& array2) {
	int size = array1[0] + array2[0];
	BitArray array = create(size);

	int k = 0;
	for (int i = 0; i < getSize(array1); ++i, ++k) {
		set(array, k, get(array1, i));
	}
	for (int i = 0; i < getSize(array2); ++i, ++k) {
		set(array, k, get(array2, i));
	}

	return array;
}

void print(const BitArray& array) {
	for (int i = 0; i < getNumInts(array[0]) * sizeof(uint32_t) * 8; ++i) {
		cout << (int)get(array, i) << " ";
	}
	cout << endl;
}

void BiA::bit_or(BitArray& array1, const BitArray& array2) {
	if (array2[0] > array1[0]) {
		BitArray array = new uint32_t[getNumInts(array2[0])+1];
		array[0] = array2[0];
		
		memcpy(&(array[1]), &(array1[1]), array1[0] / 8);
		
		delete[] array1;
		array1 = array;
	}

	for (int i = 0; i < min(array1[0], array2[0]); ++i) {
		set(array1, i, get(array1, i) ^ get(array2, i));
	}
}

void stupid(const BitArray& a1, const BitArray& a2, const BitArray& a3) {
	bool x = get(a2, 23);
	bool y = get(a1, 3);
}

void print_binary(uint32_t x) {
	char buf[sizeof(uint32_t)*8+1];

	for (int i = 31; i >= 0; --i) {
		if (x) {
			buf[i] = (x & 1) ? '1' : '0';
		} else {
			buf[i] = '0';
		}
		x >>= 1;
	}
	buf[32]=0;
	cout << buf << endl;
}

/*
	Zu den Fragen:
		(1) Namespaces können mehr als ein Mal geöffnet und entsprechend mit Definitionen gefüllt werden.
		(2) Die Funktionen sind global definiert und es kann zu Konflikten kommen.
		(3) Nein, Polymorphie funktioniert nicht auf typedefs, da sie einfach zur Compile-Time mit dem eigentlichen Typen ersetzt werden.
*/

int main(int argc, char* argv[]) {
	BitArray A1 = create(17);
	const uint32_t initializationA1[] = { 0x0000a8c3 };
	for (int i=0; i<17; ++i)
		set( A1, i, (initializationA1[0] >> i)&1 );

	BitArray A2 = create(91);
	const uint32_t initializationA2[] = { 0x98affa34, 0xaffeaffe, 0x07bcdef1 };
	for( int i=0; i<91; ++i )
		set( A2, i, (initializationA2[i/32] >> (i&0x1f))&1 );

	// stupid(A1, A2, NULL);

	toggle( A1, 12 );
	toggle( A1, 17 );
	toggle( A2, 2 );
	toggle( A2, 18 );
	toggle( A2, 63 );
	set( A1, 1, get( A2, 23 ) );
	set( A2, 11, get( A1, 3 ) );

	BitArray A3 = concatenate(A1, A2);
	stupid(A1, A2, A3);

	//print(A1);
	//print(A2);
	//print(A3);

	uint32_t expectedResult[] = { 108, 0xe460b8c3, 0x5ffd3157, 0xbde25ffd, 0x00000f79 };
	// If the program stops here one or more of your operators didn't
	// work.
	assert( memcmp( A3, expectedResult, 4*5 ) == 0 );

	delete[] A1;
	delete[] A2;
	delete[] A3;

	return 0;
}