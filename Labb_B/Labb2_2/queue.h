/* Lab assignment 2.2 - Data structures and algorithms */
/* Queue */

#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"    // Your list are included

/*
 The Queue are to be implemented as a linked list.
 Du should use your list functions in the implementation of the queue.
 You should nor re-write the functions or copy-paste the code.
 NOTE! you should never change anything in the interface.
 Alla functions are to be implemented.
*/


typedef List Queue;  // The word 'Queue' will be your list-type


/* Create a new, empty queue */
Queue initializeQueue(void);

/* Return 1 if the queue is empty, 0 if not empty. */
int queueIsEmpty(const Queue queue);

/* Place a new element last in the queue. */
void enqueue(Queue* queue, const Data data);

/* Remove the first element in the queue. */
void dequeue(Queue* queue);

/* Return the first element in the queue. */
Data peekQueue(const Queue queue);

/* Print the entire queue - This function is onlyl for testing */
void printQueue(const Queue queue, FILE *textfile);


#endif

