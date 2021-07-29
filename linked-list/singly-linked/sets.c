/**
 * @file sets.c
 * @author Matheus Feres Turcheti (matheusft.mft@gmail.com)
 * @brief
	
	Even though hash maps are data structures naturally set-like,
it is possible, as we shall do bellow, to make linked lists behave
as sets, with the operations being quite simple to implement.
  	The code bellow evaluates and prints the union, intersection, and differences
between two lists of ints that are inputed as:

{a_1, a_2, ..., a_n}
{b_1, b_2, ..., b_m}
^D
  	
	On any case of failure, the program stops with an error message.

 * @version 0.2
 * @date 2021-07-29
 * 
 */


#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "slist.h"


list* li_union(list* A, list* B);
list* li_intersection(list* A, list* B);
list* li_difference(list* A, list* B);


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


/**
 * @brief Evaluates the union of lists of ints (A+B). If memory allocation fails any partially constructed list is freed.
 
 * @return a new list on success; on failure, NULL.
 */
list* li_union(list* A, list* B){
    list* C = lalloc();
    if (!C)
        return NULL;

    node* a = A->head;
    node* b = B->head;
    int do_it;

    while (b) {
        do_it = 1;
        while (a != NULL) {
            if (b->data == a->data) {
                do_it = 0;
                break;
            } a = a->next;
        } a = A->head;

        if (do_it) {
            if (l_insert(C, b->data, 0) == 0) {
                free(C);
                return NULL;
            }
        }

        b = b->next;
    }

    while (a) {
        if (l_insert(C, a->data, 0) == 0) {
            free(C);
            return NULL;
        }
        a = a->next;
    }

    return C;
}


/**
 * @brief Evaluates the intersection of lists of ints (AB).  If memory allocation fails any partially constructed list is freed.
 
 * @return a new list on success; on failure, NULL.
 */
list* li_intersection(list* A, list* B){
    list* C = lalloc();
    if (!C)
        return NULL;

    node* a = A->head;
    node* b = B->head;

    while (b) {

        while (a != NULL) {
            if (b->data == a->data) {
                if (l_insert(C, b->data, 0) == 0) {
                    free(C);
                    return NULL;
                }
            } a = a->next;
        } a = A->head;

        b = b->next;
    }

    return C;
}


/**
 * @brief Evaluates the difference (A-B) of lists of ints. If memory allocation fails any partially constructed list is freed.

 * @return a new list on success; on failure, NULL. 
 */
list* li_difference(list* A, list* B){
    list* C = lalloc();
    if (!C)
        return NULL;

    node* a = A->head;
    node* b = B->head;
    int do_it;

    while (a) {
        do_it = 1;
        while (b != NULL) {
            if (a->data == b->data) {
                do_it = 0;
                break;
            } b = b->next;
        } b = B->head;

        if (do_it) {
            if (l_insert(C, a->data, 0) == 0) {
                free(C);
                return NULL;
            }
        }

        a = a->next;
    }

    return C;
}
