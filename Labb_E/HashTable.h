/* Lab assignment 4 - Data structures and algorithms */
/* Hashtable */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Bucket.h"
#define UNUSED 0 // Used to marked an element in the table that is not taken/assingned

/*Hashtable solving collisions with linear probing*/
typedef struct
{
    struct Bucket* table; //The hashtable is an array of buckets
    unsigned int size; //Size of hashtable
} HashTable;

/*Allocate memory for the table*/
HashTable createHashTable(unsigned int size);

/* 
 Places the pair/bucket {key,data} into the hashtable. If the key is already in
 the table, its value should be updated.
 Return number of collisions.
*/
unsigned int insertElement(HashTable* htable, const Key key, const Value value);

/* Removes bucket with data 'key' */
void deleteElement(HashTable* htable, const Key key);

/* 
 Returns a pointer to the value associated with 'key', or NULL if no such key
 exists in the table
 */
const Value* lookup(const HashTable* htable, const Key key);

/* Empty hashtable */
void freeHashTable(HashTable* htable);

/* Returns size of hashtablen */
unsigned int getSize(const HashTable* htable);

/* This function is so that you easily can visualise the table when testing */
void printHashTable(const HashTable* htable);

#endif

