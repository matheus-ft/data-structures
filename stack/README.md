# Stack

There are two main ways to implement a stack:

* (dynamic) [array](array-stack)
* [linked list](list-stack) (sinlgy-linked with `head` pointer)

Each of them in the folders they link to.

## Stack structure

### General info

* `data` / `key` : the data being queued (array or field in a node)
* `last` / `head` : reference to the stack's top element (index in the darray or pointer to node)
* `size` / `height` : number of "keys" still in the stack

### Dynamic array additions

* `capacity` : *current* maximum amount of data points permitted

### Operations

* salloc (allocates memory for a stack)
* push (inserts new data to the stack)
* pop (retrieves the top element)
* print (prints the keys in the stack)
* free (releases a stack)

### Notes

The `push` and `pop` functions are what makes a stack a stack. Wheter it is an array or a list, insertion and deletion always occur in a specific way: **last in, first out**.

*LIFO* means that the first data to be added to the stack will be the last one to be retrieved.

So, in order to make this possible, insertion and deletion always happen in the front of the array/list.

Picture an *actual* stack of, let's say, plates. The first plated to be grabbed was the last one to be stacked.

The same is true for the data points/keys in our `stack`! The data that arrives last is retrieved first; naturally we insert and remove them at the front of the "pile".

---

### Fork and let me know in case you come up with a better and/or more general version of my implementation (or, of course, you've found any mistakes)

 I hope it helped you, though ; )
