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
  int lenght;  // number of nodes in the sequence
}; 
typedef struct linked_list list;


/**
 * @brief Creates an empty list of ints.

 * @return A pointer to the new list or NULL if
  memory allocation fails.
 */
list* lalloc(void);


/**
 * @brief Releases a list of ints and all its nodes.
 */
void free_list(list* L);


/**
 * @brief Inserts a new node in the begining of the list.
 * 
 * @param L linked list receiving the new node
 * @param data the data being stored in the new node 
 * @return 1 on success; 0 on failure. 
 */
int l_inject(list* L, int data);


/**
 * @brief Inserts a new node at the desidred position in a list of ints.

 * @param L linked list receiving a new node
 * @param data the data being stored in the new node 
 * @param position the "index" of the new node, must be in the closed interval [0, L->lenght]
 * @return 1 on success; 0 if list is null/memory allocation fails; errno if the position is invalid.
 */
int l_insert(list* L, int data, int position);


/**
 * @brief Removes a node from the begining of the list.
 * 
 * @param L linked list from which we eject the node
 * @return Address of a node with the data from the ejected element.
 * If the list is empty or null, returns NULL.
 */
node* l_eject(list* L);


/**
 * @brief Removes a node from a certain point in a list of ints.

 * @param L linked list from which we delete a node
 * @param position "index" of the node to be removed, must be in the right-open interval [0, L->lenght)
 * @return Address of a node with the data from the deleted element.
 * If the list is empty or the position is invalid, returns NULL.
 */
node* l_delete(list* L, int position);


/**
 * @brief Prints the <n> elements of a list of ints with the formatting: [a_1, a_2, ..., a_n].

 * @param L linked list to be printed
 */
void printl(list* L);
