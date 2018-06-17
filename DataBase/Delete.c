#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Delete the student that user enter his Roll number */
void print (void);
struct student* Search (int RollNumber);
void Delete (int Roll_Number);
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
void Delete (int Roll_Number)
{
    struct student* temp; // temporary pointer to get the address of the required node*/
    struct student* temp_prev; // pointer to the address of the previous node
    temp_prev = Head;
    temp = Search(Roll_Number);
    // if the returned address is null that means the entered roll number is not found
    if (temp != '\0')
    {
        printf("You Are About to delete a student\npress <Enter> to continue or <ESC> to get back to the main\n");
        char Valid;
        Valid=getch();
        // if enter,delete
        if (Valid == 13)
        {
            if (temp == Head)
            {
                Head=Head->next;
                free(temp);
                system("cls"); // clear the console
            }
            else
            {
                // loop until get the previous node to save the link before free the required node
            while (temp_prev->next != temp)
            {
                temp_prev= temp_prev->next;
            }
            temp_prev->next = temp->next;
            free(temp);
            system("cls"); // clear the console
            }

        }
        // if press ESC get back to main continue
        else if (Valid == 27)
        {
            system("cls");;
        }
        // if press any key except ENTER or ESC
        else
        {
            printf("You Have Entered a wrong key\nPress Any Key to get back to the main screen");
            getch();
            system("cls"); // clear the console
        }

    }
    else
    {
        printf("Press Any Key to get back to the main screen");
        getch();
        system("cls");
    }

}
