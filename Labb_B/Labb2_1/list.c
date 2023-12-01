#include "list.h"
#include <stdlib.h>
#include <assert.h>

/*It is allowed to add your own helper functions. However, the already existing functiondeclarations (function heads) are not allowed to be changed.
 */

 /*
  Helper function to add.
  Allocate memory for a new node. If the allocation is successful, initialize data and pointer (pointer is initialized to NULL).
  The new node (or NULL) are returned.
 */
static struct node* createListNode(const Data data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Failed to allocate new memory");
		return NULL;
	}
	newNode->data = data;
	newNode->previous = NULL;
	newNode->next = NULL;
	return newNode;
}

/*Returns an empty list - function is already completed*/
List createEmptyList(void)
{
	return NULL;
}


/*Is the list empty?
  Return 1 if empty, 0 is not.*/
int isEmpty(const List list)
{
	return (list == NULL); //Replace with correct return value
}

/*
 Add a node first in the list.
 Postcondition: The new data is first in the list (test with assert)
 */
void addFirst(List* list, const Data data)
{
	struct node* newNode = createListNode(data);
	if (newNode != NULL) {
		//if the list is empty
		if (*list == NULL) {
			*list = newNode;
		}
		//if the list is NOT empty
		else {
			newNode->next = *list;
			(*list)->previous = newNode;
			*list = newNode;
		}
	}
	//Remember that the list may be empty when a new node is added.
}

/*
 Add a node last in the list.
 Tip: When you find the right position you can use the function addFirst to insert the node.
 */
void addLast(List* list, const Data data)
{
	struct node* newNode = createListNode(data);
	if (*list == NULL) {
		*list = newNode;
	}
	else {
		struct node* temp = *list;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->previous = temp;
	}
}

//Precondition: the list is not empty (test with assert).
void removeFirst(List* list)
{
	assert(*list != NULL);
	if ((*list)->next != NULL)
	{
		*list = (*list)->next;
		free((*list)->previous);
		(*list)->previous = NULL;
	}
	else
	{
		free(*list);
		*list = NULL;
	}
}

/*
 Remove the last node in the list.
 Precondition: The list is not empty (test with assert).
 */
void removeLast(List* list)
{
	if (*list != NULL) {
		//Handle case of a single element. In this case the head pointer should be updated to NULL
		if ((*list)->next == NULL) {
			free(*list);
			*list = NULL;
		}
		else {
			struct node* temp = *list;
			//find second to last element
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
		}
	}
}
/*
 Remove data from list (first occurence).
 Return 1 if data is found, 0 if not found.
 Tip: when you find the correct node, you can use one of the above functions to remove the node.
 */
int removeElement(List* list, const Data data)
{
	if (*list == NULL)
		return 0;
	else if ((*list)->data == data)
	{
		removeFirst(list);
		return 1;
	}
	else {
		struct node* temp = *list;
		while (temp != NULL) {
			if (temp->data == data) {
				temp->previous->next = temp->next;
				if (temp->next != NULL) {
					temp->next->previous = temp->previous;
				}
			return 1;  // Data found and removed
			}

			temp = temp->next;
		}
		free(temp);  // Free the memory of the node
	}
	return 0;  // Data not found in the list
}



/*
 Is the data in the list?Finns data i listan?
 Return 1 if data is found, 0 if not found.
 Remember that the list may be empty.
*/
int search(const List list, const Data data)
{
	struct node* temp = list;
	while (temp != NULL) {
		if (temp->data == data)
			return 1;
		temp = temp->next;
	}
	return 0;
}

/*Return number of nodes in list.*/
int numberOfNodesInList(const List list)
{
	if (list != NULL)
	{
		int nodes = 1;
		struct node* temp = list;
		while (temp->next != NULL) {
			nodes++;
			temp = temp->next;
		}
		return nodes;
	}
	else
		return 0;
}

/*
 Remove all nodes from the list.
 Don't forget to free the dynamic memory.
 Postcondition: The list is empty, *list is NULL (test with assert).
*/
void clearList(List* list)
{
	struct node* temp = *list;
	struct node* nextNode;

	while (temp != NULL) {
		nextNode = temp->next;
		free(temp);
		temp = nextNode;
	}
	*list = NULL;
}

/*
 Print the list.
 In the function call, stdout should be given as argument 2 (to print to the screen).
 Use fprintf to the the print out.
 This kind of print out function is more general since it can be used both to write to the console but also to external files.
*/
void printList(const List list, FILE* textfile)
{
	struct node* temp = list;

	while (temp != NULL) {
		fprintf(textfile, "%d", temp->data);
		temp = temp->next;
	}
	fprintf(textfile, "\n");
}

/*
 Return the first data in the list.
 Precondition: The list is not empty (tesst with assert).
*/
Data getFirstElement(const List list)
{
	return list->data;
}

/*
 Return last data in the list
 Precondition: The list is not empty (test with assert).
*/
Data getLastElement(const List list)
{
	if (list != NULL) {
		struct node* temp = list;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		return temp->data; //Replace with correct return value
	}
}