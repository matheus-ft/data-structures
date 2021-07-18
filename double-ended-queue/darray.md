# Double-ended Queue
 This is an implementation of a double-ended queue (*deque*) with an array of **strings** as the data stored.
 To be more precise, we represent our deque using a *dynamic array* (that's why `darray`).

 ## The *deque* structure
 To effectivelly build and operate a deque we need to be able to retrieve some information about our dynamic array:
 * `data` : the data it stores
 * `size`: the ammount of positions occupied in the array
 * if there is any logical sequence in the data stored, `first`: the index of the first element of such sequence 
 * `capacity` : the total number of elements the array can currently handle
 * `min_cap` : the minimum size we let, by our terms, the array to have
 * `initial_cap` : altough not needed, this implementations limits the minimum array size by its size on definition

### Operations
 The main operations available on a deque are:
 * push (appends data to the end of the sequence)
 * pop (retrieves, by remotion, data from the end of the sequence)
 * inject (inserts data in the beggining of the sequence)
 * eject (retrieves, by remotion, data from the beggining of the sequence)
 
 It should be noted that this names specifically might be switched depending on the language, programmer, or book author.

 In addition to those, let's say, more needful operations, we have implemented a few more:
 * first (finds the data in the first position of the sequence)
 * last (finds the data in the last position of the sequence)
 * is_empty (verifies if the sequence is empty or not)

 ### Notes
 * The implementation takes in consideration the case where the type of data is string, but the code gets much simpler if we use numbers (int, float, etc.) or much harder if we use a complex data structure (e.g. a multidimensional array/matrix of linked lists)
 * The default laws for `capacity` updates is set as:
    * When **full**, the array **doubles** its capacity
    * When only **25% full**, the array **halves** its capacity

    But it should not be difficult to see where the code should differ in case it is needed for the laws to change.
 * The `min_cap` field is updated every time the `capacity` field is supposed to be altered, but, as the name should imply, `initial_cap` (the *actual* minimum capacity) **never** changes in **this** implementation and also limits the halving of `min_cap`.

 ### Fork and let me know in case you come up with a better and/or more general version of my implementation (or, of course, you've found any mistakes)
 I hope it helped you, though ; )
