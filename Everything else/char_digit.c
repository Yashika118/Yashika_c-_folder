#include<stdio.h>
int main()
{ char ch;
 scanf("%c",&ch);
 if(ch>='A'&& ch<='Z' || ch>='a'&& ch<='z')
 printf("alphabet");
 else if(ch>='0'&&ch<='9')
 printf("DIGIT");

 else
 printf("special character");



return 0;

}