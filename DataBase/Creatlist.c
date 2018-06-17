#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*fill the linked list and sort the students by their roll number*/
void print (void);
struct student* StudentData (void);
void Creatlist (int NumberOfStudents);

struct student
{
    int RollNumber;
    char FirstName [12];
    char SecondName [12];
    int Age;
    int Percentage;
    struct student* next;
};


struct student* Head; // the address of the first node in the list
void Creatlist (int NumberOfStudents)
{
    int i;
    struct student* temp2;
    struct student* temp3;
    struct student* temp3n;

    for (i=0;i<NumberOfStudents;i++)
    {

        if (Head == NULL)
        {
            temp3=StudentData();
            Head=temp3;
            temp3n=temp3->next;
        }
        else
        {
            temp3=Head;
            temp3n=temp3->next;
            temp2=StudentData();
            if (Head->RollNumber>temp2->RollNumber)
            {
                temp2->next=Head;
                Head=temp2;
            }
            else
            {
                while ((temp3->next) != '\0')
                {
                    if((temp2->RollNumber) < (temp3n->RollNumber))
                    {
                        (temp2->next) = (temp3->next);
                        (temp3->next) = temp2;
                        break;
                    }
                    else
                    {
                        temp3=temp3n;
                        temp3n=(temp3n->next);
                    }
                }
                if (temp3->next=='\0')
                {
                  temp3->next=temp2;

                }
            }
        }
            print();

        }

    printf("Data successfully saved\nPress Any Key to get back to the main screen");
            getch();
            system("cls"); // clear the console
}
