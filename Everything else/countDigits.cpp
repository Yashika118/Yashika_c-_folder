#include <iostream>
using namespace std;
int main()
{
    int n;
    int dig;
    int d;
    cin >> n >> dig;
    int count = 0;
    
    while(n!=0){
        d=n%10;
        if(dig==d){
            count=count+1;
        }
        n=n/10;
    }
    cout<<count;
}