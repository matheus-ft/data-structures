/// Singly linked list node
struct list_node {
  int data;
  int counter;  // the amount of times the node's data has been requested
  struct list_node* next;
}; 
typedef struct list_node node;


/// Singly linked list capsule
struct linked_list {
  node* head;  // the first node in the list
  int size;
}; 
typedef struct linked_list list;


/**
 * @brief Creates an empty list of ints.

 * @return A pointer to the new list or NULL if
  memory allocation fails.
 */
list* lalloc();


/**
 * @brief Release a list of ints and all its nodes.
 */
void free_list(list* L);


/**
 * @brief Insert a new node at the desidred position in a list of ints.

 * @param L linked list receiving a new node
 * @param data the data being stored in the new node 
 * @param position the "index" of the new node (first node has position == 0)
 * @return 1 on success or 0 if memory allocation.
 */
int l_insert(list* L, int data, int position);


/**
 * @brief Removes a node from a certain point in a list of ints.

 * @param L linked list from which we delete a node
 * @param position "index" of the node to be removed (first node has position == 0)
 * @return Address of a node with the data from the deleted element.
 */
node* l_delete(list* L, int position);


/**
 * @brief Prints the contents of a list of ints with the formatting: [a_1, a_2, ..., a_n].

 * @param L linked list to be printed
 */
void printl(list* L);
