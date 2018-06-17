#include <stdio.h>
#include <stdlib.h>
/* search by roll number and return the address of the node where the roll number is found
   if it returned null that means that the roll number is not found*/
struct student* Search (int RollNumber);
void print (void);
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
struct student* Search (int RollNumber)
{
     struct student* temp; // temporary pointer to the head of linked list to loop over the linked list */
     temp = Head;
     // check the Roll number and loop till found it
     while (temp->next != '\0')
        {
            // check if the roll number is the required or not
            // if yes, print student data and break
            if (temp->RollNumber == RollNumber)
            {
                printf(" Student Roll Number is found\n");
                // print student data and ask if it is the right data of student to be deleted
                printf("Student Roll Number: %d\n",temp->RollNumber);
                printf("Student First Name: %s\n",temp->FirstName);
                printf("Student Second Name: %s\n",temp->SecondName);
                printf("Student Age: %d\n",temp->Age);
                printf("Student Percentage: %d\n",temp->Percentage);
                printf("\n\n");
                break;
            }
            // if it is not the required Roll number move to the next node in the list
            else
            {
                temp=temp->next;
            }
        }
    // check if the required Roll number is the roll number of the last node or not
    // if it is not, print that the number is not found and make it return null
    if ((temp->next == '\0')&(temp->RollNumber != RollNumber))
    {
        printf("Student Roll Number is not found\n\n");
        temp=temp->next;
    }
    // if it is , print data
    else if ((temp->next == '\0')&(temp->RollNumber == RollNumber))
    {
        printf(" Student Roll Number is found\n");
        // print student data and ask if it is the right data of student to be deleted
        printf("Student Roll Number: %d\n",temp->RollNumber);
        printf("Student First Name: %s\n",temp->FirstName);
        printf("Student Second Name: %s\n",temp->SecondName);
        printf("Student Age: %d\n",temp->Age);
        printf("Student Percentage: %d\n",temp->Percentage);
        printf("\n\n");
    }
    return temp;
}
