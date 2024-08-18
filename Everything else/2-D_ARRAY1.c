#include<stdio.h>
int main()
{

int a[3][4]={{11,12,13,14},{15,16,17,18},{19,20,21,22}};

for(int i=0;i<3;i++)
{
    for(int j=0;j<4;j++)
    {
        printf("%d",a[i][j]);
    }

printf("\n");

}


}