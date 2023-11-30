#include <assert.h>
#include <string.h>

#include "dstring.h"

/* This program tests the functionality of the ADT Dstring. */
int main(void)
{
    DString str1, str2;
    str1 = dstring_initialize("Department of ");
    str2 = dstring_initialize("Redundancy ");
    int resultat = dstring_concatenate(&str1, str2); /* Concatenates str1 and str2, and puts the resulting string in str1. str1 now contains "Department of Redundancy" */
    assert(resultat == 1); //allocation was successful.

    /* If any of these asserts fails something is wrong with your implementation, use the debugger to find out what. */

    assert(str1 != NULL);
    assert(str2 != NULL);
    assert(strlen(str2) == 11);
    assert(strlen(str1) == 25); // The concatenated string should have length 25

    /* "Department of Redundancy Department" should be printed on the screen (output)
       stdout is a textfil that represents the console */

    dstring_print(str1, stdout);    // Prints "Department of Redundancy"
    dstring_truncate(&str1, 10);    // Shortens str1 so that it only contains the first 10 characters in the string ("Department")
    assert(strlen(str1) == 10);
    assert(strlen(str2) == 11);
    dstring_print(str1, stdout);    // Prints "Department"

    /* Free up the dynamic memory for the two strings */
    dstring_delete(&str1);
    dstring_delete(&str2);

    /* Make sure the strings don't point to non-allocated memory */
    assert(str1 == NULL);
    assert(str2 == NULL);
    return 0;
}

