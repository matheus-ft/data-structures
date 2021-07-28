#include <stdlib.h>
#include <stdio.h>
#include "slist.h"


list* lalloc(){ return calloc(1, sizeof(list)); }


void free_list(list* L){
    node* p = L->head;
    node* aux = NULL;

    while (p) {
        aux = p->next;
        free(p);
        p = aux;
    }

    free(L);
}


int l_insert(list* L, int data, int position){
    // corrects the position argument (in a "user-friendly" way)
    if (position < 0) {
        position = L->size + position + 1;  // this makes some sense, think about it
        // return 0;  // if you do not accept negative positions, just return 0
    } else if (position > L->size) {
        position = L->size; 
    }

    // allocates memory for the new data point, stops on failure
    node* n = malloc(sizeof(node));
    if (n == NULL)
        return 0;

    // the insertion itself
    n->data = data;
    n->counter = 0;

    if (position == 0) {
        n->next = L->head;
        L->head = n;
    } 
    else {
        node* aux = L->head;
        for (int i = 0; i < position - 1; ++i)
            aux = aux->next;
        
        n->next = aux->next;
        aux->next = n;
    }
    
    L->size++;
    return 1;
}


node* l_delete(list* L, int position){
    node* aux = L->head;
    node* del = aux->next;

    for (int i = 0; i < position - 1; ++i)
        aux = aux->next;
        del = del->next;
    
    node* n = del;
    aux->next = del->next;

    return n;
}


void printl(list* L){
    printf("[");

    node* p = L->head;
    while ( (p != NULL) && (p->next != NULL) ) {
        printf("%d, ",p->data);
        p = p->next;
    } if (p)
        printf("%d",p->data);

    printf("]");
}
