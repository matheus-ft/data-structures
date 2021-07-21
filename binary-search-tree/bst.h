#ifndef BST_H
#define BST_H

/* Main data structure */
/// Binary search tree node
struct bst_node {
    int key;
    int BF;

    struct bst_node* father;
    struct bst_node* left;
    struct bst_node* right;
};
typedef struct bst_node node;

/// Binary search tree capsule
struct binary_search_tree {
    node* root;
};
typedef struct binary_search_tree tree;

/* Auxiliar data structure */
/// Singly linked list node
struct list_node {
    int key;
    struct list_node* next;
};
typedef struct list_node lnode;

/// Singly linked list info
struct linked_list {
    lnode* head;
    int size;
    lnode* tail;
};
typedef struct linked_list list;


/* ************
 * LL Functions
 * ************ */

/**
 * Allocates memory for a linked list with NULL head and size 0
 * @return pointer to the list created or NULL if
  memory allocation fails.
 */
list* lalloc();

/**
 * Inserts a node with certain key in the end of a linked list
 * @param L list receiving the data
 * @param key the (integer) key of the node to be inserted
 * @return 1 when successful and 0 otherwise
 */
int l_append(list* L, int key);

/**
 * Prints the keys of a linked list sequentially and separated by spaces
 */
void printl(list* L);

/**
 * Deallocate the memory of a linked list
 */
void free_list(list* L);


/* *********
 * BST Functions
 * ********* */

/**
 * Allocates memory and creates a BST with NULL root
 * @return pointer to the tree created
 */
tree* bst_create(void);

/**
 * Recursively searches for a node with a certain key
 * @param k (integer) key wanted
 * @param p pointer to the root of the BST-subtree in which the search is performed
 * @return pointer to the node that has the key wanted or NULL if there's no such node
 */
node* bst_search(node* p, int k);

/**
 * Inserts data in a binary search tree
 * @param T pointer to the BST
 * @param data (integer) key of the node to be inserted
 * @return 1 when successful and 0 otherwise (insufficient memory or already existing key)
 */
int bst_insert(tree* T, int data);

/**
 * Frees all the nodes in the BST-subtree
 * @param p pointer to the subtree's root
 */
void bst_subtree_free(node* p);

/**
 * Frees an entire binary search tree
 * @param T pointer to the BST
 */
void bst_free(tree* T);

/**
 * Finds the minimum key in a BST-subtree
 * @param p pointer to the root of the BST-subtree in question
 * @return pointer to the node that has that key
 */
node* bst_minimum(node* p);

/**
 * Finds the maximum key in a BST-subtree
 * @param p pointer to the root of the BST-subtree in question
 * @return pointer to the node that has that key
 */
node* bst_maximum(node* p);

/**
 * Finds the successor of a certain node
 * @param p pointer to the node whose successor is requested
 * @return pointer to the successor node
 */
node* bst_successor(node* p);

/**
 * Finds the predecessor of a certain node
 * @param p pointer to the node whose predecessor is requested
 * @return pointer to the predecessor node
 */
node* bst_predecessor(node* p);

/**
 * Replaces a node by another one within a binary search tree
 * @param T pointer to the BST containing the nodes
 * @param old pointer to the node that will be replaced
 * @param new pointer to the node replacing the other one
 */
void bst_replace(tree* T, node* old, node* new);

/**
 * Deletes a certain node (by replacing it with its successor and then freeing it) within a BST
 * @param T pointer to the binary search tree in question
 * @param p pointer to the node to be removed
 */
void bst_delete(tree* T, node* p);

/**
 * Removes a key from a BST (by searching for its node and deleting it)
 * @param T pointer to the binary search tree
 * @param key (integer) key of the node to be removed
 * @return 1 when successful and 0 otherwise (data not in the tree)
 */
int bst_remove(tree* T, int key);

/**
 * Pre-Order prints all nodes in a BST-subtree
 * @param n pointer to the root of the BST-subtree in question
 */
void bst_pre_order(node* n);

/**
 * In-Order prints all nodes in a BST-subtree
 * @param n pointer to the root of the BST-subtree in question
 */
void bst_in_order(node* n);

/**
 * Post-Order prints all nodes in a BST-subtree 
 * @param n pointer to the root of the BST-subtree in question
 */
void bst_post_order(node* n);

/**
 * @return the number of nodes in a BST-subtree
 * @param p pointer to the root of the BST-subtree in question
 */
int bst_nnodes(node* p);

/**
 * @return the number of leaves in a BST-subtree
 * @param p pointer to the root of the BST-subtree in question
 * @definition "leaf" is a node with two NULL "kids"
 */
int bst_nleaves(node* p);

/**
 * @return the maximum between two integers
 */
int max(int a, int b);

/**
 * @return the height of a BST-subtree
 * @param n pointer to the root of the BST-subtree in question
 * @param T pointer to the BST containing the node pointed by <n>
 */
int bst_height(node* n, tree* T);

/**
 * Gives the "path" of the height of a BST-subtree
 * @param n pointer to the root of the BST-subtree in question
 * @return a list with the nodes from <n> to some leaf
 */
list* bst_height_path(node* n);

/**
 * Prints out the "path" of the height of a BST-subtree
 * @param n pointer to the root of the BST-subtree in question
 * @return 1 when successful and 0 otherwise (empty tree)
 */
int bst_print_height(node* n);

/**
 * Evaluates the Balance Factor of each node in a BST-subtree
 * @param n pointer to the root of the BST-subtree in question
 * @param T pointer to the BST containing the node pointed by <n>
 */
void bst_BF(node* n, tree* T);

/**
 * Verifies if a BST-subtree is AVL or not
 * @param n pointer to the root of the BST-subtree in question
 * @return 1 when True and 0 when False
 */
int bst_is_avl(node* n);

#endif