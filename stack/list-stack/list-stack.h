/// Singly linked list node
typedef struct stack_node {
    int key;  // data stored
    struct stack_node* previous;  // link to the node added before
} node;

/// Stack capsule
typedef struct list_stack {
    node* head;  // pointer the the last data point in the stack 
    int height;  // amount of nodes in the list
} stack;

/**
 * @brief Allocates memory and starts an empty stack.
 * 
 * @return the address of the stack created or NULL, if it failed. 
 */
stack* salloc(void);

/**
 * @brief Injects a data point in the linked list.  
 * 
 * @param s stack in which data is added
 * @param key the data inserted
 * @return 1 on success. 0 on failure.
 */
int s_push(stack* s, int key);

/**
 * @brief Removes the node on the top of the stack by ejecting it.
 * 
 * @return Address of a node with the data from the ejected element.
 * If the stack is empty or null, returns NULL.
 */
node* s_pop(stack* s);

/**
 * @brief Releases a whole stack deallocating memory.
 */
void free_stack(stack* s);

/**
 * @brief Displays all the contents in a stack (LIFO, of course) separeted by '|'.
 * 
 * @param s stack being printed.
 */
void print_s(stack* s);
