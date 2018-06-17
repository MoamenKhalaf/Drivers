#include <stdio.h>
#include <stdlib.h>
/* Function to validate that entered name is not larger than the maximum allowed name which is assumed 12 character*/
int getname (char *Name);

int getname (char *Name)
{
    int i;
    for (i=0;i<12;i++)
    {
        scanf("%c",Name+i);
        if((Name[i]== '\n')&&(i!=0))
        {
            Name[i] = '\0';
            i=1;
            break;
        }
        else if (i==11)
        {
            fflush(stdin);
            printf("Very Large Name\n");
            i=0;
            break;
        }
        else if ((i==0) && (Name[i]=='\n'))
        {
            fflush(stdin);
            printf("Very small Name\n");
            i=0;
            break;

        }
    }
    return i;
}
