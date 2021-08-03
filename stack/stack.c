#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* salloc(int capacity){
    stack* s = malloc(sizeof(stack));
    if (s) {
        s->data = (int*) malloc(capacity * sizeof(int));
        s->capacity = capacity;
        s->last = -1;
        s->size = 0;
    }
    return s;
}

int resize_stack(stack* s, float factor){
    int* array = malloc(factor * s->capacity * sizeof(int));
    if (array == NULL) 
        return 0;
    
    s->capacity *= factor;
    for (int i = 0; i < s->size; ++i)
        array[i] = s->data[i];

    free(s->data);
    s->data = (int*) malloc(sizeof(int));
    s->data = array;
    free(array);
    
    return 1;
}

int s_push(stack* s, int key){
    if (s == NULL) return 0;

    if (s->size == s->capacity)
        if ( !resize_stack(s, 2) ) return 0;  // this will try to resize and continue accordingly

    s->data[++s->last] = key;  // this works because the increment is done *before* the access
    s->size++;
    return 1;
}

int* s_pop(stack* s){
    if (s == NULL) return s;
    else if (s->last >= 0) {
        if (s->size <= 0.25 * s->capacity)
            resize_stack(s, 0.5);
        --s->size;
        int* popped = &s->data[s->last--];  // this works because the increment is done *after* the access
        return popped;
    }
    else return NULL;
}

void free_stack(stack* s){
    if (s) {
        // if q->data stores pointers of any kind, they should be freed too
        free(s->data);
    } free(s);
}

void prints(stack* s){
    if (s == NULL)
        printf("There's no stack.\n");
    else if (s->size == 0)
        printf("The stack is empty.\n");
    else {
        for (int i = s->last; i >= 0; --i)
            printf("| %d ", s->data[i]);
    }
}
