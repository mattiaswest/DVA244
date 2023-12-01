#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "list.h"
#include <assert.h>

/*This function can be used to test specific functions.
 (Of course you may write your own menue function if you wish)*/
void menu(List head);

/*If the program runs flawlessly through this function, it works as specified (observe that the print outs must be testet manually).
  NOTE! Before all functions are implementet, the execution will get stuck in different asserts.*/
void testFunction(List head);


int main(void)
{
    List head = createEmptyList(); /*head should always point to the beginning of your list, if the list is empty it should contain NULL.*/
    
    /*Comment or uncomment depending on which of the functions you want to run.*/
    testFunction(head);
    //menu(head);
    
    
    return 0;
}

void menu(List head)
{
    int choice;
    Data data;
    int c; //Only used to clear the input buffert.
    
    do
    {
        printf("\n\n--------------MENU--------------\n"
               "1 - Print list\n"
               "2 - Add data first in list\n"
               "3 - Add data last in list\n"
               "4 - Remove first node in list\n"
               "5 - Remove last node in list\n"
               "6 - Remove data in list\n"
               "7 - Number of nodes in list\n"
               "8 - Is the list empty?\n"
               "9 - Get first element in list\n"
               "10 - Get last element in list\n"
               "11 - Search in list\n"
               "12 - Clear list (removes all nodes)\n"
               "13 - End program\n"
               "-----------------------------------\n"
               "Choice: ");
        
        scanf_s("%d", &choice);
        while((c = getchar()) != '\n' && c != EOF); //Clears the input buffert.
        
        switch(choice)
        {
            case 1: printf("List: ");
                    printList(head, stdout); break;
                
            case 2: printf("Data to add first: ");
                    scanf_s("%d%*c", &data);
                    addFirst(&head, data);
                    printf("List: ");
                    printList(head, stdout);
                    break;
                
            case 3: printf("Data to add last: ");
                    scanf_s("%d%*c", &data);
                    addLast(&head, data);
                    printf("List: ");
                    printList(head, stdout);
                    break;
                
            case 4: removeFirst(&head);
                    printf("First node removed\n");
                    printf("List: ");
                    printList(head, stdout);
                    break;
                
            case 5: removeLast(&head);
                    printf("Last node removed\n");
                    printf("List: ");
                    printList(head, stdout);
                    break;
                
            case 6: printf("Data to remove: ");
                    scanf_s("%d%*c", &data);
                    if(removeElement(&head, data) == 1)
                        printf("First occurance of node with data %d is removed\n", data);
                    else
                        printf("No node with data %d\n", data);
                    printf("List: ");
                    printList(head, stdout);
                    break;
                
            case 7: printf("Number of nodes in list: %d\n", numberOfNodesInList(head)); break;
                
            case 8: if(isEmpty(head) == 1)
                        printf("The list is empty\n");
                    else
                        printf("The list is not empty\n");
                    break;
                
            case 9: printf("First element: %d\n", getFirstElement(head)); break;
                
            case 10: printf("Last element: %d\n", getLastElement(head)); break;
                
            case 11: printf("Data to search for: ");
                scanf_s("%d", &data);
                if(search(head, data) == 1)
                {
                    printf("%d found in list ", data);
                    printList(head, stdout);
                }
                else
                {
                    printf("%d not found in list ", data);
                    printList(head, stdout);
                }
                break;
                
            case 12: clearList(&head); break;
                
            case 13: printf("\nEnding program"); break;
                
            default: printf("\nWrong input");
        }
    }while(choice != 13);
}

/*You need to manually test the function printList. Make sure to test it on both an existing list and an empty list. Also test that you can run clearList on an empty list without the program krashing.
*/
void testFunction(List head)
{
    printf("Starting test\n");
    
    assert(isEmpty(head)); //The list should be empty at first

    //Testar addFirst
    addFirst(&head, 6);
    addFirst(&head, 5);
    addFirst(&head, 4);
    addFirst(&head, 3);
    addFirst(&head, 2);
    assert(numberOfNodesInList(head) == 5);
    assert(getFirstElement(head) == 2);
    assert(getLastElement(head) == 6);
    //listan består nu av 2-3-4-5-6
    
    //Tests addLast on non-empty list
    addLast(&head, 7);
    addLast(&head, 8);
    assert(numberOfNodesInList(head) == 7);
    assert(getFirstElement(head) == 2);
    assert(getLastElement(head) == 8);
    //The list now contains 2-3-4-5-6-7-8

    //Tests removeFirst on non-empty list
    removeFirst(&head);
    assert(numberOfNodesInList(head) == 6);
    assert(getFirstElement(head) == 3);
    assert(getLastElement(head) == 8);
    //The list now contains 3-4-5-6-7-8
    
    //Tests removeLast on non-empty list
    removeLast(&head);
    assert(numberOfNodesInList(head) == 5);
    assert(getFirstElement(head) == 3);
    assert(getLastElement(head) == 7);
    //The list now contains 3-4-5-6-7
    
    //Tests to remove a node (existing) in the middle of a non-empty list.
    removeElement(&head, 5);
    assert(numberOfNodesInList(head) == 4);
    assert(getFirstElement(head) == 3);
    assert(getLastElement(head) == 7);
    //The list now contains 3-4-6-7
    
    //Tests to remove first node using removeElement in a non-empty list.
    removeElement(&head, 3);
    assert(numberOfNodesInList(head) == 3);
    assert(getFirstElement(head) == 4);
    assert(getLastElement(head) == 7);
    //The list now contains 4-6-7
    
    //Tests to remove last node using removeElement in a non-empty list.
    removeElement(&head, 7);
    assert(numberOfNodesInList(head) == 2);
    assert(getFirstElement(head) == 4);
    assert(getLastElement(head) == 6);
    //The list now contains 4-6
    
    //Tests to remove a non-existing node using removeElement in a non-empty list.
    assert(removeElement(&head, 5) == 0);
    assert(!isEmpty(head)); //The list should not be empty (4 and 6 remains in the list)
    
    //Tests to remove a single element using removeElement
    removeElement(&head, 6);
    assert(numberOfNodesInList(head) == 1);
    assert(getFirstElement(head) == 4);
    removeElement(&head, 4);
    assert(isEmpty(head)); //The list is now empty
    
    //Tests to add a node to an empty list
    addLast(&head, 5); //Tests to add last in an empty list
    assert(getFirstElement(head) == getLastElement(head));
    removeFirst(&head); //Remove last (only) element with removeFirst
    assert(isEmpty(head)); //Empty list again
    
    addFirst(&head, 5);
    assert(getFirstElement(head) == getLastElement(head));
    removeLast(&head); //Remove last (only) element with removeLast
    assert(isEmpty(head)); //Empty list again
    
    addFirst(&head, 5);
    addFirst(&head, 4);
    addFirst(&head, 3);
    addFirst(&head, 2);
    assert(numberOfNodesInList(head) == 4);
    assert(getFirstElement(head) == 2);
    assert(getLastElement(head) == 5);
    //The list now contains 2-3-4-5
    
    //Tests search (in the middle, first, last, non-existing data)
    assert(search(head, 4) == 1);
    assert(search(head, 2) == 1);
    assert(search(head, 5) == 1);
    assert(search(head, 7) == 0);
    
    //Tests to empty entire list
    clearList(&head);
    assert(isEmpty(head));
    
    assert(search(head, 5) == 0);//Tests to seach in empty list
    assert(removeElement(&head, 3) == 0); //Tests to remove from empty list
    assert(numberOfNodesInList(head) == 0); //Tests to count nodes in empty list
    
    printf("Congratulations!\nYour program passed the test\n");
}


