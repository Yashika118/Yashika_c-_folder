#include<iostream>
using namespace std;
int main(){
    int N;
    int Rev=0;
    cin>>N;
    while(N!=0){
    int dig=N%10;
    Rev=(Rev*10+dig);
    N=N/10;
    }

        cout<<Rev<<endl;









    return 0;
}