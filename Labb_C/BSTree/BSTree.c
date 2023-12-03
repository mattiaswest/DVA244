#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "BSTree.h"

static struct treeNode* createNode(int data)
{
    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else
    {
        printf("Error allocating memory!");
        return NULL;
    }
    return newNode;
}

void inorderTraversal(const BSTree tree, int* arrayBST, int* index)
{
    if (tree)
    {
        //store left subtree
        inorderTraversal(tree->left, arrayBST, index);
        //store current value
        arrayBST[(*index)++] = tree->data;
        //store right subtree
        inorderTraversal(tree->right, arrayBST, index);
    }
}

/* Return a dynamically allocated array containing the data in the tree sorted */
static int* writeSortedToArray(const BSTree tree)
{
    int len = numberOfNodes(tree);
    int* arrayBST = (int*)malloc(len * sizeof(int));
    if (arrayBST != NULL)
    {
        int index = 0;
        inorderTraversal(tree, arrayBST, &index);
    }


   /* Create a dynamic array with the correct size.
    
      Write data sorted (smallest to larges) from the tree to the aray.
      - perhaps you might need a helper function here */
   
   return arrayBST; //Replace with correct return value
}

/* Build a sorted, balanced tree from the array */
static void buildTreeSortedFromArray(BSTree* tree, const int arr[], int size)
{
    if (size > 1)
    {
        int mid = (size / 2);
        struct treeNode* root = createNode(arr[mid]);
        *tree = root;

        buildTreeSortedFromArray(&((*tree)->left), arr, mid);
        buildTreeSortedFromArray(&((*tree)->right), arr[mid], size - mid);
    }
}


/* Implementation of the tree - the functions in the interface */

/* Create an empty tree - this function is completed. */
BSTree emptyTree(void)
{
   return NULL;
}


int isEmpty(const BSTree tree)
{
   return (tree == NULL);
}


/* Post-condition: data is in the tree, sorted correctly */
void insertSorted(BSTree* tree, int data)
{
    //recursive solution
    if (*tree == NULL)
    {
        *tree = createNode(data);
        return;
    }

    if (data < (*tree)->data)
    {
        insertSorted(&((*tree)->left), data);
    }
    else
    {
        insertSorted(&((*tree)->right), data);
    }
    //iterative solution
    /*if (*tree == NULL)
    {
        *tree = createNode(data);
        return;
    }
    struct treeNode* current = *tree;

    while (1)
    {
        if (data < current->data)
        {
            if (current->left == NULL)
            {
                current->left = createNode(data);
                return;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = createNode(data);
                return;
            }
            current = current->right;
        }
    }*/
}

/*
  When calling: use stdio as second parameter to print to the conole/screen
  It is enought that you implement the LR-orders
 */
void printPreorder(const BSTree tree, FILE *textfile)
{
    if (tree)
    {
        fprintf(textfile, "%d ", tree->data);
        printPreorder(tree->left, textfile);
        printPreorder(tree->right, textfile);
    }
}

void printInorder(const BSTree tree, FILE *textfile)
{
    if (tree) 
    {
        printInorder(tree->left, textfile);
        fprintf(textfile, "%d ", tree->data);
        printInorder(tree->right, textfile);
    }
}

void printPostorder(const BSTree tree, FILE *textfile)
{
    if (tree)
    {
        printPostorder(tree->left, textfile);
        printPostorder(tree->right, textfile);
        fprintf(textfile, "%d ", tree->data);
    }
}


int find(const BSTree tree, int data)
{
   // Remember that the tree may be empty here
   return -1; //Replace with correct return value
}


void removeElement(BSTree* tree, int data)
{
   /* No data should/can be removed from an empty tree.
    Three cases: Leaf (no children), One child (left or right), Two children
    
    Don't forget to free the dynamic memory for the removed node.
    */
}

int numberOfNodes(const BSTree tree)
{
    if (isEmpty(tree))
        return 0;
    else
        return 1 + numberOfNodes(tree->left) + numberOfNodes(tree->right);
}

int depth(const BSTree tree)
{
   return -1; //Replace with correct return value
}


int minDepth(const BSTree tree)
{
    //See math.h for useful functions
   return -1; //Replace with correct return value
}

/*
 Postcondition:
    - tree has the same number of nodes as previously
    - the depth of the tree is the same as mindepth of the tree.
 */
void balanceTree(BSTree* tree)
{
    int* arr = writeSortedToArray(*tree);
    freeTree(tree);
    buildTreeSortedFromArray(tree, arr, sizeof(arr));
    free(arr);
    arr = NULL;
   /* Suggested algorithm:
      - write the tree sorted to a dynamic array (writeSortedToArray)
      - empty tree (freeTree)
      - build tree recursively from array (buildTreeSortedFromArray)
      - free memory for the dynamic array
    */
}

/*Postcondition: the tree is empty*/
void freeTree(BSTree* tree)
{
    if (*tree == NULL)
        return;

    freeTree(&((*tree)->left));
    freeTree(&((*tree)->right));

    free(*tree);
    *tree = NULL;
}



