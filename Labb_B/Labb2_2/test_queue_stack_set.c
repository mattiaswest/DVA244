/*
 The queue, stack and set are to be implemented as linked list.
 You will find the different interfaces in queue.h, stack.h and set.h
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include "queue.h"
#include "stack.h"
#include "set.h"

/*Make call in main to the menu you want to run.*/
void menuQueue(void);
void menuStack(void);
void menuSet(void);

/*Run each of these test functions to validate that you ADTs work as expected.
*/
void testFunctionQueue(void);
void testFunctionStack(void);
void testFunctionSet(void);

int main(void)
{

    menuStack();
    //testFunctionSet();
    printf("test");
    menuSet();
    return 0;
}


void menuQueue(void)
{
    int choice;
    int c;
    Data data;
    Queue myQueue = initializeQueue();
    
    do
    {
        printf("\n\n---------MENU QUEUE--------\n"
               "1 - Add to queue (enqueue)\n"
               "2 - Remove from queue (dequeue)\n"
               "3 - Peek at front in queue\n"
               "4 - Is queue empty?\n"
               "5 - Quit queue menu\n"
               "--------------------------------\n"
               "Choice: ");
        scanf_s("%d", &choice);
        while((c = getchar()) != '\n' && c != EOF);
        
        switch(choice)
        {
            case 1: printf("Data to add: ");
                    scanf_s("%d", &data);
                    enqueue(&myQueue, data);
                    printf("Queue: ");
                    printQueue(myQueue, stdout);
                    break;
            case 2: dequeue(&myQueue);
                    printf("The first element in queue is removed\n");
                    printf("Queue: ");
                    printQueue(myQueue, stdout);
                    break;
            case 3: printf("First element in queue: %d\n", peekQueue(myQueue));
                    printf("Queue: ");
                    printQueue(myQueue, stdout);
                    break;
            case 4: if(queueIsEmpty(myQueue) == 1)
                        printf("Queue is empty\n");
                    else
                        printf("Queue is not empty\n");
                    break;
            case 5: printf("Ending menu\n"); break;
            default: printf("Wrong input\n");
        }
        
    }while(choice != 5);
    
}

void menuStack()
{
    int choice;
    int c;
    Data data;
    Stack myStack = initializeStack();
    
    do
    {
        printf("\n\n---------MENU STACK--------\n"
               "1 - Add to stack (push)\n"
               "2 - Remove from stack (pop)\n"
               "3 - Peek at top in stack\n"
               "4 - Is stack empty?\n"
               "5 - Quit stack menu\n"
               "--------------------------------\n"
               "Choice: ");
        scanf_s("%d", &choice);
        while((c = getchar()) != '\n' && c != EOF);
        
        switch(choice)
        {
            case 1: printf("Data to push: ");
                    scanf_s("%d", &data);
                    push(&myStack, data);
                    printf("Stack: ");
                    printStack(myStack, stdout);
                    break;
            case 2: pop(&myStack);
                    printf("The top in stack is removed\n");
                    printf("Stack: ");
                    printStack(myStack, stdout);
                    break;
            case 3: printf("Top element in stack: %d\n", peekStack(myStack));
                    printf("Stack: ");
                    printStack(myStack, stdout);
                    break;
            case 4: if(stackIsEmpty(myStack) == 1)
                    printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
                break;
            case 5: printf("Ending menu\n"); break;
            default: printf("Wrong input\n");
        }
        
    }while(choice != 5);
}

void menuSet()
{
    int choice;
    int c;
    Data data;
    Set mySet = initializeSet();
    
    do
    {
        printf("\n\n---------MENU SET----------\n"
               "1 - Add to set\n"
               "2 - Remove from set\n"
               "3 - Is data in set?\n"
               "4 - Quit set menu\n"
               "--------------------------------\n"
               "Choice: ");
        scanf_s("%d", &choice);
        while((c = getchar()) != '\n' && c != EOF);
        
        switch(choice)
        {
            case 1: printf("Data to add: ");
                    scanf_s("%d", &data);
                    addToSet(&mySet, data);
                    printf("Set: ");
                    printSet(mySet, stdout);
                    break;
            case 2: printf("Data to remove: ");
                    scanf_s("%d", &data);
                    removeFromSet(&mySet, data);
                    printf("Data %d is removed from set\n", data);
                    printf("Set: ");
                    printSet(mySet, stdout);
                    break;
            case 3: printf("Data to search for: ");
                    scanf_s("%d", &data);
                    if(isInSet(mySet, data) == 1)
                        printf("%d found in set\n", data);
                    else
                        printf("%d not found in set", data);
                    printf("Set: ");
                    printSet(mySet, stdout);
                    break;
            case 4: printf("Ending menu\n"); break;
            default: printf("Wrong input\n");
        }
        
    }while(choice != 5);
}

void testFunctionQueue()
{
    Queue myQueue = initializeQueue();
    
    assert(queueIsEmpty(myQueue));
    enqueue(&myQueue, 5);
    enqueue(&myQueue, 7);
    enqueue(&myQueue, 3);
    assert(!queueIsEmpty(myQueue));
    assert(peekQueue(myQueue) == 5);
    dequeue(&myQueue);
    assert(peekQueue(myQueue) == 7);
    dequeue(&myQueue);
    assert(peekQueue(myQueue) == 3);
    dequeue(&myQueue);
    assert(queueIsEmpty(myQueue));
    enqueue(&myQueue, 8);
    assert(peekQueue(myQueue) == 8);

    printf("Congratulations, your Queue passed the test program\n\n");
}

void testFunctionStack()
{
    Stack myStack = initializeStack();
    
    assert(stackIsEmpty(myStack));
    push(&myStack, 5);
    push(&myStack, 2);
    push(&myStack, 9);
    assert(!stackIsEmpty(myStack));
    assert(peekStack(myStack) == 9);
    pop(&myStack);
    assert(peekStack(myStack) == 2);
    pop(&myStack);
    assert(peekStack(myStack) == 5);
    push(&myStack, 4);
    assert(peekStack(myStack) == 4);
    pop(&myStack);
    pop(&myStack);
    assert(stackIsEmpty(myStack));
    push(&myStack, 8);
    assert(peekStack(myStack) == 8);
    
    printf("Congratulations, your Stack passed the test program\n\n");
}

void testFunctionSet()
{
    Set mySet = initializeSet();
    
    assert(isEmpty(mySet));
    addToSet(&mySet, 4);
    addToSet(&mySet, 1);
    addToSet(&mySet, 8);
    assert(!isEmpty(mySet));
    assert(isInSet(mySet, 1));
    assert(isInSet(mySet, 4));
    assert(isInSet(mySet, 8));
    addToSet(&mySet, 1);
    
    int occurances = 0;
    for(struct node *current = mySet; current != NULL; current = current->next)
        if(current->data == 1)
            occurances++;
    assert(occurances == 1);
    
    removeFromSet(&mySet, 8);
    assert(!isInSet(mySet, 8));
    removeFromSet(&mySet, 1);
    removeFromSet(&mySet, 4);
    assert(isEmpty(mySet));
    addToSet(&mySet, 3);
    assert(isInSet(mySet, 3));
    
    printf("Congratulations, your Set passed the test program\n\n");
}

