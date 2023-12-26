#define _CRT_SECURE_NO_WARNINGS // Needed in Visual Studio for some functions
#include "HashTable.h"
#include "Bucket.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

static int hash(Key key, int tablesize)
{
    return key%tablesize;
}

static int linearProbe(const HashTable* htable, Key key, unsigned int *col)
{
    int index = hash(key, htable->size);
    for (unsigned int i = 0; i < htable->size; i++)
    {
        if (htable->table[(index + i) % htable->size].key == 0 || htable->table[(index+i)%htable->size].key == key)
            return (index + i) % htable->size;
        (*col)++;
    }
    return -1;
}

HashTable createHashTable(unsigned int size)
{
    struct Bucket *temp = (struct Bucket*)calloc(size, sizeof(struct Bucket));
    if (temp != NULL)
    {
        HashTable htable = { temp, size };
        return htable;
    }
    printf("Error allocating memory");
    free(temp);
    temp = NULL;
    return;
}

unsigned int insertElement(HashTable* htable, const Key key, const Value value)
{
    int col = 0;
    int index = linearProbe(htable, key, &col);
    if (index != -1)
    {
        htable->table[index].key = key;
        htable->table[index].value = value;
        //printf("Index: %d Key: %d Value.pnr %d\n", index, htable->table[index].key, htable->table[index].value.personalNumber);
    }
    else
        printf("The table is full!\n");

    return col;
}

/*Postcondition: no element with key is in the table (use loopup to verify)*/
void deleteElement(HashTable* htable, const Key key)
{
    int col = 0;
    int index = linearProbe(htable, key, &key);
    if (index != -1)
    {
        htable->table[index].key = NULL;
        for (unsigned int i = 0; i < htable->size; i++)
        {
            int tempKey = htable->table[(index+i)%htable->size].key;
            Value tempVal = htable->table[(index + i)%htable->size].value;
            htable->table[(index+i)%htable->size].key = 0;
            unsigned int col = insertElement(htable, tempKey, tempVal);
            printf("Key: %d\n", htable->table[(index + i) % htable->size].key);
        }
    }
}

const Value* lookup(const HashTable* htable, const Key key)
{
    int col;
    int index = linearProbe(htable, key, &col);
    if (index != -1 && htable->table[index].key != 0)
        return &(htable->table[index].value);
    else
        return NULL;
}

/*Postcondition: hashtable have size 0*/
void freeHashTable(HashTable* htable)
{

}


unsigned int getSize(const HashTable* htable)
{
    if (htable != NULL)
        return(htable->size);
    //Getting the number of elements that have a key
    /*
    unsigned int col = 0;
    if (htable != NULL)
    {
        for (int i = 0; i < htable->size; i++)
        {
            if (htable->table[i].key != 0)
                col++;
        }
        return col;
    }
    */
    else
    {
        printf("The table is empty.");
        return 0;
    }

}


void printHashTable(const HashTable* htable)
{
    for (unsigned int i = 0; i < htable->size; i++)
    {
        if (htable->table[i].key != 0)
            printPerson(&(htable->table[i].value), i);
    }
}

