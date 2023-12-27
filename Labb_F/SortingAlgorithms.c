#define _CRT_SECURE_NO_WARNINGS
#include "SortingAlgorithms.h"
#include "Statistics.h"
#include "Array.h"
#include <assert.h>
#include <string.h>

int isImplemented(SortingAlgorithm algorithm)
{
    switch (algorithm)
    {
//      case BUBBLE_SORT:
//      case INSERTION_SORT:
//      case SELECTION_SORT:
//      case QUICK_SORT:
//      case MERGE_SORT:
            return 1;
        default:
            return 0;
    }
}

/*Number of swaps in one and the same algorithm can be different depending
 on the implementation. Sometimes the data is already in the rigth place,
 then you can choose to test it and not make a swap (which gives an extra
 comparison), or you can choose to make a swap anyway (with oneself)
 without testing (which gives an extra swap). If you follow the algorithms
 we have worked through in class exactly, you will make a swap even when
 the element is in the correct position.
 When analysing the generated data (result.txt) you need to have this in
 mind.*/

/******************************************************************************************/
/*Here you will implement your algorithms*/

static void bubbleSort(ElementType* arrayToSort, unsigned int size, Statistics* statistics)
{
}

static void insertionSort(ElementType* arrayToSort, unsigned int size, Statistics* statistics)
{
}

static void selectionSort(ElementType* arrayToSort, unsigned int size, Statistics* statistics)
{
}

static void mergeSort(ElementType* arrayToSort, unsigned int size, Statistics* statistics)
{
}

static void quickSort(ElementType* arrayToSort, unsigned int size, Statistics* statistics)
{
}

/******************************************************************************************/


char* getAlgorithmName(SortingAlgorithm algorithm)
{
    /*Isn't the string we allocated local in the function?
      No, not in this case. String constants is a special case in C.*/
    switch (algorithm)
    {
        case BUBBLE_SORT:    return "  Bubble sort ";
        case SELECTION_SORT: return "Selection sort";
        case INSERTION_SORT: return "Insertion sort";
        case MERGE_SORT:     return "  Merge sort  ";
        case QUICK_SORT:     return "  Quick sort  ";
        default: assert(0 && "Invalid algorithm!"); return "";
    }
}

//Sorts 'arrayToSort' with 'algorithmToUse'. Statistics for all swaps and comparisons will go into *statistics
static void sortArray(ElementType* arrayToSort, unsigned int size, SortingAlgorithm algorithmToUse, Statistics* statistics)
{
    if(statistics != NULL)
        resetStatistics(statistics);

    switch (algorithmToUse)
    {
    case BUBBLE_SORT:     bubbleSort(arrayToSort, size, statistics); break;
    case SELECTION_SORT: selectionSort(arrayToSort, size, statistics); break;
    case INSERTION_SORT: insertionSort(arrayToSort, size, statistics); break;
    case MERGE_SORT:     mergeSort(arrayToSort, size, statistics); break;
    case QUICK_SORT:     quickSort(arrayToSort, size, statistics); break;
    default:
        assert(0 && "Invalid algorithm!");
    }
}

//Prepares arrays for sorting by allocating memory for them and initializing them.
static void prepareArrays(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], const unsigned int sizes[])
{
    assert(isImplemented(algorithm));

    int i;
    int totalArraySize;

    for (i = 0; i < NUMBER_OF_SIZES; i++)
    {
        totalArraySize = sizeof(ElementType)*sizes[i];
        sortingArray[i].arrayToSort = malloc(totalArraySize);
        memcpy(sortingArray[i].arrayToSort, arrays[i], totalArraySize);

        sortingArray[i].algorithm = algorithm;
        sortingArray[i].arraySize = sizes[i];
        resetStatistics(&sortingArray[i].statistics);
    }
}

static void sortArrays(SortingArray toBeSorted[])
{
    int i;
    for (i = 0; i < NUMBER_OF_SIZES; i++)
    {
        SortingArray* current = &toBeSorted[i];
        sortArray(current->arrayToSort, current->arraySize, current->algorithm, &current->statistics);
    
        if (!isSorted(current->arrayToSort, current->arraySize))
        {
            printf("Error! Algorithm %s has not sorted correctly!\n", getAlgorithmName(current->algorithm));
            printf("The result is: \n");
            printArray(current->arrayToSort, current->arraySize, stdout);
            assert(0); // Aktiveras alltid
        }
    }
}

void printResult(SortingArray sortedArrays[], FILE* file)
{
    assert(file != NULL);

    int i;
    for (i = 0; i < NUMBER_OF_SIZES; i++)
    {
        fprintf(file, "%4u element: ", sortedArrays[i].arraySize);
        printStatistics(&sortedArrays[i].statistics, file);
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}

void sortAndPrint(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], unsigned int sizes[], FILE* file)
{
    assert(file != NULL);

    prepareArrays(sortingArray, algorithm, arrays, sizes);
    sortArrays(sortingArray);
    printResult(sortingArray, file);
}

void freeArray(SortingArray sortingArray[])
{
    int i;
    for (i = 0; i < NUMBER_OF_SIZES; i++)
    {
        if (sortingArray[i].arrayToSort != NULL)
            free(sortingArray[i].arrayToSort);
        sortingArray[i].arrayToSort = NULL;
        sortingArray[i].arraySize = 0;
        resetStatistics(&sortingArray[i].statistics);
    }
}

