#include<stdio.h>
int main()
{ int i;
scanf("%d",&i);
int ans=0;
while(i>0){
ans=ans+i%10;
i=i/10;
}
printf("%d",ans);



}