#include<stdio.h>
int main()
{
  int n,i,sum=0;
printf("enter number of terms");
scanf("%d",&n);
printf(" the square of natural numbers upto %d terms\n",n);
for(i=1;i<=n;i++)
{
    printf("%d\n",i*i);
    sum=sum+(i*i);
}
printf("sum of %d natural numbers and their square=%d",n,sum);

}