#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int row = 1; row <= n; row++)
    {
        for (int numbers = n; numbers >= row; numbers--)
        {
            printf("%d", numbers);
            printf("\t");
        }
        printf("\n");
    }
}
