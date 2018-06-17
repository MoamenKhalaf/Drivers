#include <stdio.h>
#include <stdlib.h>
/* Get the student data */
struct student* StudentData (void);
int validate_int (void);
int getname (char *Name);
/* Structure to get student data and the pointer to the structure used to establish a linked list*/
struct student
{
    int RollNumber;
    char FirstName [12];
    char SecondName [12];
    int Age;
    int Percentage;
    struct student* next;
};

extern struct student* Head;

struct student* StudentData (void)
{
    int valid; // check the validation of name entered by the user
    struct student* TempHead;
    TempHead=Head;
    struct student* temp= (struct student*) malloc(sizeof(struct student)); // create new element in the heap section
    // get the Roll of the student
    Roll:
    printf("Enter Roll Number:");
    temp->RollNumber=validate_int();
    if (temp->RollNumber == -1) // if the return of the scanf is -1 which means invalid input
    {
        goto Roll;
    }
    else if (temp->RollNumber <0)// if the user enter a negative number
    {
        printf("Enter A Positive Number");
        goto Roll;
    }
    else
    {
        while (TempHead != NULL)
        {
            if (TempHead->RollNumber == temp->RollNumber)
            {
                printf("You Have Entered this Roll number before!\n\n");
                goto Roll;
            }
            else
            {
                TempHead=TempHead->next;
            }
        }
    }

    //get the first name of the student
    FirstName:
    printf("Enter First Name:");
    valid=getname(temp->FirstName);
    if (valid == 0)//if the user enter a very large or small name
    {
        goto FirstName;
    }
    else
    {
        ;
    }
    // get the second name of the student
    SecondName:
    printf("Enter Second Name:");
    valid=getname(temp->SecondName);
    if (valid == 0)//if the user enter a very large or small name
    {
        goto SecondName;
    }
    else
    {
        ;
    }
    // get the Age of the user
    Age:
    printf("Enter Age:");
    temp->Age=validate_int();
    if (temp->Age == -1)// if the return of scanf is -1 which means invalid input
    {
        goto Age;
    }
    else if (temp->Age <0) // if user enter a negative number which is invalid
    {
        printf("Enter A Positive Number\n");
        goto Age;
    }
    else
    {
        ;
    }
    // get the percentage of the student
    Percentage:
    printf("Enter Percentage:");
    temp->Percentage=validate_int();
    if (temp->Percentage == -1)// if the return of scanf is -1 which means invalid input
    {
        goto Percentage;
    }
    else if (temp->Percentage <0)// if user enter a negative number
    {
        printf("Enter A Positive Number\n");
        goto Percentage;
    }
    else
    {
        ;
    }

    temp->next=NULL;
    printf("\n\n\n");
    return temp;


}
