#include<stdio.h>
int main()

{int sum=0;
     while(1)
  {int n;
    scanf("%d",&n);

    sum=sum+n;
    if(sum<0){
        return 0;
    }
    else{
        printf("%d\n",n);
    }

  }   








}