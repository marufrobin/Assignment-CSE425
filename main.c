
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int z = 0, i = 0, j = 0, c = 0;

char ae[16], ac[20], stk[15], act[10];

void check()
{

    strcpy(ac,"REDUCE TO S -> ");
      for(z = 0; z < c - 2; z++)
    {

        if(stk[z] == '(' && stk[z + 1] == 'S' &&
                                stk[z + 2] == ')')
        {
            printf("%s(S)", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, ae);
            i = i - 2;
        }
    }

    for(z = 0; z < c; z++)
    {

        if(stk[z] == 'a')
        {
            printf("%sa", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';


            printf("\n$%s\t%s$\t", stk, ae);
        }
    }
     for(z = 0; z < c; z++)
    {

        if(stk[z] == 'b')
        {
            printf("%sb", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';


            printf("\n$%s\t%s$\t", stk, ae);
        }
    }
     for(z = 0; z < c; z++)
    {

        if(stk[z] == 'c')
        {
            printf("%sc", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';


            printf("\n$%s\t%s$\t", stk, ae);
        }
    }
    for(z = 0; z < c - 2; z++)
    {
       if(stk[z] == 'S' && stk[z + 1] == '+' &&
                                stk[z + 2] == 'S')
        {
            printf("%sS+S", ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, ae);
            i = i - 2;
        }

    }

    for(z=0; z<c-2; z++)
    {
        if(stk[z] == 'S' && stk[z + 1] == '-' &&
                                stk[z + 2] == 'S')
        {
            printf("%sS-S", ac);
            stk[z]='S';
            stk[z + 1]='\0';
            stk[z + 2]='\0';
            printf("\n$%s\t%s$\t", stk, ae);
            i = i - 2;
        }
    }
    return ;
}


int main()
{
    printf("GRAMMAR is -\nS->S+S \nS->S-S \nS->a|b|c\n");

    strcpy(ae,"a-(b+c)");

    c=strlen(ae);

    strcpy(act,"SHIFT");

    printf("\nstack \t input \t action");

    printf("\n$\t%s$\t", ae);

    for(i = 0; j < c; i++, j++)
    {
        printf("%s", act);

        stk[i] = ae[j];
        stk[i + 1] = '\0';

        ae[j]=' ';

        printf("\n$%s\t%s$\t", stk, ae);

        check();
    }

    check();

    if(stk[0] == 'S' && stk[1] == '\0')
        printf("Accept\n");
    else
        printf("Reject\n");
}



