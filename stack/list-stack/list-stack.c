#include <stdio.h>
#include <stdlib.h>
#include "list-stack.h"


stack* salloc(void){ return calloc(1, sizeof(stack)); }


int s_push(stack* s, int key){
    node* n = malloc(sizeof(node));
    if (!n || !s) 
        return 0;
    
    n->key = key;

    n->previous = s->head;
    s->head = n;

    s->height++;
    return 1;
}


node* s_pop(stack* s){
    if (!s) return NULL;

    node* del = s->head;
    
    if (s->height > 0) {
        s->head = del->previous;
        s->height--;
    }

    return del;
}


void free_stack(stack* s){
    if (s) {
        node* p = s->head;
        node* aux = NULL;

        while (p) {
            aux = p->previous;
            free(p);
            p = aux;
        }
    }
    free(s);
}


void print_s(stack* s){
    if (s) {
        node* p = s->head;
        if (p) {
            while (p->previous != NULL) {
                printf("| %d ", p->key);
                p = p->previous;
            } printf("| %d |\n",p->key);
        } else
            printf("The stack is empty.\n");
    }
    else
        printf("There's no stack.\n");
}
