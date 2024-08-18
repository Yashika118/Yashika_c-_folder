#include<stdio.h>
int main()
{ int n,i,sum=0;
  scanf("%d",&n);
for(i=1;i<n;i++)
{
if(n%i==0){
sum=sum+i;
//printf("%d\n",i);//
}
}

printf("\nsum of divisor is=%d",sum);
if(sum==n)
{
  printf("\nSo, the number is perfect");
}
else
{
  printf("\nSo,the number is not perfect");
}
printf("\n");


}