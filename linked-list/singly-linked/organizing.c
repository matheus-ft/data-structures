#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "list.h"

/*
	Self-organizing strategies are very useful when its necessary to obtain data
from a linked list (since it is not one of its strong points, compared to arrays for example),
making the whole process potentially more efficient.
	To test the three strategies implemented (comparing their costs) over a sorted list of ints from 1 to N, the input has to be:

N
amount_of_requirements
int_required int_required ... int_required
^D

	On any case of failure, the program stops with an error message. 
*/

int main(void) {
    // input
    int N, R;
    scanf("%d %d ", &N, &R);
    int req[R];
    for (int i = 0; i < R; ++i) scanf("%d ", &req[i]);

    // list creation + MFT
    list* lista;
    lista = lalloc();
    if (lista == NULL){
		fprintf(stderr, "Creation of the list failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}
    for (int key = N; key >= 1; key--)
        if ( l_insert(lista, key, 0) == 0) {
		fprintf(stderr, "Creation of the list failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}
    printf("MTF's cost: %d\n", MTF(lista, R, req));

    // list recycle + Transpose
    free_list(lista);
    lista = lalloc();
    if (lista == NULL){
		fprintf(stderr, "First recycle of the list failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}
    for (int key = N; key >= 1; key--)
        if ( l_insert(lista, key, 0) == 0) {
		fprintf(stderr, "First recycle of the list failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}
    printf("Transpose's cost: %d\n", transpose(lista, R, req));

    // list recycle + Count
    free_list(lista);
    lista = lalloc();
    if (lista == NULL){
		fprintf(stderr, "Second recycle of the list failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}
    for (int key = N; key >= 1; key--)
        if ( l_insert(lista, key, 0) == 0) {
		fprintf(stderr, "Second recycle of the list failed\n");
		fprintf(stderr, "Error: %s\n", strerror(errno));
		exit(errno);
	}
    printf("Count's cost: %d\n", count(lista, R, req));

    // end
    free_list(lista);
    return 0;
}
