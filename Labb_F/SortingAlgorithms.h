/* Lab assignment 5 - Data structures and algorithms */
/* Sorting algorithms */

#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdlib.h>
#include <stdio.h>
#include "Statistics.h"

#define NUMBER_OF_SIZES 3 //How many different sizes one want to sort

typedef enum { BUBBLE_SORT, SELECTION_SORT, INSERTION_SORT, MERGE_SORT, QUICK_SORT, SORTING_ALGORITHMS } SortingAlgorithm;
typedef unsigned int ElementType;

//Contains all information needed for sorting an array and giving statistics
typedef struct
{
    SortingAlgorithm algorithm;
    ElementType* arrayToSort;
    unsigned int arraySize;
    Statistics statistics;
} SortingArray;

//Returns the name of an algorithm
char* getAlgorithmName(SortingAlgorithm algorithm);

//Prints statistics for sorting
void sortAndPrint(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], unsigned int sizes[], FILE* file);

//Returns 1 if algorithm is implemented, 0 if not
int isImplemented(SortingAlgorithm algorithm);

//Free memory for an array of arrays
void freeArray(SortingArray array[]);
#endif


