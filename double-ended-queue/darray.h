/**
  Declarations for a sequence of strings stored in an array that swells and
  shrinks by a factor of 2 as needed.
**/


#ifndef DARRAY_H
#define DARRAY_H


typedef struct dynamic_array_deque {

   char** data; // The array of pointers to char, that is, the array of string.

   int size;  // The sequence size.
   int first; // The index of the first element in the sequence.

   int capacity; // The array size.
   int min_cap;  // The current minimum array size.
   int initial_cap;  // The absolute minimum array size (that is, the darray will never have a capacity less than this field).

} darray;


/**
 * @brief Allocates a darray and, in this case, the array of pointers to strings. 
   Sets the initial state of the darray properly.
 
 * @param capacity the desired initial capacity for the array (it is also the minimum array size)
 * @return The address of a new darray.  On failure it returns NULL.
 */
darray* dalloc(int capacity);


/**
 * @brief Releases all the strings in a darray and the darray itself.

 * @param A dynamic array to be deallocated
 */
void free_darray(darray* A);


/**
 * @brief Adds a copy of a string to the end of the sequence.
   If the array is full, it tries to double its capacity and then adds the
   string.
   When resizing the array is not possible, it will not
   push.

 * @param A the dynamic array receiving data
 * @param string new data to be stored
 * @return 1, on success. 0, on failure.
 */
int da_push(darray* A, char* string);


/**
 * @brief Removes a string from the end of the sequence and return a pointer to it.
   If the array is 1/4 full, this function halves its capacity and then removes
   the string.  The capacity will never be smaller than the initial capacity.

 * @param A dynamic array from which data is being retrievied
 * @return Address of the data copied from the former last element. Or NULL if A is null.
 */
char* da_pop(darray* A);


/**
 * @brief Adds a copy of a string to the beginning of the sequence.
   If the array is full, it tries to double its capacity and then adds the
   string.
   When resizing the array is not possible, it will not
   inject.

 * @param A the dynamic array receiving data
 * @param string new data to be stored 
 * @return 1, on success. 0, on failure.
 */
int da_inject(darray* A, char* string);


/**
 * @brief Removes a string from the beginning of the sequence and return a pointer to it.
   If the array is 1/4 full, this function halves its capacity and then removes
   the string.  The capacity will never be smaller than the initial capacity.

 * @param A dynamic array from which data is being retrievied
 * @return Address of the data copied from the former first element. Or NULL if A is null.
 */
char* da_eject(darray* A);


/**
 * @return Pointer to the first string in the sequence. Or NULL if A is null.
 */
char* da_first(darray* A);


/**
 * @return A pointer to the last string in the sequence. Or NULL if A is null.
 */
char* da_last(darray* A);


/**
 * @return The size of the sequence (if 0, then yes, it is empty). Or -1 if A is null.
 */
int da_is_empty(darray* A);


#endif