# Binary Search Tree

 This is an implementation of a binary search tree (*BST*) explicitly.
 Also, in this implementation we utilize pointers to fathers.

 It should be noted that, in a BST, each node's key is greater than (or equal, if allowed) to any key in the left subtree, and less than (or equal, if allowed) to any key in the right subtree.
 In this implementation we will **not** allow duplicated values.

 Files:

* [bst.h](bst.h) and [bst.c](bst.c) contain the declarations and definitions of all functions and structs needed
* [bst-main.c](bst-main.c) contains a `main` function ready for examples

## The *BST* stucture

### Nodes

* `key` : field to store the key value of that node.
* `BF` : **b**alance **f**actor, if balancing is relevant (see "Notes" below)
* `father` , `left` , `right` : pointers to the father, left child, and right child nodes, respectively
* for more complex applications of a BST, a `data` field could be useful to store more information

### *Tree* itself

* `root` : the only information necessary to keep track of a tree is its root, that is, a pointer to its first node

### Operations

#### Main ones

* create (allocates memory and initiates the BST)
* search (finds the node containing a certain key)
* insert (adds a node in its proper position based on its key)
* remove (removes a node using auxiliar operations)
* pre-order / in-order / post-order (visit all the nodes in a BST and execute some operation on each; in this particular implementation, we simply print their keys)

#### Interesting ones

* successor / predecessor (see "Notes" below)
* avl? (checks if a BST is AVL or not)
* info (number of nodes, number of leaves, and height of a subtree)
  * definition: "leaf" is a node with two NULL "kids"
  * definition: "height" of a node is the largest number of edges (father-son pointer) from that node to some leaf
* longest-path (prints the longest - and most to the right - path inside a subtree)

#### Auxiliar ones

* free (for subtrees and the whole BST)
* replace (replaces one node by another one in the BST)
* delete (replaces a node by its successor and frees it)
* maximum / minimum (find the max/min key in a subtree)

### Notes

* Definition (**b**alance **f**actor):  $ BF(X) := Height(RightSubtree(X)) - Height(LeftSubtree(X)) $, for some node $X$
* Definition (successor node): the node that has the smallest key that is greater than the comparing node's key
  * with the notation node(key) we can say: node(5) is the successor of node(4) if both are in the same BST
  * if node(5) is not in a BST, but node(6) and node(4) are, then node(6) is the successor of node(4)
* Definition (predecessor node): the node that has the largest key that is less than the comparing node's key

## Auxiliar data structure: Queue

To execute the *longest-path* operation it is needed to store the keys of the nodes in such a way that the first one stored in will be the first one printed out.

This **FIFO** strategy is better explained in the [queue](https://github.com/matheus-ft/data-structures/tree/main/queue) directory. What matters here is that the queue was implemented with a [singly linked list](https://github.com/matheus-ft/data-structures/tree/main/linked-list/singly-linked) with a `tail` pointer.

### Structure

* `head` and `tail` : pointers to keep track of the first and last elements in que queue
* `size` : number of keys in the queue
* `key` and `next` : data stored in each list node and the link between consecutive nodes

### Operations

* queate (creates a queue)
* enqueue (adds a new key to que queue)
* dequeue (removes a key - not used here)
* print (prints every key in the queue)
* free (deallocates memory for the queue)

## The examples' inputs

 At the begining of the [bst-main.c](bst-main.c) you'll find a brief introduction and the format of the input for the program

 ---

### Fork and let me know in case you come up with a better and/or more general version of my implementation (or, of course, you've found any mistakes)

 I hope it helped you, though ; )
