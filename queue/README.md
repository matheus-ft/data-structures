# Queue

There are two main ways to implement a queue:
* array (circular buffer)
* linked list (sinlgy-linked with `tail` pointer, or doubly-linked and circular)

In this implementation we utiize a circular buffer (array of `int`s).

However in [BST](binary-search-tree) it is needed to store some information about our tree in such a way that the *first* node saved is also the *first* one printed, that is *first in, first out*. This is, as we shall see bellow, the organizing method that characterizes the queue structure. So a good example of a queue application is, in fact, in the `bst_height_path` and `bst_print_height` functions.


## Queue structure

### General info

* `data` / `key` : the data being queued (array or field in a node)
* `first` / `head` : reference to the queue's first element (index in the buffer or pointer to node)
* `size` : number of keys still in queue

### Circular buffer additions
* `capacity` : maximum amount of data points permitted

### Linked list additions

#### Singly-linked
* `tail` : pointer to the last element in the queue

#### Doubly-linked
* The `next` field of the last node points to the head and head's `previous` points to the last node in the list


### Operations
* queate (creates a queue)
* enqueue (adds new data to que queue)
* dequeue (removes a data point)
* printq (prints the data queued)
* free_queue (deallocates memory for the queue)

### Notes
The `enqueue` and `dequeue` functions are what makes a queue a queue. Wheter it is an array or a list, insertion and deletion always occur in a specific way: **first in, first out**. 

*FIFO* means that the first data to be enqueued will also be the first dequeued.

So, in order to make this possible, insertion always happens in the back of the array/list and deletion in the front.

Picture an *actual* queue in front of some store on a black friday... Okay, maybe not on black friday, just some regular queue in the movie theater. The first person in line is (or at least should be) the first one to get inside the theater.

The same is true for the data points/keys in our `queue` data structure! The data that arrives last is retrieved last; naturally we insert them at the back of the line, and remove at the front.

---

### Fork and let me know in case you come up with a better and/or more general version of my implementation (or, of course, you've found any mistakes)

 I hope it helped you, though ; )
