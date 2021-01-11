#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* TODO 
 * read data from a file or generated randomly
 * partition cartesian product into a set of equivalence classes. Equivalence
 * relation: have the same first coordinate
*/

typedef struct pair {
	int x;
	int y;
} Pair;

typedef struct set {
	int *data;
	int size;
} Set;

typedef struct cartesian {
	Pair *data;
	int size;
} CartProduct;

Set* initSet(const int *data, const int size) {
	Set *set = malloc(sizeof(Set));
	set->data = malloc(sizeof(int) * size);
	memcpy(set->data, data, sizeof(int) * size);
	set->size = size;

	return set;
}

void uninitSet(Set *set) {
	free(set->data);
	free(set);
}

CartProduct *initCartesian(const Set *X, const Set *Y) {
	CartProduct *cart = malloc(sizeof(CartProduct));
	cart->size = X->size * Y->size; // calculate the size of Cartesian product set

	cart->data = malloc(sizeof(Pair) * cart->size);

	for (int i = 0; i < X->size; ++i) {
		for (int j = 0; j < Y->size; ++j) {
			cart->data[i * Y->size + j].x = X->data[i];
			cart->data[i * Y->size + j].y = Y->data[j];
		}
	}

	return cart;
}

void uninitCartesian(CartProduct *cart) {
	free(cart->data);
	free(cart);
}

void printCartesian(const CartProduct *cart) {
	for (int i = 0; i < cart->size; ++i) {
		printf("<%i,%i> ", cart->data[i].x, cart->data[i].y);
	}
}

void printSet(const Set *set) {
	printf("{ ");
	for (int i = 0; i < set->size; ++i) {
		printf("%i ", set->data[i]);
	}
	printf("}");
}

int main (int argc, char **argv) {
	int setA[] = {1, 2, 3, 4};
	int setB[] = {5, 6, 7, 8};

	Set *A, *B;
	A = initSet(setA, 4);
	B = initSet(setB, 4);
	printSet(A);
	printf("\n");
	printSet(B);
	printf("\n");

	CartProduct *cart = initCartesian(A, B);

	printCartesian(cart);
	printf("\n");

	// free previously allocated memory
	uninitSet(A);
	uninitSet(B);
	uninitCartesian(cart);
	
	return 0;
}
