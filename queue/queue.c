#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue* queate(int capacity){
    queue* q = malloc(sizeof(queue));
    if (q) {
        q->first = 0;
        q->size = 0;
        q->capacity = capacity;
        q->data = malloc(capacity * sizeof(int));
    }
    return q;
}

int enqueue(queue* q, int key){
    if (q->size == q->capacity)
        return 0;

    int position = (q->first + q->size) % q->capacity;
    q->data[position] = key;  // because first + size - 1 == last

    q->size++;
    return 1;
}

int dequeue(queue* q){
    int ex = q->first;

    q->first = (q->first + 1) % q->capacity;
    q->size--;

    return q->data[ex];
}

void free_queue(queue* q){
    // if q->data stores pointers of any kind, they should be freed too
    free(q->data);
    free(q);
}

void printq(queue* q){
    int pos = q->first;
    while (pos < q->capacity){
		printf("%d ", q->data[pos]);
        pos = (pos + 1) % q->capacity;
    }
}
