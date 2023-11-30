#define _CRT_SECURE_NO_WARNINGS 1
#include "dstring.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>


DString dstring_initialize(const char* str)
{
   // Precondition: str is not NULL - test with assert
    assert(str != NULL);

   /* Tip:
      - Allocate (e.g., with malloc) enough memory to fit str. Don't forget that there must be room for '\0' as well.
        Don't forget to test so that the allocation is successfull before you start working with the memory.
      - It is allowed to use build-in string functions (e.g., strcpy())
      - Remember to use assert()
    */
    int len = strlen(str) + 1;

    char* temp = (char*)malloc(len * sizeof(char));
    if (temp != NULL)
    {
        strcpy(temp, str);
        return temp;
    }
    else
    {
        printf("Error allocating memory!");
        free(temp);
        return NULL;
    }
   // Postcondition: The return value contains the same string as str - does not need to be testet.

   //return NULL; // Replace this row. It is only there now so that the program can compile.
}

int dstring_concatenate(DString* destination, DString source)
{
   // Precondition: destination is not NULL
    assert(destination != NULL);
   // Precondition: source is not NULL
    assert(source != NULL);

   /* Tip:
      - Note that *destination already is a dynamically allocated string.
      - Note that you will need to allocate more memory to fit the longer string. The memory that *destination points to needs to be extended (realloc), how large should the "new" memory be?
        Don't forget that '\0' must fit in the string.
        When allocating dynamic memory, you must always test so that the allocation is successfull before you start working with the memory.
      - It is allowed to use built-in string functions (such as strcat()).
   */
    int len = strlen(*destination) + strlen(source) + 1;

    DString temp = (DString)realloc(*destination, sizeof(char) * len);
    if (temp != NULL)
    {
        *destination = temp;
        strcat(*destination, source);
        return 1;
    }
    else
    {
        printf("Error allocating memory!");
        free(temp);
        return 0;
    }

   // Postcondition: *destination contains the old string combined with source - does not need to be testet.
   //return -1; // Replace thiw row. Right now it's only there for the program to compile. What should be returned?
}

void dstring_truncate(DString* destination, unsigned int truncatedLength)
{
   // Precondition: destination is not NULL, *destination is not NULL
    assert(destination != NULL);
    assert(*destination != NULL);
   // the length (truncateLength) may not be negative
    assert(truncatedLength >= 0);
   // Preconditions should be testet with asserts
  

   /* Tip:
      - Use realloc to free the redundant memory.
        (have a look at what realloc does)
      - Don't forget '\0'.
      - What happens if truncateLength is longer than the string?
   */
    DString temp = (DString)realloc(*destination, sizeof(char) * (truncatedLength + 1));
    if (temp != NULL)
    {
        if (temp != NULL)
        {
            *destination = temp;
            (*destination)[truncatedLength] = '\0';
        }
        else
        {
            printf("Error allocating memory!");
            free(temp);
        }
    }

   // Postcondition: *destination is not longer than  'truncatedLength' - does not need to be testet.
}

void dstring_print(DString str, FILE* textfile)
{
   // Precondition: textfile is not NULL - must be testet before you try to work with the file.
    assert(textfile != NULL);
   /* Note that the file pointer is already connected to the file before the functions is called.*/

   /* Don't close the file (file pointer), the file should work as normal after the function call */
    printf("\n\nWriting to file...\n\n");
    fprintf(textfile, "%s\0", str);
}

void dstring_delete(DString* stringToDelete)
{
   // Precondition: stringToDelete is not NULL
    assert(*stringToDelete != NULL);
    free(*stringToDelete);
    *stringToDelete = NULL;
   // Postcondition: *stringToDelete are NULL and the memory is freed. - does not need to be testet.
}

int sum(int x)
{
    int temp = 1;
    printf("sum(%d) anropas", x);
    if (x == 1)
    {
        printf("sum(%d) returnerar %d", x, temp);
        return x;
    }
    else if (x < 0)
        return 0;
    else
    {
        temp = x + sum(x - 1);
        printf("sum(%d) returnerar %d", x, temp);
        return temp;

    }

}

int result = sum(5);
printf("%d", result);