#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* TODO wrapper for cartesian product
 * memory deallocation functions
 * setPrint function
 * read data from a file or generated randomly
*/

typedef struct pair {
	int x;
	int y;
} Pair;

typedef struct set {
	int *data;
	int size;
} Set;

Set* initSet(const int *data, const int size) {
	Set *set = malloc(sizeof(Set));
	set->data = malloc(sizeof(int) * size);
	memcpy(set->data, data, sizeof(int) * size);
	set->size = size;

	return set;
}

Pair *initCartesian(const Set *X, const Set *Y) {
	int size = X->size * Y->size; // calculate the size of Cartesian product set
	Pair *cartesian = malloc(sizeof(Pair) * size);

	for (int i = 0; i < X->size; ++i) {
		for (int j = 0; j < Y->size; ++j) {
			cartesian[i * Y->size + j].x = X->data[i];
			cartesian[i * Y->size + j].y = Y->data[j];
		}
	}

	return cartesian;
}

void printCartesian(Pair *cart, int size) {
	for (int i = 0; i < size; ++i) {
		printf("<%i,%i> ", cart[i].x, cart[i].y);
	}
	printf("\n");
}

int main (int argc, char **argv) {
	int setA[] = {1, 2, 3, 4};
	int setB[] = {5, 6, 7, 8};

	Set *A, *B;
	A = initSet(setA, 4);
	B = initSet(setB, 4);

	Pair *cart = initCartesian(A, B);

	printCartesian(cart, 16);
	
	return 0;
}

