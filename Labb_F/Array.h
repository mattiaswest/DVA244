#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <stdio.h>

#define SEED 245802 // This will give us the same unsorted array each time, so that we can make comparisons. The number can be changed if one wants another sequence och data to be randomly generated.
typedef unsigned int ElementType;

//Descides if the array is sorted or not
int isSorted(const ElementType* array, size_t size);

/*
 Creates arrayes of given size and rule for sorting (unsorted, forward or
 backwards).
 Note that these arrays are dynamically allocated and that they needs to be freed when not needed anymore.
*/
ElementType* createForwardSortedArray(size_t size);
ElementType* createBackwardSortedArray(size_t size);
ElementType* createUnsortedArray(size_t size);

//Write an array to file
void printArray(const ElementType* array, size_t size, FILE* file);



#endif

