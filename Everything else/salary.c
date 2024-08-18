#include<stdio.h>
int main()
{ char name[30];
  float basic,hra,da,pf,gross;
  printf("Enter name:");
  gets(name);
  printf("Enter Basic salary:");
  scanf("%f",&basic);
  printf("Enter HRA:");
  scanf("%f",&hra);
  printf("Enter D.A.:");
  scanf("%f",&da);

  pf=(basic*12)/100;
  gross=basic+da+hra-pf;
  printf("\nName:%s\n BASIC:%f\nHRA:%f\nDA:%f\n***GROSS SALARY :%f***",name,basic,hra,da,pf.gross);
  return 0;

}