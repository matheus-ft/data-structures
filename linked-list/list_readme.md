# Linked Lists

Each one of this directory's folders contains a general implementation (plus *direct* examples) of some type of linked list:
* [Singly linked list](singly-linked)
* [Doubly linked list](doubly-linked) (not finished yet)
* [Circular linked list](circular-list) (not finished yet)

Although different, the general ideia for each of them is the same.



 ## The general *list* structure

 ### Nodes

 #### Mandatory info

 * `data` : field to store data of any type in the list (there can be any amount of "data" fields of any type)
 * `next` : the *link* between a node and the next one on the list (see "Notes" below)

 #### Optional info

 * `previous` : pointer to the *previous* node on the list (see "Notes" below)
 * `counter` : field that stores how many times the data on that node was accessed (useful when utilizing the self organizing strategy of frequency *count*)
 * any other information that can be useful given a specific situation (e.g. `color`)

 ### List itself (capsule)

 #### Mandatory info

 * `head` : pointer to the first node in the list (do not forget it!)

 #### Optional info

 *  `size` : field containing, not surprisingly, the amount of nodes in the list (also frequently called `lenght`)
 * `tail` : pointer to the last node in the list (see "Notes" below)



### Operations

 The main operations available on a linked list are:
 * insert (adds a node in any position)
 * delete (retrieves data, by remotion, in any position)
 
 In addition to the operations to change the size of the list:
 * printing (prints all the elements in a list with some desired formatting or order)
 * set operations, such as union, intersection, and difference for lists of `int`s (see "Notes" below)
 * self-organizing strategies, such as **m**ove-**t**o-**f**ront, *transpose*, and *count*

### Notes

 * `previous` :
    * **singly** linked lists do not have this field in their nodes
    * **doubly** linked lists are *characterized* for having this field in their nodes
 * `next` field for the last node, two approaches:
    * `NULL` : null pointer to identify the end of the list
    * `head` : pointer to the head; in this case we call the list **circular** (which can be either singly ou doubly linked)
 
 * [Hash maps](hash-map) are (way) better suited to represent sets, but it is still possible to use lists for simple application 

 * Although the concept of a list as a *sequence* of data points is useful by itself (as a substitution, with pros and cons, for *arrays*), linked lists can also be used to implement other data structures. Some, let's say, *indirect* and simple applications would be:
    * stacks
    * queues



 ### Fork and let me know in case you come up with a better and/or more general version of my implementation (or, of course, you've found any mistakes)

 I hope it helped you, though ; )

## To do

- [ ] doubly-linked list
- [ ] circular linked list
- [ ] queues
- [ ] stacks
