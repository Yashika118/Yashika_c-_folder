#include<stdio.h>
int main()
{
  int i;
  int sum=0;
  float average;
  scanf("%d",&i);

for(i=1;i<=10;i++)
{
  printf("%d=First 10 Natural Numbers\n",i);

  sum=sum+i;
  

}  
  printf("%d=Sum\n",sum);

  average=sum/10;
  printf("%f=Average\n",average);
  printf("\n");


}