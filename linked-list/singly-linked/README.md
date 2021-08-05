# Singly Linked List

 This is an implementation of a **s**ingly linked **list** (*s-list*) of integers.

 Files:

* [slist.c](slist.c) and [slist.h](slist.h) contain the basic structure of a *s-list* and the source code for its operations
* [sets.c](sets.c) contains the functions that perform set-like operations over *s-lists* and also a `main` function ready for examples
* [organizing.c](organizing.c) contains self-organizing strategies for *s-lists* and also a `main` function ready for examples

## The *s-list* structure

### Nodes

* `data` : field to store data of any type in the list (particularly to these examples, we have lists of `int`s)
* `counter` : counts how many times the data on that node was retrieved (for the self organizing strategy of frequency count)
* `next` : the *link* between two consecutive nodes

### List itself

* `head` : pointer to the first node in the list (do not forget it!)
* `lenght` : amount of nodes in the list

### Operations

 As a simplification of the general operations we could have:

* inject
  * inserts a node in the *front* of the *s-list*
  * implemented here as `l_inject`
* eject
  * deletes a node in the *front* of the *s-list*
  * implemented here as `l_eject` and in [BST](https://github.com/matheus-ft/data-structures/tree/main/binary-search-tree) as `dequeue`
* append
  * inserts a node in the *back* of the *s-list*
  * implemented in [BST](https://github.com/matheus-ft/data-structures/tree/main/binary-search-tree) as `enqueue` and in [*d-list*](https://github.com/matheus-ft/data-structures/tree/main/linked-list/doubly-linked) as `l_append`
* pop
  * deletes a node in the *back* of the *s-list*
  * `l_pop` was not implemented (see "Notes" below)

 And, in addition to the general operations:

* print (prints, sequentially, all the elements in a *s-list* within **square** brackets)
* set operations (*union*, *intersection*, and *difference*)
* self-organizing strategies (such as **m**ove-**t**o-**f**ront, *transpose*, and *count*)

### Notes

* [Hash maps](https://github.com/matheus-ft/data-structures/tree/main/hash-map) (not ready yet) are way better suited to represent sets, but it is still possible to use lists for simple application

* In this implementation, since we have a *singly* linked list, the operations *insert* and *delete* have time complexity $O(n)$ in the worst case and $O(1)$ in the best (insertion and deletion at the front of the list). To ease this problem (linear time is not *that* bad, but it isn't pretty either), we can:
  * separate the operations in "front" and "back" with a `tail` field
  * use a **doubly linked** list; this way we can optimize, using the `size` field, how many nodes the operations would have to visit before inserting or removing another node

    Problems:
  * using a `tail` pointer requires more memory and will make just the insertion constant time for both first and last nodes
    * remotion with constant time for the last node (`l_pop`) only happens if the list is also doubly-linked
  * a doubly linked list will require a lot more memory and does not *actually* reduce the time complexity from $O(n)$ for any node in the middle of the list, it only makes the operations more efficient

    In any case we can also limit the operations to the first node (and last node, if there's some memory to spare to a lot more pointers) of the list to avoid linear time

## The examples' inputs

 At the begining of each one of the example files you'll find a brief introduction and the format of the input for the program

 ---

### Fork and let me know in case you come up with a better and/or more general version of my implementation (or, of course, you've found any mistakes)

 I hope it helped you, though ; )
