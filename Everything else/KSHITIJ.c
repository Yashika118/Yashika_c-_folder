#include <stdio.h>
void success(int n)
{
    int i, j;



    for(i=n/2; i<=n; i+=2)
    {
        for(j=1; j<n-i; j+=2)
        {
            printf(" ");
        }

        for(j=1; j<=i; j++)
        {
            printf("*");
        }

        for(j=1; j<=n-i; j++)
        {
            printf(" ");
        }

        for(j=1; j<=i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    for(i=n; i>=1; i--)
    {
        for(j=i; j<n; j++)
        {
            printf(" ");
        }

        for(j=1; j<=(i*2)-1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    printf("i really love spending time with you!!!");


}


int main()
{
    char arr[27] = {'a', 'b', 'c', 'd', 'e', 'c', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int n;
    int t = 1;
    int i = 0;
    while (1)
    {

        if (t==1)
        {
            printf("enter a number between 4-20 \n");
            scanf("%d", &n);
        }
        t--;
        printf("%c%c%c%c", arr[23], arr[9], arr[12], arr[12]);
        printf(" ");
        printf("%c%c%c", arr[25], arr[15], arr[21]);
        printf(" ");
        for (int count = 0; count < i; count++)
        {
            printf("%c%c%c%c%c%c", arr[16], arr[12], arr[4], arr[0], arr[19], arr[4]);
            printf(" ");
        }
        printf("%c%c", arr[1], arr[4]);
        printf(" ");
        printf("%c%c", arr[13], arr[25]);
        printf(" ");
        printf("%c%c%c%c%c%c%c%c%c", arr[22], arr[0], arr[12], arr[4], arr[14], arr[20], arr[9], arr[14], arr[4]);
        printf("?\n");

            printf("enter 'y' for yes or 'n' for no \n");
            char response;
            scanf(" %c", &response);
            if (response == 89 || response == 121)
            {
                success(n);
                return 0;
            }
            else if (response == 78 || response == 110)
            {
                i++;
            }
            else
            {
                printf("y ya n likh do yaar \n");
            }

    }

    return 0;
}
