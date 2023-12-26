#define _CRT_SECURE_NO_WARNINGS // Used in Visual Studio to allow surtain functions
#include "HashTable.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "Person.h"
#define SIZE 50
#define LOOPS 1000

/*Types to handle a dynamic number of tables - used in compareHashTableSizes*/
typedef struct{
    HashTable table;
    unsigned int tableSize;
    unsigned int collissions;
}Table;

typedef struct{
    Table *Tables;
    unsigned int noOfTables;
}HTables;
/**********************************************/
static void fillArrayWithPersons(Person *list);
static unsigned int addPersonsToTable(HashTable *htable, Person *persons);
static unsigned int getTableSize(int nr);

/*Test functions*/
void compareHashTableSizes(void);/*Choose how many different hashtable-sizes you want to compare. It places the same data in different hashtables with the different sizes you have choosen and prints number of collisions with each of the sizes.*/
void test(void); /*Tests all functions and different cases for the hashtabel*/
void menu(void); /*A menu to test your functions with manual data och random data*/


int main(void)
{
//    menu();
//    test();
    compareHashTableSizes();

    return 0;
}

/*********************************************************************************************************/
/*Functions for menu, tests and to compare collisions for different sized hashtables*/
/*********************************************************************************************************/

static void fillArrayWithPersons(Person *list)
{
    for(int i = 0; i < SIZE; i++)
        list[i] = getRandomPerson();
}

static unsigned int addPersonsToTable(HashTable *htable, Person *persons)
{
    unsigned int collissions = 0;
    for(int i = 0; i < SIZE; i++)
    {
        collissions+=insertElement(htable, persons[i].personalNumber, persons[i]);
        assert(lookup(htable, persons[i].personalNumber)->personalNumber == persons[i].personalNumber);
    }
    return collissions;
}

static unsigned int getTableSize(int nr)
{
    unsigned int tableSize;

    do
    {
        printf("Size of hashtable %d (at least %d): ", nr, SIZE);
        scanf_s("%u", &tableSize); //It is prefered to let the size be a prime number
    } while (tableSize < SIZE);

    return tableSize;
}

/*Compares hashtables of different sizes with the same data*/
void compareHashTableSizes(void)
{
    int noOfTables;
    HTables myTables;
    int i, j;
    
    printf("How many hashtables do you want to compare: ");
    scanf_s("%d", &noOfTables);
    if(noOfTables <= 0)
    {
        printf("No tables selected, shutting down\n");
        return;
    }
    
    myTables.Tables = (Table *)calloc(noOfTables, sizeof(Table));
    if(myTables.Tables == NULL)
    {
        printf("Error creating tables, shutting down\n");
        return;
    }
    
    for(j = 0; j < noOfTables; j++)
    {
        myTables.Tables[j].tableSize = getTableSize(j+1);
        assert(myTables.Tables[j].tableSize >= SIZE);
        myTables.Tables[j].collissions = 0;
    }
    
    Person listOfPersons[SIZE];
    
    for(i = 0; i < LOOPS; i++)
    {
        fillArrayWithPersons(listOfPersons);
        
        for(j = 0; j < noOfTables; j++)
        {
            myTables.Tables[j].table = createHashTable(myTables.Tables[j].tableSize);
            myTables.Tables[j].collissions += addPersonsToTable(&(myTables.Tables[j].table), listOfPersons);
            freeHashTable(&(myTables.Tables[j].table));
        }
    }
    
    for(j = 0; j < noOfTables; j++)
        printf("Table %d (size %d) - number of collisions: %d\n", j+1, myTables.Tables[j].tableSize, myTables.Tables[j].collissions/LOOPS);
    
    
    free(myTables.Tables);
}




