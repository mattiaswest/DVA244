/* Lab assignment 2.1 - Data structures and algorithms */
/* Linked list */

#ifndef LIST_H
#define LIST_H
#include <stdio.h>


                                                                  
/*
 Descide if you want to make a single-linked list our a double-linked list.
 Choose the corresponding struct definition below.
 Regardless of your choice, the function declarations will look the same.

 NOTE!
 You should not change anything in the interface.
 All founctions are to be implmented (in list.c).
*/


typedef int Data;


/*Choose this struct definition if you want to implement a double-linked list.*/

struct node
{
    Data data;
    struct node *next;
    struct node *previous;
};


/*Choose this struct definition if you want to implement a single-linked list.*/
/*
 struct node
{
    Data data;
    struct node *next;
};
*/
 

//The list is representet by a node pointer.
typedef struct node *List;

//Return an empty list
List createEmptyList(void);


//Is the list empty?
//Return 1 if the list is empty, otherwise 0.
int isEmpty(const List list);

//Add a node first in the list
void addFirst(List *list, const Data data);

//Add a node last in the list
void addLast(List *list, const Data data);

//Remove first node in the list
void removeFirst(List *list);

//Remove last node in the list
void removeLast(List *list);

//Remove data from the list (first occurence), return 0 if the data is not in the list, otherwise 1.
int removeElement(List *list, const Data data);

//Search for a data in the list. Return 1 if found, otherwise 0.
int search(const List list, const Data data);

//Return  number of nodes in the list.
int numberOfNodesInList(const List list);

//Empty the list / remove all data (nodes) from the list.
void clearList(List *list);

//Print the list
void printList(const List list, FILE *textfile);

//Return first data in the list (without removing it)
Data getFirstElement(const List list);

//Return last data in the list (without removing it)
Data getLastElement(const List list);


#endif

