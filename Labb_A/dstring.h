/* Lab assignment 1 - Data structures and algorithms */
/* Dstring ADT */

#ifndef DSTRING_H
#define DSTRING_H
#include <stdio.h>

typedef char* DString;

/* Returnes a string containing the same string as 'str'.
   The returned string is dynamically allocated (i.e on the heap). */
DString dstring_initialize(const char* str);

/* Concatenates the original string with source.
   Returnes 0 if allocating enough memory fails, otherwise 1 is returned.
 */
int dstring_concatenate(DString* destination, DString source);

/* Shoertens *destination so that it contains at most 'truncatedLength' characters.
   If 'truncatedLength' is longer than the length of the string, nothing happens.
 */
void dstring_truncate(DString* destination, unsigned int truncatedLength);

/* Writes the string to a text-file.
   The text file is already assumed to be opened, and still be opened after the function call.
 */
void dstring_print(DString stringToPrint, FILE* textfile);

/* Free up the allocated memory for the dynamic string and assigns the string (*stringToDelete) the value NULL */
void dstring_delete(DString* stringToDelete);

int sum(int x);

#endif

