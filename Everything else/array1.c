#include<stdio.h>
int main()
{
float b[2];
b[0]=10.45;
b[1]=25.67;
printf("%f\n",b[0]);
printf("%f\n",b[1]);

char c[5]={'A','B','$','?','7'};
printf("%c\n",c[0]);
printf("%c\n",c[1]);
printf("%c\n",c[2]);
printf("%c\n",c[3]);
printf("%c\n",c[4]);

printf("size of array b: %d\n",sizeof(b));
printf("size of array c: %d\n",sizeof(c));


}