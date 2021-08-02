#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "slist.h"


list* lalloc(){ return calloc(1, sizeof(list)); }


void free_list(list* L){
    if (L) {
        node* p = L->head;
        node* aux = NULL;

        while (p) {
            aux = p->next;
            free(p);
            p = aux;
        }
    }
    free(L);
}


int l_inject(list* L, int data){
    node* n = malloc(sizeof(node));
    if (!n || !L) 
        return 0;
    
    n->data = data;
    n->counter = 0;

    n->next = L->head;
    L->head = n;

    L->lenght++;
    return 1;
}


int l_insert(list* L, int data, int position){
    if (position == 0)
        return l_inject(L, data);
    else if (position < 0) {
        fprintf(stderr, "Negative position\n");
		fprintf(stderr, "Error: %s\n---\n", strerror(errno));
		return errno;
    }
    else if (position > L->lenght) {
        fprintf(stderr, "Index out of range\n");
		fprintf(stderr, "Error: %s\n---\n", strerror(errno));
		return errno;
    }

    /*
    // If you want to be "user-friendly" and correct the <position> argument
    // so that the function does not raise any error, use the code below:

    if (position < 0)
        position = L->lenght + position + 1;  // this makes sense, think about it
    else if (position > L->lenght)
        position = L->lenght;
    
    */

    // allocates memory for the new data point, stops on failure
    node* n = malloc(sizeof(node));
    if (!n || !L) 
        return 0;

    // the insertion itself
    n->data = data;
    n->counter = 0;

    node* aux = L->head;
    for (int i = 0; i < position - 1; ++i)
        aux = aux->next;
    
    n->next = aux->next;
    aux->next = n;
    
    L->lenght++;
    return 1;
}


node* l_eject(list* L){
    if (!L) return NULL;

    node* del = L->head;
    
    if (L->lenght > 0) {
        L->head = del->next;
        L->lenght--;
    }

    return del;
}


node* l_delete(list* L, int position){
    if (position == 0)
        return l_eject(L);
    else if (position < 0) {
        fprintf(stderr, "Negative position\n");
		fprintf(stderr, "Error: %s\n---\n", strerror(errno));
		return NULL;
    }
    else if (position >= L->lenght) {
        fprintf(stderr, "Index out of range\n");
		fprintf(stderr, "Error: %s\n---\n", strerror(errno));
		return NULL;
    }
    else if (!L)
        return NULL;

    /*
    // If you want to be "user-friendly" and correct the <position> argument
    // so that the function does not raise any error, use the code below:
    
    if (position < 0)
        position = L->lenght + position;  // this makes sense, think about it
    else if (position >= L->lenght)
        position = L->lenght - 1;
    
    */
    
    node* aux = L->head;
    node* del = NULL;

    if (L->lenght > 0) {
        for (int i = 0; i < position - 1; ++i)
            aux = aux->next;
        
        del = aux->next;
        aux->next = del->next;
        L->lenght--;
    }

    return del;
}


void printl(list* L){
    if (L) {
        node* p = L->head;
        if (p) {
            printf("[");
            while (p->next != NULL) {
                printf("%d, ", p->data);
                p = p->next;
            } printf("%d]\n",p->data);
        } else
            printf("The list is empty.\n");
    }
    else
        printf("There is no list.\n");
}
