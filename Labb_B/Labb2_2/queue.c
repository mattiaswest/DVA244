#include "queue.h"
#include <assert.h>

/*
 Here it is important to re-use code you have already written for the linked list. Re-using don't mean to copy the code or writing the code again, you re-use code by calling the function with the functionality you want to re-use.
*/

/*This function is complete*/
Queue initializeQueue(void)
{
    return NULL;
}

int queueIsEmpty(const Queue queue)
{
    return isEmpty(queue);    // Replce with correct return value.
}

/*Postcondition: data is added last in queue */
void enqueue(Queue* queue, const Data data)
{
    addLast(*queue, data);
    assert(getLastElement(*queue) == data);
   //Tip: To add last in a queue implemented as a linked list, is the same as adding first or last in a linked list.
}

/* Precondition: Queue is not empty */
void dequeue(Queue* queue)
{
    assert(!queueIsEmpty(*queue));
    removeFirst(*queue);
    //Tip: Removing from a queue implemented as a linked list, is the same as removing last or first in a linked list.
}

/* Precondition: Queue is not empty */
Data peekQueue(const Queue queue)
{
    assert(!queueIsEmpty(queue));
    return getFirstElement(queue);    // Replce with correct return value.
}


/*Tip: There may be a good idea to also note where the queue starts.*/
void printQueue(const Queue queue, FILE *textfile)
{
    printList(queue, textfile);
}



