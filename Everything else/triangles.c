#include <stdio.h>
int main()
{
    int side1, side2, side3;
    //   side1;
    //   side2=b;
    //   side3=c;

    printf("Enter three sides\n");
    scanf("%d%d%d", &side1, &side2, &side3);

    if ((side1 == side2) && (side2 == side3))
        
    {
        printf("EQUILATERAL TRIANGLE\n");
    }
        if ((side1 != side2) && (side2 != side3) && (side3 != side1))
        {
            printf("SCALENE TRIANGLE\n");
        }
        else
        {
            printf("ISOCELES TRIANGLE\n");
        }

        return 0;
    }
