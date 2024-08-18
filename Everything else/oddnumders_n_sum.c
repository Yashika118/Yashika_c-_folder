#include<stdio.h>
int main()
{ int n;
  scanf("%d",&n);
  int sum=0;
int i=1;
while(i<2*n)
{
if(i%2!=0)
{
sum=sum+i;

}
i++;

}

printf("%d",sum);

}