#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include "BSTree.h"
#include <stdio.h>

/*
 Function to test your tree.
 Note! preorder, inorder and postorder must be tested manually via the menu
*/
void testTree(BSTree tree);

/*
 Menu that can be used to test individual functions.
 Of course, you may write your own menu if you wish.
*/
void menuTree(BSTree tree);


int main(void)
{
    BSTree tree = emptyTree();
    
    testTree(tree);
    //menuTree(tree);
    
    return 0;
}


void testTree(BSTree tree)
{
    printf("Starting test\n");
    
    //The tree should be empty at the start
    assert(isEmpty(tree));
    //Tests on empty tree
    assert(!find(tree, 7)); //search in empty tree
    removeElement(&tree, 7); //remove from empty tree - program should not krash
    assert(depth(tree) == 0 && minDepth(tree) == 0);
    balanceTree(&tree); //balance empty tree - program should not krash
    
    
    //Insert seven elements into the tree
    int arr[7] = {5,10,1,3,7,19,16}, i;
    for (i = 0; i < 7; i++)
    {
        insertSorted(&tree, arr[i]);
    }
    
    //Verify that all elements are in the tree
    for (i = 0; i < 7; i++)
    {
        assert(find(tree, arr[i]));
    }
    
    assert(numberOfNodes(tree) == 7);
    assert(depth(tree) == 4); //With insertion in this order, the depth is 4
    assert(minDepth(tree) == 3); //With seven nodes, min depth is 3
    
    removeElement(&tree, 7); //Remove a leaf
    removeElement(&tree, 19); //Remove an element with one child
    removeElement(&tree, 5); //Remove an element with two cildren
    assert(numberOfNodes(tree) == 4); //Tree nodes have been removed
    //Verify that the elements have been removed
    assert(!find(tree, 7));
    assert(!find(tree, 19));
    assert(!find(tree, 5));
    
    //Remove remaining nodes in tree
    removeElement(&tree, 10);
    removeElement(&tree, 1);
    removeElement(&tree, 3);
    removeElement(&tree, 16);
    
    assert(isEmpty(tree));
    
    //Insert into empty tree
    insertSorted(&tree, 10);
    assert(find(tree, 10));
    
    //Add nine elements so that the tree becomes unbalanced
    for (i = 0; i < 9; i++)
        insertSorted(&tree, i+20);
    
    assert(numberOfNodes(tree) == 10);
    
    //Verify that the tree is not balanced
    assert(depth(tree) != minDepth(tree));
    
    balanceTree(&tree);
    assert(numberOfNodes(tree) == 10); //Verify that the number of nodes are the same
    assert(depth(tree) == minDepth(tree)); //Verify that the tree is balanced
    
    //Empty the tree and verify that it is empty
    freeTree(&tree);
    assert(isEmpty(tree));
    assert(numberOfNodes(tree) == 0);
    assert(depth(tree) == 0);
    
    //Remove node with two children
    int arr2[14] = {3, 2, 1, 9, 5, 4, 7, 6, 8, 15, 13, 11, 14, 18};
    i = 0;
    for(int i = 0; i < 14; i++)
    {
        insertSorted(&tree, arr2[i]);
    }
    removeElement(&tree, 9);
    
    /*Remove commentations on row 106-116 if you when removing a node with two children choose the smallest in right sub-tree as replacement (11 will replace 9 in this test), compare your printouts of the tree with the printouts showing what the tree should look like. If needed, you can alter the spacing in the printouts so that the formatting looks ok in your console.
    */
    /*
    printf("\nPreorder\nYour tree:    ");
    printPreorder(tree, stdout);
    printf("\nCorrect tree: 3 2 1 11 5 4 7 6 8 15 13 14 18");
    printf("\nInorder\nYour tree:    ");
    printInorder(tree, stdout);
    printf("\nCorrect tree: 1 2 3 4 5 6 7 8 11 13 14 15 18");
    printf("\nPostorder\nYour tree:    ");
    printPostorder(tree, stdout);
    printf("\nCorrect tree: 1 2 4 6 8 7 5 14 13 18 15 11 3");
    */
    
    
    /*Remove commentations on row 120-130 if you when removing a node with two children choose the
     largest in left sub-tree as replacement (8 will replace 9 in this test), compare your
     printouts of the tree with the printouts showing what the tree should look like. If needed, you
     can alter the spacing in the printouts so that the formatting looks ok in your console.
    */
    /*
    printf("\nPreorder\nYour tree:    ");
    printPreorder(tree, stdout);
    printf("\nCorrect tree: 3 2 1 8 5 4 7 6 15 13 11 14 18");
    printf("\nInorder\nYour tree:    ");
    printInorder(tree, stdout);
    printf("\nCorrect tree: 1 2 3 4 5 6 7 8 11 13 14 15 18");
    printf("\nPostorder\nYour tree:    ");
    printPostorder(tree, stdout);
    printf("\nCorrect tree: 1 2 4 6 7 5 11 14 13 18 15 8 3");
    */

    printf("\n\nCongratulations, your program passet the test\n");
}


void menuTree(BSTree tree)
{
    int choice, data;
    char c;
    
    do
    {
        printf("\n\n--------------MENU--------------\n"
               "1 - Add to tree\n"
               "2 - Remove from tree\n"
               "3 - Print in preorder\n"
               "4 - Print in inorder\n"
               "5 - Print in postorder\n"
               "6 - Number of nodes in tree\n"
               "7 - Depth of tree (actual and theoretical)\n"
               "8 - Is the tree empty?\n"
               "9 - Balance tree\n"
               "10 - Search in tree\n"
               "11 - Free tree\n"
               "12 - End program\n"
               "-----------------------------------\n"
               "Choice: ");
        
        scanf_s("%d", &choice);
        while((c = getchar()) != '\n' && c != EOF); //clears the input buffert
        
        switch(choice)
        {
            case 1: printf("Data to add: ");
                scanf_s("%d", &data);
                insertSorted(&tree, data);
                printf("Tree: ");
                printPreorder(tree, stdout);
                break;
            case 2: printf("Data to remove: ");
                scanf_s("%d", &data);
                removeElement(&tree, data);
                printf("Tree: ");
                printPreorder(tree, stdout);
                break;
            case 3: printf("Tree in preorder: ");
                printPreorder(tree, stdout);
                break;
            case 4: printf("Tree in inorder: ");
                printInorder(tree, stdout);
                break;
            case 5: printf("Tree in postorder: ");
                printPostorder(tree, stdout);
                break;
            case 6: printf("Number of nodes in tree: %d", numberOfNodes(tree));
                break;
            case 7: printf("Actual depth of tree: %d\n", depth(tree));
                printf("Theoretical minimum depth of tree: %d\n", minDepth(tree));
                break;
            case 8: if (isEmpty(tree) == 1)
                printf("The tree is empty\n");
            else
                printf("The tree is not empty\n");
                
                break;
            case 9: balanceTree(&tree);
                break;
            case 10: printf("Data to search for: ");
                scanf_s("%d", &data);
                if (find(tree, data) == 1)
                    printf("%d was found in the tree", data);
                else
                    printf("%d was not found in the tree", data);
                
                break;
            case 11: freeTree(&tree);
                break;
            case 12: printf("Ending tree menu\n"); break;
            default: printf("Wrong input\n");
        }
        
    }while(choice != 12);
    
    freeTree(&tree);
    
}




