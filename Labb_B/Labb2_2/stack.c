#include "stack.h"
#include <assert.h>

/*
 Here it is important to re-use code you have already written for the
 linked list. Re-using don't mean to copy the code or writing the code
 again, you re-use code by calling the function with the functionality you
 want to re-use.
*/

/* This function is completed */
Stack initializeStack(void)
{
    return createEmptyList();
}

int stackIsEmpty(const Stack stack)
{
    return isEmpty(stack);
}

/* Postcondition: 'data' on the top of the stack */
void push(Stack* stack, const Data data)
{
    addFirst(stack, data);
    assert(getFirstElement(*stack) == data);
}

/* Precondition: The stack is not empty */
void pop(Stack* stack)
{
    assert(!stackIsEmpty(stack));
    removeFirst(stack);
}

/* Precondition: The stack is not empty */
Data peekStack(const Stack stack)
{
    assert(!stackIsEmpty(stack));
    return getFirstElement(stack);  //Replace with correct return value
}

/*Tip: There may be a good idea to also note where the queue starts.*/
void printStack(const Stack stack, FILE* textFile)
{
    printList(stack, textFile);
}


