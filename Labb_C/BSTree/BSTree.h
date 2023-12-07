/* Lab assignment 3 - Data structures and algorithms */
/* Binary search tree */

#ifndef BSTREE_H
#define BSTREE_H

#include <stdio.h>

struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

typedef struct treeNode* BSTree;

//inorder traversal on the tree
void inorderTraversal(const BSTree node, int* arrayBST, int* index);

/* Create a new tree */
BSTree emptyTree(void);

/* Return 1 if the tree is empty, otherwise 0 */
int isEmpty(const BSTree tree);

/* Places 'data' sorted in the tree */
void insertSorted(BSTree* tree, int data);

/* Print functions*/
void printPreorder(const BSTree tree, FILE *textfile);
void printInorder(const BSTree tree, FILE *textfile);
void printPostorder(const BSTree tree, FILE *textfile);

/* Return 1 if 'data' is in the tree, 0 if not. */
int find(const BSTree tree, int data);

struct treeNode* findMinNode(struct treeNode* node);

/* Remove 'data' from the tree, if it is in the tree */
void removeElement(BSTree* tree, int data);

struct treeNode* removeElementRecursive(struct treeNode* root, int data);

/* Return the number of nodes in tree */
int numberOfNodes(const BSTree tree);

/* Return the depth/high of tree */
int depth(const BSTree tree);

/* Return the calculated minimum depth of tree */
int minDepth(const BSTree tree);

/* Balance tree, so that depth(tree) == minDepth(tree) */
void balanceTree(BSTree* tree);

/* Empty tree and free dynamic memory for all nodes in the tree */
void freeTree(BSTree* tree);

#endif

