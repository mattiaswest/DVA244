#include "Array.h"
#include "Statistics.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int isSorted(const ElementType* array, size_t size)
{
    assert(array != NULL);

    unsigned int i;

    for (i = 1; i < size; i++)
        if (array[i] < array[i - 1]) //if two elements are in the wrong order, the elements are not sorted
            return 0;
    return 1;
}

ElementType* createForwardSortedArray(size_t size)
{
    ElementType* array = malloc(sizeof(ElementType)*size);
    unsigned int i;

    if (array != NULL)
    {
        for (i = 0; i < size; i++)
            array[i] = i;

        assert(isSorted(array, size));
    }
    return array;
}

ElementType* createBackwardSortedArray(size_t size)
{
    ElementType* array = malloc(sizeof(ElementType)*size);
    unsigned int i;

    if (array != NULL)
    {
        for (i = 0; i < size; i++)
            array[i] = (unsigned int) size - i;

        assert(!isSorted(array, size));
    }
    return array;
}

ElementType* createUnsortedArray(size_t size)
{
    srand(SEED); //Makes sure that each unsorted array is the same

    ElementType* array = createForwardSortedArray(size); //Start with a sorted array
    unsigned int randomIndex1, randomIndex2;
    unsigned int i;

    if (array != NULL)
    {
        //Randomly swap places
        for (i = 0; i < size; i++)
        {
            //Choose two random index to swap
            randomIndex1 = rand() % size;
            randomIndex2 = rand() % size;
            swapElements(&array[randomIndex1], &array[randomIndex2], NULL);
        }
    }
    return array;
}

void printArray(const ElementType* array, size_t size, FILE* file)
{
    assert(array != NULL);

    unsigned int i;
    printf("[");
    for (i = 0; i < size; i++)
        fprintf(file, "%u ", array[i]);
    printf("]\n");
}

