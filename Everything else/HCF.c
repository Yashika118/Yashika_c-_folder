#include<stdio.h>
int main()
{int n,m;
scanf("%d%d",&n,&m);
int i;
if(n<m){
    i=n;
}
else{
    i=m;
}
while(1){
if(n%i==0&&m%i==0){

printf("%d=HCF",i);
    break;
}
else
    i--;




}




}