#include <stdio.h>
int main()
{
    char ch;
    ch= 'y';
    int i;
    while (ch == 'y')
    {
        printf("Enter a number");
        scanf("%d", &i);
        if (i % 2 == 0)
        {
            printf("%d=EVEN", i);
        }
        else
        {
            printf("%d=ODD", i);
        }

    printf("y or n");
    scanf(" %c",&ch);




    }
    return 0;
}