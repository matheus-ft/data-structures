#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "list.h"


/*
	Even though hash maps are data structures naturally set-like,
it is possible, as we shall do bellow, to make linked lists behave
as sets, with the operations being quite simple to code.
  	The code bellow evaluates and prints the union, intersection, and differences
between two lists of ints that are inputed as:

{a_1, a_2, ..., a_n}
{b_1, b_2, ..., b_m}
^D
  	
	On any case of failure, the program stops with an error message. 
*/


int main(void) {
	int i;  // numbers in the lists

	list* A = lalloc();
	if (A == NULL) {
		fprintf(stderr, "Creation of A failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}

	// Load A:
	scanf("{");
	while (scanf("%d",&i) == 1) {
		int st = l_insert(A,i,0);
		
		if (!st) {
			fprintf(stderr, "Creation of A failed\n");
			fprintf(stderr, "Error: %s\n", strerror(errno));
			exit(errno);
		}

		scanf(", ");
	}
	scanf("} ");


	list* B = lalloc();
	if (B == NULL) {
		fprintf(stderr, "Creation of B failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}

	// Load B:
	scanf("{");
	while (scanf("%d",&i) == 1) {
		int st = l_insert(B,i,0);

		if (!st) {
			fprintf(stderr, "Creation of B failed\n");
			fprintf(stderr, "Error: %s\n", strerror(errno));
			exit(errno);
		}

		scanf(", ");
	}
	scanf("} ");


	printf("A: ");
	printl(A);
	printf("\n");

	printf("B: ");
	printl(B);
	printf("\n");


	list* C;

	C = li_union(A,B);
	if (!C) {
		fprintf(stderr, "Creation of C=A+B failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}

	printf("A u B: ");
	printl(C);
	printf("\n");
	free_list(C);

	C = li_intersection(A,B);
	if (!C) {
		fprintf(stderr, "Creation of C=AB failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}

	printf("A i B: ");
	printl(C);
	printf("\n");
	free_list(C);

	C = li_difference(A,B);
	if (!C) {
		fprintf(stderr, "Creation of C=A-B failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}

	printf("A - B: ");
	printl(C);
	printf("\n");
	free_list(C);

	C = li_difference(B,A);
	if (!C) {
		fprintf(stderr, "Creation of C=B-A failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}

	printf("B - A: ");
	printl(C);
	printf("\n");
	free_list(C);

	free_list(A);
	free_list(B);
	return 0;
}
