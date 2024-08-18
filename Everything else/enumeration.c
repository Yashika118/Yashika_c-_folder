#include<stdio.h>
int main()
{
 int color;
 printf("enter the color code(0-2)");
 scanf("%d",&color);

if(color==SAFFRON){
printf("saffron");}
elseif(color==WHITE){
printf("white");}
elseif(color==GREEN){
printf("green");}
else{
printf("invalid color\n");
}

enum c{SAFFRON,WHITE,GREEN};


}