/*Tests all functions, and different cases for the hashtable. Du can whenever you want to add a call to the function printHashTable(&htable); to see what the table looks like.*/
void test(void)
{
    HashTable htable = createHashTable(10); /*A better size for the amount 9 is 13. However, this function (test) is only for testing that the hashtables' functions are correctly implemented, and %10 is easier than %13 for most to calculate. .*/
    int size = getSize(&htable);
    assert(getSize(&htable) == 10);
    Person arrPersons[9] = {{931014, 81.0, "Tobias"},
                            {881011, 75.0, "Alva"},
                            {600704, 114.0, "Bengt"},
                            {790408, 93.5, "Nora"},
                            {900610, 71.3, "Aram"},
                            {510929, 83.6, "Jasmin"},
                            {740318, 63.0, "Emma"},
                            {801204, 93.4, "Ibrahim"},
                            {830709, 53.9, "Sara"}};
    Person aPerson;
    const Value *aPersonPointer;
    int i, collisions = 0;
    
    //Add a few persons and verify that they are in the right positions.
    for(i = 0; i < 9; i++)
    {
        collisions+= insertElement(&htable, arrPersons[i].personalNumber, arrPersons[i]);
    }
    printHashTable(&htable);
    assert(htable.table[0].key == 900610);
    assert(htable.table[1].key == 881011);
    assert(htable.table[2].key == 740318);
    assert(htable.table[3].key == 830709);
    assert(htable.table[4].key == 931014);
    assert(htable.table[5].key == 600704);
    assert(htable.table[6].key == 801204);
    assert(htable.table[7].key == UNUSED);
    assert(htable.table[8].key == 790408);
    assert(htable.table[9].key == 510929);
    assert(collisions == 11);
    
    //Add a duplicate key - value should be updated
    strcpy(aPerson.name, "Anna");
    aPerson.personalNumber = 881011;
    aPerson.weight = 65.2;
    insertElement(&htable, 881011,aPerson);
    printf("\n\n_____________________\n\n");
    printHashTable(&htable);
    assert(htable.table[1].value.weight == aPerson.weight);
    assert(strcmp(htable.table[1].value.name, aPerson.name) == 0);
    
    //Searches for a person in the right location and one placed elsewhere due to collisions.
    aPersonPointer = lookup(&htable, 790408);
    assert(strcmp(aPersonPointer->name, "Nora") == 0);
    aPersonPointer = lookup(&htable, 740318);
    assert(strcmp(aPersonPointer->name, "Emma") == 0);
    
    //Searches for a person not in the list
    assert(lookup(&htable, 600705) == NULL);
    

    //Remove a person with no buckets direclty after
    deleteElement(&htable, 801204);
    assert(lookup(&htable, 801204) == NULL);
    assert(htable.table[6].key == UNUSED);
    
    //Remove a person with buckets directly after
    deleteElement(&htable, 790408);
    assert(lookup(&htable, 790408) == NULL);
    assert(htable.table[0].key == 900610);
    assert(htable.table[1].key == 881011);
    assert(htable.table[2].key == 830709);
    assert(htable.table[3].key == UNUSED);
    assert(htable.table[4].key == 931014);
    assert(htable.table[5].key == 600704);
    assert(htable.table[6].key == UNUSED);
    assert(htable.table[7].key == UNUSED);
    assert(htable.table[8].key == 740318);
    assert(htable.table[9].key == 510929);
    
    //Empty the entire table
    deleteElement(&htable, 900610);
    deleteElement(&htable, 881011);
    deleteElement(&htable, 830709);
    deleteElement(&htable, 931014);
    deleteElement(&htable, 600704);
    deleteElement(&htable, 740318);
    deleteElement(&htable, 510929);
    assert(htable.table[0].key == UNUSED);
    assert(htable.table[1].key == UNUSED);
    assert(htable.table[2].key == UNUSED);
    assert(htable.table[3].key == UNUSED);
    assert(htable.table[4].key == UNUSED);
    assert(htable.table[5].key == UNUSED);
    assert(htable.table[6].key == UNUSED);
    assert(htable.table[7].key == UNUSED);
    assert(htable.table[8].key == UNUSED);
    assert(htable.table[9].key == UNUSED);
    
    //Add some buckets
    insertElement(&htable, arrPersons[0].personalNumber, arrPersons[0]);
    assert(htable.table[4].key == 931014);
    insertElement(&htable, arrPersons[1].personalNumber, arrPersons[1]);
    assert(htable.table[1].key == 881011);
    insertElement(&htable, arrPersons[2].personalNumber, arrPersons[2]);
    assert(htable.table[5].key == 600704);
    insertElement(&htable, arrPersons[3].personalNumber, arrPersons[3]);
    assert(htable.table[8].key == 790408);
    
    //Empty and free
    freeHashTable(&htable);
    assert(htable.size == 0);
    assert(htable.table == NULL);
    
    
    printf("Your hashtable passed the test\n\n");
}

void menu(void)
{
    int choice, subChoice, size, pNr;
    unsigned int collisions = 0;
    HashTable htable;
    htable.table = NULL;
    Person aPerson;
    const Value *aPersonPointer;
    do{
        printf("\n----------Menu Hashtable----------\n1 - Create Hashtable\n2 - Insert element\n3 - Print hashtable\n4 - Search for element\n5 - Delete element\n6 - Get size of hashtable\n7 - Free hashtable\n8 - Exit\n");
        scanf_s("%d", &choice);
        
        switch (choice)
        {
            case 1:
                size = getTableSize(0);
                htable = createHashTable(size);
                break;
            case 2:
                printf("1 - Random data\n2 - Manual data\n");
                scanf_s("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        aPerson = getRandomPerson();
                        printf("Random\n%d: %s: %f\n", aPerson.personalNumber, aPerson.name, aPerson.weight);
                        break;
                    case 2:
                        while(getchar()!='\n');
                        printf("Enter name: ");
                        fgets(aPerson.name, 28, stdin);
                        aPerson.name[strlen(aPerson.name)-1] = '\0'; /*Remove the enter-character that fgets reads from the keyboard*/
                        printf("Enter weight: ");
                        scanf_s("%f", &aPerson.weight);
                        printf("Enter personal number (YYMMDD): ");
                        scanf_s("%d", &aPerson.personalNumber);
                        break;
                    default: printf("Invalid input\n");
                        break;
                }
                
                if((collisions = insertElement(&htable, aPerson.personalNumber, aPerson)) >= 1)
                    printf("Insertion created %d collisions\n", collisions);
                break;
            case 3:
                printHashTable(&htable);
                break;
            case 4:
                printf("Enter personal number (YYMMDD) to search for: ");
                scanf_s("%d", &pNr);
                aPersonPointer = lookup(&htable, pNr);
                if(aPersonPointer == NULL)
                    printf("%d could not be found in the table\n", pNr);
                else
                    printf("Found\n%d: %s: %f\n", aPersonPointer->personalNumber, aPersonPointer->name, aPersonPointer->weight);
                break;
            case 5:
                printf("Enter personal number (YYMMDD) to delete: ");
                scanf_s("%d", &pNr);
                deleteElement(&htable, pNr);
                break;
            case 6:
                printf("Table size: %u\n\n", getSize(&htable));
                break;
            case 7:
                freeHashTable(&htable);
                break;
            case 8:
                printf("Exiting program\n");
                break;
                
            default: printf("Invalid input\n");
                break;
        }
        
    }while(choice != 8);
}



