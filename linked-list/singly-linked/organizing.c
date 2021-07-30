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


#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "slist.h"


int MTF(list* L, int number, int requests[number]);
int transpose(list* L, int number, int requests[number]);
int count(list* L, int number, int requests[number]);


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


/**
 * @brief Organizes a linked list while accessing its data based on certain requests.
 The strategy here is to move to the front of the list the node containing the data requested.
  
 * @param L list containing the data being requested
 * @param number amount of requests
 * @param requests array of the ints being requested (data is assumed to be in the list, pay attention to this)
 * @return the cost of the whole operation (in amount of nodes visited)
 */
int MTF(list* L, int number, int requests[number]){
    int cost = 0;

    for (int i = 0; i < number; ++i) {
        int r = requests[i];  // data being requested
        node* loop = L->head;  // auxiliar pointer
        node* ptr = NULL;  // node being requested
        node* prev = NULL;  // node "behind" the one being requested

        do {
            cost++;

            prev = ptr;
            ptr = loop;
            loop = loop->next;
        }   while (ptr->data != r);

        if (ptr != L->head) {
            prev->next = ptr->next;
            ptr->next = L->head;
            L->head = ptr;
        }

        // here could/should be added a function that operates over the node with the requested data
    }

    return cost;
}


/**
 * @brief Organizes a linked list while accessing its data based on certain requests.
 The strategy here is to swap the node containing the data requested with its predecessor.
  
 * @param L list containing the data being requested
 * @param number amount of requests
 * @param requests array of the ints being requested (data is assumed to be in the list, pay attention to this)
 *  * @return the cost of the whole operation (in amount of nodes visited)
 */
int transpose(list* L, int number, int requests[number]){
    int cost = 0;
    
    for (int i = 0; i < number; ++i) {
        int r = requests[i];  // data being requested
        node* ptr = L->head;  // node being requested
        node* prev = NULL;  // node that will be swapped with ptr
        node* preprev = NULL;  // node "behind" the one being swapped

        while (ptr) {
            ++cost;

            if (ptr->data == r)
                break;

            preprev = prev;
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr != L->head) {
            prev->next = ptr->next;
            ptr->next = prev;
            if (prev == L->head)
                L->head = ptr;
            if (preprev != NULL)
                preprev->next = ptr;
        }

        // here could/should be added a function that operates over the node with the requested data
    }

    return cost;
}


/**
 * @brief Organizes a linked list while accessing its data based on certain requests.
 The strategy here is to sort the list not by the data stored, but by the amount of times each node
 is requested. When two nodes have the same counter value, the most recent request gets the priority.
  
 * @param L list containing the data being requested
 * @param number amount of requests
 * @param requests array of the ints being requested (data is assumed to be in the list, pay attention to this)
 * @return the cost of the whole operation (in amount of nodes visited)
 */
int count(list* L, int number, int requests[number]){
    int cost = 0;
    
    for (int i = 0; i < number; ++i) {
        int r = requests[i];  // data being requested
        node* ptr = L->head;  // node being requested
        node* prev = NULL;  // node "behind" the one being requested

        while (ptr) {
            ++cost;

            if (ptr->data == r) {
                ptr->counter += 1;
                break;
            }

            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr != L->head) {
            node* loop = L->head;
            node* prevloop = NULL;

            while ( (loop != NULL) && (ptr != loop) ) {
                /* all nodes previous to the node being requested *should* have 
                higher counters than the node being requested, however, in case 
                they don't, the node being requested just got "more important" 
                then the other ones and, for that reason, it will be moved to the
                front of the sequence of nodes with equal or smaller counter */

                if (loop->counter <= ptr->counter) {
                    prev->next = ptr->next;
                    ptr->next = loop;
                    
                    if (prevloop == NULL)
                        L->head = ptr;
                    else
                        prevloop->next = ptr;

                    break;
                }

                prevloop = loop;
                loop = loop->next;
            }
        }

        // here could/should be added a function that operates over the node with the requested data
    }
    return cost;  // this function can be optimized
}
