#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int row = 1; row <= n; row++)
    {
        for (int space = 1; space <= n - row; space++)
        {
            printf("  ");
        }
        for (int star = 1; star <= (2 * row - 1); star++)
        {

            printf("* ");
    
        }
        printf("\n");
    }
    for(int row=1;row<=n-1;row++)
    {for(int space=1;space<=row;space++)
    {printf("  ");

    }
    for(int star=1;star<=(2*(n-row))-1;star++)
    {
        printf("* ");
    }
    printf("\n");
    }

    return 0;
}