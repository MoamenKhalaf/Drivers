#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* function to get the number of students user need to store their data */
int studentnumber (void);
int validate_int (void);

int studentnumber (void)
{
    int number; // get the number of students
    static char flag = 0x00; // flag to check if the user need to add more users
/* if flag=0x00 that means that it is first time to enter the number students
else if flag = 0x01 that means that it is not the first time and we have to ask user if hen need to add more*/
    if (flag == 0x00) // check if it is the first time
    {
        NumberOfStudents:
        printf("How Many Students:");
        number = validate_int(); // get number from  user and check if user enter a valid data or not
        if (number == -1) // check for valid data
        {
            goto NumberOfStudents;
        }
        else
        {
            flag = 0x01;
            printf("Number successfully saved\nPress Any Key to get back to the main screen");
            /*{
                char c;
                scanf("%c",&c); // waiting for pressing any key
            }*/
            getch();
            Exit:
            system("cls"); // clear the console
            return number;
        }
    }
    else // if it is not first time to enter number of students
    {
       MoreStudents:
        system("cls");
        printf("Do you need add more students?\n        1.Yes       2.No");
        number = validate_int(); // get number from  user and check if user enter a valid data or not
        if (number == -1)
        {
            goto MoreStudents;
        }
        else
        {
            if (number == 1) // if yes
            {
                system("cls");
                goto NumberOfStudents;
            }
            else // if no
            {
                goto Exit;
            }
        }
    }
}
