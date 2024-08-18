#include<stdio.h>
int main()
{
 int months;
 printf("Enter the months(1-12)");
 scanf("%d",&months);
switch(months)
{
 case 1:
 printf("JANUARY\n");
 break;
 case 2:
 printf("FEBRUARY\n");
 break;
 case 3:
 printf("MARCH\n");
 break;
 case 4:
 printf("APRIL\n");
 break;
 case 5:
 printf("MAY\n");
 break;
 case 6:
 printf("JUNE\n");
 break;
 case 7:
 printf("JULY\n");
 break;
 case 8:
 printf("AUGUST\n");
 break;
 case 9:
 printf("SEPTEMBER\n");
 break;
 case 10:
 printf("OCTOBER\n");
 break;
 case 11:
 printf("NOVEMBER\n");
 break;
 case 12:
 printf("DECEMBER\n");
 break;
 default:
 printf("INVALID CODE\n");

}
return 0;
}