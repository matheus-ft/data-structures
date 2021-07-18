#include <stdlib.h>
#include <stdio.h>
#include "list.h"


/// main operations

list* lalloc() { return calloc(1,sizeof(list)); }


void free_list(list* L) {
  node* p = L->head;
  node* aux = NULL;

  while (p) {
    aux = p->next;
    free(p);
    p = aux;
  }

  free(L);
}


int l_insert(list* L, int data, int position) {
    node* n = malloc(sizeof(node));
    if (n == NULL)
        return 0;

    n->data = data;
    n->counter = 0;

    if ( position > L->size)
        position = L->size++;  // the increment must be done after
    else
        ++L->size;


    node* aux = L->head;
    for (int i = 0; i < position - 1; ++i)
        aux = aux->next;      
    n->next = aux->next;
    aux->next = n;
    
    return 1;
}


node* l_delete(list* L, int position) {
    node* aux = L->head;
    node* del = aux->next;

    for (int i = 0; i < position - 1; ++i)
        aux = aux->next;
        del = del->next;
    
    node* n = del;
    aux->next = del->next;

    return n;
}


void printl(list* L) {
  printf("[");

  node* p = L->head;
  while ( (p != NULL) && (p->next != NULL)) {
    printf("%d, ",p->data);
    p = p->next;
  } if (p)
    printf("%d",p->data);

  printf("]");
}


/// set-like operations

list* li_union(list* A, list* B) {
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
            if (li_insert(C, b->data) == 0) {
                free(C);
                return NULL;
            }
        }

        b = b->next;
    }

    while (a) {
        if (li_insert(C, a->data) == 0) {
            free(C);
            return NULL;
        }
        a = a->next;
    }

    return C;
}


list* li_intersection(list* A, list* B) {
    list* C = lalloc();
    if (!C)
        return NULL;

    node* a = A->head;
    node* b = B->head;

    while (b) {

        while (a != NULL) {
            if (b->data == a->data) {
                if (li_insert(C, b->data) == 0) {
                    free(C);
                    return NULL;
                }
            } a = a->next;
        } a = A->head;

        b = b->next;
    }

    return C;
}


list* li_difference(list* A, list* B) {
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
            if (li_insert(C, a->data) == 0) {
                free(C);
                return NULL;
            }
        }

        a = a->next;
    }

    return C;
}


/// self-organizing strategies

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
    }

    return cost;
}


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
    }
    return cost;
}

/// 