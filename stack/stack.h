/// Stack structure
typedef struct array_stack {
    int* data;  // dynamic array of ints
    int capacity;  // maximum amount of data points permitted (ideally an even number)
    int last;  // index of the stack's top element 
    int size;  // amount of data points stored
} stack;

/**
 * @brief Allocates memory and starts an empty stack.
 * 
 * @param capacity initial number of data points supported
 * @return the address of the stack created or NULL, if it failed. 
 */
stack* salloc(int capacity);

/**
 * @brief Changes the array supporting the stack by multipying its capacity by a given factor.
 * 
 * @param s stack being resized
 * @param factor ratio between the new capacity and the old one
 * @return 1 on success. 0 on failure.
 */
int resize_stack(stack* s, float factor);

/**
 * @brief Appends a data point in the array. 
 * If the darray is full, it tries to double its capacity and then adds the key.
 * When resizing the array is not possible, it will not push. 
 * 
 * @param s stack in which data is added
 * @param key the data inserted
 * @return 1 on success. 0 on failure.
 */
int s_push(stack* s, int key);

/**
 * @brief Removes, by invalidating its position with the `last` field, a data point from the stack.
 * If the darray is a quarter full, it tries to halve its capacity, no matter how small the array already is. 
 * When resizing the array is not possible, it will pop without changing the capacity.
 * 
 * @return pointer to the data point invalidated. NULL if the stack is empty or null. 
 */
int* s_pop(stack* s);

/**
 * @brief Releases a whole stack deallocating memory.
 */
void free_stack(stack* s);

/**
 * @brief Displays all the contents in a stack (LIFO, of course) separeted by '|'.
 * 
 * @param s stack being printed.
 */
void prints(stack* s);
