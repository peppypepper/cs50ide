// similar to stack but its FIFO, first in first out, just like a regular line at the bank
// 2 operations like stack: enqueue and dequeue, both take pointers and values you want to add
// enqueue: add a new element to the end of the queue
// dequeue: remove the oldest element from the front of the queue
// array or linked list implementation

// array based implementation
typedef struct _queue
{
    Value array[capacity]; // no dynamism
    int front; // need to keep track of the front of the queue
    int size; // need to keep track of the size of the queue, number of elements it contains
}

queue q; //declare
enqueue(&q, 28); //add 28 to position 0, size 1, update front value = 0
enqueue(&q, 33); // add 33 to position 1, size 2, update front value = 0
dequeue(&q); // remove 28 from the queue, size 1, update front value = 1
enqueue(&q, 40); // add 40 to position 2, update size 2, update front value = 2
