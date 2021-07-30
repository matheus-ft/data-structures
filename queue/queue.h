/// Queue structure
struct array_queue {
    int* data;  // array storing the desired data
    int first;  // index of the queue's first element in the buffer 
    int size;  // amount of data points stored
    int capacity;  // maximum amount of data points permitted
}; 
typedef struct array_queue queue;


/**
 * @brief Allocates memory and starts an empty queue.
 * 
 * @param capacity the maximum number of data points the queue will be allowed to store in its array
 * @return The address of the queue created.
 */
queue* queate(int capacity);


/**
 * @brief Adds a new data point in the queue.
 * If the buffer is full, the old data is not overwritten.
 * 
 * @param q queue receiving data
 * @param key the data being stored
 * @return 1, on success. 0, on failure.
 */
int enqueue(queue* q, int key);


/**
 * @brief Deletes the first data point in the queue by invalidating
 * its position with the `first` and `size` fields.
 * 
 * @return The value removed.
 */
int dequeue(queue* q);

/**
 * @brief Releases a queue and its array.
 */
void free_queue(queue* q);

/**
 * @brief Prints all the data points in queue sequentially and separated by spaces.
 * 
 * @param q queue being printed
 */
void printq(queue* q);
