#include <stdio.h>
/* function to validate the data entered by user in case of integers*/
int validate_int (void);

int validate_int()
{
    int Data;
    char Enter;
    int right;
    fflush(stdin);
    right = scanf("%d%c",&Data,&Enter); /* scanf function return -1 if data invalid
                                              and return the number of entered data if it is valid */

    if (right < 2) // Check for the return of scanf function to know user enter a right data or not
    {
        printf("Enter A right Data\n");
        fflush(stdin); // flush the standard input buffer
        Data=-1; // return -1 to know that data entered is wrong
    }
    else if (Enter=='\n') /* check if the second argument is Enter or not
                            if true return the Data */
    {
        fflush(stdin); // flush the standard input buffer
    }

    else
    {
        printf("Enter A right Data\n");
        fflush(stdin); // flush the standard input buffer
        Data = -1; // return -1 to know that data entered is wrong
    }

    return Data;
}
