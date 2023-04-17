#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct polyNode* polypointer;
typedef struct polyNode {
	int coef;
	int expon;
	polypointer link;
};

polypointer a, b;

void print_node(polypointer);
void insert_first(int, int);
void insert_last(int, int);
polypointer padd(polypointer, polypointer);
polypointer deleteAll(polypointer);

int main() {
	char c;

	FILE* fp1 = fopen("a.txt", "r");
	FILE* fp2 = fopen("b.txt", "r");

	fscanf(fp1, "%c", c);
	while (!feof(fp1)) {
		fscanf(fp1, "%d %d", &a->coef, &a->expon);
		if (strcmp(c, "a")==0) {
			insert_first(a->coef, a->expon);
		}
		else {
			insert_last(a->coef, a->expon);
		}
	}

	fscanf(fp2, "%c", c);
	while (!feof(fp2)) {
		fscanf(fp2, "%d %d", &b->coef, &b->expon);
		if (strcmp(c, "a") == 0) {
			insert_first(b->coef, b->expon);
		}
		else {
			insert_last(b->coef, b->expon);
		}
	}


}

void insert_first(int coef, int expon) {

}