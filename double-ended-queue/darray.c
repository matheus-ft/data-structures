#include <stdlib.h>
#include <string.h>
#include "darray.h"


darray* dalloc(int capacity) {
    darray* A = malloc(sizeof(darray));
    
    if (A) {
        A->data = (char**) malloc(capacity * sizeof(char*));

        A->first = 0;
        A->size = 0;
        
        A->capacity = capacity;
        A->min_cap = capacity;
        A->initial_cap = capacity;
    }

    return A;
}


void free_darray(darray* A) {
    int last = A->size + A->first - 1;
    int u;

    for (int i = A->first; i <= last; ++i) {
        u = i % A->capacity;
        free(A->data[u]);
    }

    free(A->data);

    free(A);
}


int da_push(darray* A, char* string) {
    char* str = malloc( (strlen(string) + 1) * sizeof(char));
    if (str)
        strcpy(str, string);
    else
        return 0;

    int last = A->size + A->first - 1;

    if (A->size == A->capacity) {
        char** B = (char**) malloc( (2 * A->capacity) * sizeof(char*));

        if (B == NULL) 
            return 0;
        else {
            int i = A->first;
            int n = 0;
            int u;
            while (i <= last) {
                u = i % A->capacity;
                B[n] = A->data[u];
                n++;
                i++;
            }

            B[n] = str;
            free(A->data);
            A->data = (char**) malloc(sizeof(B));
            A->data = B;

            A->capacity *= 2;
            if (A->capacity >= 4*A->initial_cap) 
                A->min_cap = A->capacity / 4;
            else
                A->min_cap = A->initial_cap;

            A->size++;
            A->first = 0;
            return 1;
        }
    }
    else {  // if the darray is not Full
        if (last >= A->capacity)
            last -= A->capacity;
        A->data[last + 1] = str;
        A->size++;
        return 1;
    }
}


char* da_pop(darray* A) {
    if (A->size == 0)
        return NULL;

    int last = A->size + A->first - 1;

    if ( (A->capacity > A->initial_cap) && (A->size <= (A->capacity / 4)) ) {
        char **B = (char **) malloc( (A->capacity / 2) * sizeof(char *));

        if (!B) 
            return NULL;
        else {
            int i = A->first;
            int n = 0;
            int u;
            while (i <= last) {
                u = i % A->capacity;
                B[n] = A->data[u];
                n++;
                i++;
            }

            free(A->data);
            A->data = (char **) malloc(sizeof(B));
            A->data = B;

            A->capacity /= 2;
            if (A->capacity >= 4*A->initial_cap) A->min_cap = A->capacity / 4;
            else
                A->min_cap = A->initial_cap;

            A->size--;
            A->first = 0;
            return A->data[n - 1];
        }
    } else {
        if (last >= A->capacity)
            last -= A->capacity;
        A->size--;
        return A->data[last];
    }
}


int da_inject(darray* A, char* string) {
    char* str = malloc( (strlen(string) + 1) * sizeof(char));
    if (str != NULL) 
        strcpy(str, string);
    else
        return 0;

    int last = A->size + A->first - 1;

    if (A->size == A->capacity) {
        char** B = (char**) malloc( (2 * A->capacity) * sizeof(char*));

        if (B == NULL) 
            return 0;
        else {
            int i = A->first;
            int n = 1;
            int u;
            while (i <= last) {
                u = i % A->capacity;
                B[n] = A->data[u];
                n++;
                i++;
            }

            B[0] = str;
            free(A->data);
            A->data = (char**) malloc(sizeof(B));
            A->data = B;

            A->capacity *= 2;
            if (A->capacity >= 4*A->initial_cap) A->min_cap = A->capacity / 4;
            else
                A->min_cap = A->initial_cap;

            A->size++;
            A->first = 0;
            return 1;
        }
    }
    else {
        int zero = (A->first != 0) ? A->first - 1 : A->capacity - 1;
        A->data[zero] = str;
        A->size++;
        A->first = zero;
        return 1;
    }
}


char* da_eject(darray* A) {
    if (A->size == 0)
        return NULL;

    int last = A->size + A->first - 1;

    if ( (A->capacity > A->initial_cap) && (A->size <= (A->capacity / 4)) ) {
        char **B = (char **) malloc( (A->capacity / 2) * sizeof(char *));

        if (!B) 
            return NULL;
        else {
            int i = A->first;
            int n = 0;
            int u;
            while (i <= last) {
                u = i % A->capacity;
                B[n] = A->data[u];
                n++;
                i++;
            }

            free(A->data);
            A->data = (char **) malloc(sizeof(B));
            A->data = B;

            A->capacity /= 2;
            if (A->capacity >= 4*A->initial_cap) A->min_cap = A->capacity / 4;
            else
                A->min_cap = A->initial_cap;

            A->size--;
            A->first = 1;
            return A->data[0];
        }
    } else {
        int second = (A->first != A->capacity - 1) ? A->first + 1 : 0;
        int o = A->first;

        A->size--;
        A->first = second;
        return A->data[o];
    }
}


char* da_first(darray* A) { return A->data[A->first]; }


char* da_last(darray* A) {
    int last = ( A->size + A->first - 1 ) % A->capacity;
    return A->data[last];
}


int da_is_empty(darray* A) {
    if (A == NULL || A->size == 0)
        return 1;
    else
        return 0;
}
