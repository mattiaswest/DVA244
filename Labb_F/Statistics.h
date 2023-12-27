#ifndef STATISTICS_H
#define STATISTICS_H
#include <stdio.h>
#include "Array.h"

/*
 This file contains functions to keep track of how many swaps and
 comparisons are made in the sorting algorithms
*/


struct statistics
{
    unsigned int comparisons;
    unsigned int swaps;
};

typedef struct statistics Statistics;

//Resets the statistics
void resetStatistics(Statistics* statistics);

//Writes the statistics to file
void printStatistics(const Statistics* statistics, FILE* file);

//Comparison operations with statistics. Remember; ElementType is unsigned int here
int lessThan(ElementType element1, ElementType element2, Statistics* statistics); //True if element1 < element2
int greaterThan(ElementType element1, ElementType element2, Statistics* statistics); //True if element1 > element2
int equalTo(ElementType element1, ElementType element2, Statistics* statistics); //True if om element1 == element2
int notEqualTo(ElementType element1, ElementType element2, Statistics* statistics); //True if element1 != element2
int lessThanOrEqualTo(ElementType element1, ElementType element2, Statistics* statistics); //True if element1 <= element2
int greaterThanOrEqualTo(ElementType element1, ElementType element2, Statistics* statistics); //True if element >= element2

//Swaps element 1 and element 2, with statistics.
void swapElements(ElementType* element1, ElementType* element2, Statistics* statistics);

#endif

