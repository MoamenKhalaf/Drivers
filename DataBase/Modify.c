#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* search by roll number and modify the data*/
void modify (void);
struct student* Search (int RollNumber);
void print (void);
int validate_int (void);
int getname (char *Name);
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
extern struct student* Head;
void modify (void)
{
    struct student* temp;
    int Valid;
    int x=0;
    char c;
    modify:
    printf("Enter Roll Number:");
    Valid = validate_int();
    if (Valid == -1)
    {
        goto modify;
    }
    else
    {
        temp = Search(Valid);
        // if the roll number not found
        if (temp == '\0')
        {

           while (x==0||x==1)
           {
             switch (x)
           {
           case 0:
            {
                printf("Do You Need To add student?\n-->1.yes\t\t\t2.No");
                c=getch();
                if (c==13)
                {
                    system("cls");
                   Creatlist(1);
                   x=2;
                }
                else if (c=='d'||c=='a')
                {
                    x=1;

                }
                system("cls");
                break;
            }
           case 1:
            {
                printf("Do You Need To add student?\n   1.yes\t\t\t-->2.No");
                c=getch();
                if (c==13)
                {
                    system("cls");
                   x=2;
                }
                else if (c=='d'||c=='a')
                {
                    x=0;
                }
                 system("cls");
                break;
            }
           }

           }
        }
        // if roll number found, get the new data
        else
        {
                //get the first name of the student
                FirstName:
                printf("Enter New First Name:");
                Valid=getname(temp->FirstName);
                if (Valid == 0)//if the user enter a very large or small name
                {
                    goto FirstName;
                }
                else
                {
                    ;
                }
                // get the second name of the student
                SecondName:
                printf("Enter New Second Name:");
                Valid=getname(temp->SecondName);
                if (Valid == 0)//if the user enter a very large or small name
                {
                    goto SecondName;
                }
                else
                {
                    ;
                }
                // get the Age of the user
                Age:
                printf("Enter New Age:");
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
                printf("Enter New Percentage:");
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
                    printf("Press Any Key to get back to the main screen");
                    getch();
                    system("cls");
        }


    }

}
