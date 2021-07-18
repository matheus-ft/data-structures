# Singly Linked List
 This is an implementation of a linked list (*list*) in the "classical" fashion.

 ## The *list* structure
 ### Nodes
 * `data` : field to store data of any type in the list (there can be any ammount of data fields of any type; particularly to this implementation, we have a list of `int`s)
 * if utilizing the self organizing strategy of frequency count, `counter` : counts how many times the data on that node was retrieved
 * `next` : the *link* between two consecutive nodes
 * any other information that can be useful given a specific situation

 ### List itself
 * `head` : pointer to the first node in the list (do not forget it, otherwise the list is lost)
 *  `size` : optional field containing, not surprisingly, the amount of nodes in the list
 * `tail` : see "Notes" below

### Operations
 The main operations available on a linked list are:
 * insert (adds a node in any position)
 * delete (retrieves data, by remotion, in any position)
 
 In addition to the operations to change the size of the list:
 * printing (prints, sequentially, all the elements in a list with some desired formatting)
 * set-like operations, such as union, intersection, and difference for lists of ints (but it is not ideal; hash maps would be better)
 * self-organizing strategies (such as move-to-front, transpose, and count)

 ### Notes
 * In this case, since we have a singly linked list, the operations insert and delete have time complexity $O(n)$ in the worst case and $O(1)$ in the best (insetion and deletion at the beginning of the list). To ease this problem (linear time is not *that* bad, but it isn't pretty either), we can:
    * separate the operations in "front" and "back" with a `tail` field (last node in the list)
    * use a doubly linked list; this way we can optimize, using the `size` field, how many nodes the operations would have to visit before inserting or removing another node
    
    Problems:
    * using a `tail` pointer will require more memory but will only turn into constant time operations at the head and tail of the list
    * a doubly linked list requires a lot more memory and does not *actually* reduce the time complexity from $O(n)$, it only makes the operations more efficient

    In any case we can also limit the operations to the first (and last, if there's some memory to spare) nodes of the list to avoid linear time (the price to pay is less flexibility)

 ### Fork and let me know in case you come up with a better and/or more general version of my implementation (or, of course, you've found any mistakes)
 I hope it helped you, though ; )
