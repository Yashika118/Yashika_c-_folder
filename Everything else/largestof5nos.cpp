#include<iostream>
#include<limits.h>
using namespace std;
int main(){

    int n;
    int largest=INT_MIN;
    // cout<<largest<<endl;
    int count=1;

    while(count<=5){
        cin>>n;
        if(n>largest){
            largest=n;
        }
        count=count+1;
    }
    cout<<largest<<endl;






}