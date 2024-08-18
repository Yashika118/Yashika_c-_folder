#include<stdio.h>
int main()
{ int num1,num2,num3,num4,num5,sum;
  float average;
 printf("Enter five numbers\n");
 scanf("%d%d%d%d%d",&num1,&num2,&num3,&num4,&num5);

 sum=num1+num2+num3+num4+num5;
  printf("SUM=%d\n",sum);
 average=sum/5;
  printf("AVERAGE=%f\n",average);

 return 0;
}
