/* Lab assignment 2.2 - Data structures and algorithms */
/* Stack */

#ifndef STACK_H
#define STACK_H
#include "list.h"        // Your list is implemented

/*
 The stack are to be implemented as a linked list.
 Du should use your list functions in the implementation of the stack.
 You should nor re-write the functions or copy-paste the code.
 NOTE! you should never change anything in the interface.
 Alla functions are to be implemented.
*/

 
typedef List Stack;     // The word 'Stack' will be your list type


/* Create a new, empty stack */
Stack initializeStack(void);

/* Return 1 if the stack is empty, 0 if not. */
int stackIsEmpty(const Stack stack);

/* Place an element on top of the stack */
void push(Stack* pStack, const Data element);

/* Remove the top element from the stack */
void pop(Stack* pStack);

/* Return the top element on the stack */
Data peekStack(const Stack stack);

/* Print the entire stack - This function is only for testing */
void printStack(const Stack stack, FILE *textfile);


#endif

