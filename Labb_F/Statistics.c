#include "Statistics.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void resetStatistics(Statistics* statistics)
{
    assert(statistics != NULL);

    statistics->comparisons = 0;
    statistics->swaps = 0;
}

void printStatistics(const Statistics* statistics, FILE* file)
{
    assert(statistics != NULL);
    assert(file != NULL);

    fprintf(file, "%5u comparisons, %5u swaps", statistics->comparisons, statistics->swaps);
}


int lessThan(ElementType element1, ElementType element2, Statistics* statistics)
{
    assert(statistics != NULL);
    statistics->comparisons++;
    return element1 < element2;
}

int greaterThan(ElementType element1, ElementType element2, Statistics* statistics)
{
    assert(statistics != NULL);
    statistics->comparisons++;
    return element1 > element2;
}

int equalTo(ElementType element1, ElementType element2, Statistics* statistics)
{
    assert(statistics != NULL);
    statistics->comparisons++;
    return element1 == element2;
}

int notEqualTo(ElementType element1, ElementType element2, Statistics* statistics)
{
    assert(statistics != NULL);
    statistics->comparisons++;
    return element1 != element2;
}

int lessThanOrEqualTo(ElementType element1, ElementType element2, Statistics* statistics)
{
    assert(statistics != NULL);
    statistics->comparisons++;
    return element1 <= element2;
}

int greaterThanOrEqualTo(ElementType element1, ElementType element2, Statistics* statistics)
{
    assert(statistics != NULL);
    statistics->comparisons++;
    return element1 >= element2;
}


void swapElements(ElementType* element1, ElementType* element2, Statistics* statistics)
{
    assert(element1 != NULL && element2 != NULL);

    ElementType temp = *element1;
    *element1 = *element2;
    *element2 = temp;

    if (statistics)
        statistics->swaps++;
}

