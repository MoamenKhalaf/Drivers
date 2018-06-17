#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/* Gui Main menu to choose required function
  downward arrow will decrease and integer and upward arrow will increase that integer and
  according to the value of that integer the corresponding menu is printed*/

  int validate_int (void);
int studentnumber (void);
void Creatlist (int NumberOfStudents);
void StudentData ();
void print (void);
void Delete (int Roll_Number);
struct student* Search (int RollNumber);
void modify (void);

extern struct student* Head;

int main()
{
    int FnNumber=1; // store the function number that the arrow points to it
    char c;
	Head = NULL; // list is empty
    int number=0;
   printf("Welcome\nPress Any Key to continue");
   getch(); // wait for pressing any key
   while (1)
   {
       switch (FnNumber)
   case 1:
    {
        system("cls");
        printf("-->1.Enter Number Of Students\n");
        printf("2.Enter Student Data\n");
        printf("3.Show Student Data\n");
        printf("4.Delete student\n");
        printf("5.Modify Student\n");
        printf("6.Search By Roll Number\n");
        printf("7.Exit");
        c=getch();
        if (c==13)
        {
            system("cls");
            number=studentnumber();
        }
        else if (c=='s')
        {
            FnNumber=2;
        }
        else if (c=='w')
        {
            FnNumber=7;
        }
        break;
   case 2:
    {
        system("cls");
         printf("1.Enter Number Of Students\n");
        printf("-->2.Enter Student Data\n");
        printf("3.Show Student Data\n");
        printf("4.Delete student\n");
        printf("5.Modify Student\n");
        printf("6.Search By Roll Number\n");
        printf("7.Exit");
        c=getch();
        if (c==13)
        {
            system("cls");
            if (number == 0)
                    {
                        printf("Enter the Number Of Students first\nPress Any key to go back\n");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        Creatlist(number);
                        number=0;
                    }
        }
        else if (c=='s')
        {
            FnNumber=3;
        }
        else if (c=='w')
        {
            FnNumber=1;
        }
        break;
    }
   case 3:
    {
        system("cls");
         printf("1.Enter Number Of Students\n");
        printf("2.Enter Student Data\n");
        printf("-->3.Show Student Data\n");
        printf("4.Delete student\n");
        printf("5.Modify Student\n");
        printf("6.Search By Roll Number\n");
        printf("7.Exit");
        c=getch();
        if (c==13)
        {
            system("cls");
            if ((number == 0)&(Head == NULL))
                    {
                        printf("Enter Number Of Students & Data first\nPress Any Key to go to back");
                        getch();
                        system("cls");
                    }
                    else if (Head == NULL)
                    {
                        printf("Enter Data first\nPress Any Key to go to back");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        print();
                        printf("Press Any Key to get back to the main screen");
                        getch();
                        system("cls");
                    }
        }
        else if (c=='s')
        {
            FnNumber=4;
        }
        else if (c=='w')
        {
            FnNumber=2;
        }
        break;
    }
   case 4:
    {
        system("cls");
         printf("1.Enter Number Of Students\n");
        printf("2.Enter Student Data\n");
        printf("3.Show Student Data\n");
        printf("-->4.Delete student\n");
        printf("5.Modify Student\n");
        printf("6.Search By Roll Number\n");
        printf("7.Exit");
        c=getch();
        if (c==13)
        {
            system("cls");
            int Roll;
                    if ((number == 0)&(Head == NULL))
                    {
                        printf("Enter Number Of Students & Data first\nPress Any Key to go to back");
                        getch();
                        system("cls");
                    }
                    else if (Head == NULL)
                    {
                        printf("Enter Data first\nPress Any Key to go to back\n");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        printf("Enter Roll Number:");
                        Del:
                        Roll = validate_int();
                        if (Roll == -1)
                        {
                            goto Del;
                        }
                        else
                        {
                            Delete(Roll);
                        }
                    }
        }
        else if (c=='s')
        {
            FnNumber=5;
        }
        else if (c=='w')
        {
            FnNumber=3;
        }
        break;
    }
   case 5:
    {
        system("cls");
         printf("1.Enter Number Of Students\n");
        printf("2.Enter Student Data\n");
        printf("3.Show Student Data\n");
        printf("4.Delete student\n");
        printf("-->5.Modify Student\n");
        printf("6.Search By Roll Number\n");
        printf("7.Exit");
        c=getch();
        if (c==13)
        {
            system("cls");
            if ((number == 0)&(Head == NULL))
                    {
                        printf("Enter Number Of Students & Data first\nPress Any Key to go to back");
                        getch();
                        system("cls");
                    }
                    else if (Head == NULL)
                    {
                        printf("Enter Data first\nPress Any Key to go to back");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        modify();
                    }
        }
        else if (c=='s')
        {
            FnNumber=6;
        }
        else if (c=='w')
        {
            FnNumber=4;
        }
        break;
    }
   case 6:
    {
        system("cls");
         printf("1.Enter Number Of Students\n");
        printf("2.Enter Student Data\n");
        printf("3.Show Student Data\n");
        printf("4.Delete student\n");
        printf("5.Modify Student\n");
        printf("-->6.Search By Roll Number\n");
        printf("7.Exit");
        c=getch();
        if (c==13)
        {
            system("cls");
            int Roll;
                    if ((number == 0)&(Head == NULL))
                    {
                        printf("Enter Number Of Students & Data first\nPress Any Key to go to back\n");
                        getch();
                        system("cls");
                    }
                    else if (Head == NULL)
                    {
                        printf("Enter Data first\nPress Any Key to go to back");
                        getch();
                        system("cls");
                    }
                    else
                    {
                        sr:
                        printf("Enter Roll Number:");
                        Roll = validate_int();
                        if (Roll == -1)
                        {
                            goto sr;
                        }
                        else
                        {
                            Search(Roll);
                            printf("Press Any Key to get back to the main screen");
                            getch();
                        }
                        system("cls");
                    }
        }
        else if (c=='s')
        {
            FnNumber=7;
        }
        else if (c=='w')
        {
            FnNumber=5;
        }
        break;
    }
   case 7:
    {
        system("cls");
         printf("1.Enter Number Of Students\n");
        printf("2.Enter Student Data\n");
        printf("3.Show Student Data\n");
        printf("4.Delete student\n");
        printf("5.Modify Student\n");
        printf("6.Search By Roll Number\n");
        printf("-->7.Exit");
        c=getch();
        if (c==13)
        {
           exit(0);
        }
        else if (c=='s')
        {
            FnNumber=1;
        }
        else if (c=='w')
        {
            FnNumber=6;
        }
        break;
    }
    }
   }
    return 0;
}
