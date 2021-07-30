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

 In addition to the general operations:
 * printing (prints, sequentially, all the elements in a *s-list* within square brackets)
 * set operations (*union*, *intersection*, and *difference*)
 * self-organizing strategies (such as **m**ove-**t**o-**f**ront, *transpose*, and *count*)
 
 ### Notes
 * In this implementation, since we have a *singly* linked list, the operations insert and delete have time complexity $O(n)$ in the worst case and $O(1)$ in the best (insertion and deletion at the beginning of the list). To ease this problem (linear time is not *that* bad, but it isn't pretty either), we can:
    * separate the operations in "front" and "back" with a `tail` field
    * use a **doubly linked** list; this way we can optimize, using the `size` field, how many nodes the operations would have to visit before inserting or removing another node
    
    Problems:
    * using a `tail` pointer will require more memory but will only turn into constant time operations at the first and last nodes of the list
    * a doubly linked list requires a lot more memory and does not *actually* reduce the time complexity from $O(n)$, it only makes the operations more efficient

    In any case we can also limit the operations to the first node (and last node, if there's some memory to spare to the `tail` field) of the list to avoid linear time
 

 ## The examples' inputs
 
 At the begining of each one of the example files you'll find a brief introduction and the format of the input for the program
 
 ---

 ### Fork and let me know in case you come up with a better and/or more general version of my implementation (or, of course, you've found any mistakes)

 I hope it helped you, though ; )
