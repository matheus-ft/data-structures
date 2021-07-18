/// Singly linked list node
typedef struct list_node {
  int data;
  int counter;  // the amount of times the node's data has been requested
  struct node* next;
} node;


/// Singly linked list capsule
typedef struct linked_list {
  node* head;  // the first node in the list
  int size;
} list;


/// main operations
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


/// set-like operations
/**
 * @brief Evaluates the union of lists of ints (A+B). If memory allocation fails any partially constructed list is freed.
 
 * @return a new list on success; on failure, NULL.
 */
list* li_union(list* A, list* B);


/**
 * @brief Evaluates the intersection of lists of ints (AB).  If memory allocation fails any partially constructed list is freed.
 
 * @return a new list on success; on failure, NULL.
 */
list* li_intersection(list* A, list* B);


/**
 * @brief Evaluates the difference (A-B) of lists of ints. If memory allocation fails any partially constructed list is freed.

 * @return a new list on success; on failure, NULL. 
 */
list* li_difference(list* A, list* B);


/// self-organizing strategies
/**
 * @brief Organizes a linked list while accessing its data based on certain requests.
 The strategy here is to move to the front of the list the node containing the data requested.
  
 * @param L list containing the data being requested
 * @param number amount of requests
 * @param requests array of the ints being requested (data is assumed to be in the list, pay attention to this)
 * @return the cost of the whole operation (in amount of nodes visited)
 */
int MTF(list* L, int number, int requests[number]);


/**
 * @brief Organizes a linked list while accessing its data based on certain requests.
 The strategy here is to swap the node containing the data requested with its predecessor.
  
 * @param L list containing the data being requested
 * @param number amount of requests
 * @param requests array of the ints being requested (data is assumed to be in the list, pay attention to this)
 *  * @return the cost of the whole operation (in amount of nodes visited)
 */
int transpose(list* L, int number, int requests[number]);


/**
 * @brief Organizes a linked list while accessing its data based on certain requests.
 The strategy here is to sort the list not by the data stored, but by the amount of times each node
 is requested. When two nodes have the same counter value, the most recent request gets the priority.
  
 * @param L list containing the data being requested
 * @param number amount of requests
 * @param requests array of the ints being requested (data is assumed to be in the list, pay attention to this)
 * @return the cost of the whole operation (in amount of nodes visited)
 */
int count(list* L, int number, int requests[number]);

///