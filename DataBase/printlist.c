#include <stdio.h>
#include <stdlib.h>
/* print linked list*/
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
void print (void)
{
    struct student* temp;
    temp=Head;
    while(temp!=NULL)
    {
        printf("Student Roll Number: %d\n",temp->RollNumber);
        printf("Student First Name: %s\n",temp->FirstName);
        printf("Student Second Name: %s\n",temp->SecondName);
        printf("Student Age: %d\n",temp->Age);
        printf("Student Percentage: %d\n",temp->Percentage);
        printf("\n");
        temp=temp->next;
    }
}
