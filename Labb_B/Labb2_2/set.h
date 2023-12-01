/* Lab assignment 2.2 - Data structures and algorithms */
/* Set */

#ifndef SET_H
#define SET_H
#include "list.h"   // Your list is included

/*
 The set are to be implemented as a linked list.
 Du should use your list functions in the implementation of the set.
 You should nor re-write the functions or copy-paste the code.
 NOTE! you should never change anything in the interface.
 Alla functions are to be implemented.
*/


typedef List Set;    // The word 'Set' will be your list-type

/* Create a new, empty set */
Set initializeSet(void);

/*
 Add an element to the set.
 Remember that all elements in the set must be unique.
*/
void addToSet(Set* set, const Data element);

/* Remove 'element' from the set*/
void removeFromSet(Set* set, const Data element);

/*Return 1 if the element is in the set, 0 if it is not. */
int isInSet(const Set set, const Data element);

/* Print the entire set - this function is only for testing */
void printSet(const Set set, FILE *textfile);


#endif


