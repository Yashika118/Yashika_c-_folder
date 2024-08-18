#include<iostream>
#include<math.h>
using namespace std;
int main(){

    int a,b,c;
    float root1,root2;
    cin>>a>>b>>c;

    float D=(pow(b,2)-4*a*c);
    cout<<sqrt(D);

    root1=(-b+sqrt(D))/(2*a);
    root2=(-b-sqrt(D))/(2*a);

    if(D==0){
        cout<<"equal real roots"<<endl;
        cout<<root1<<root2<<endl;
    }
    else if(D>0){
        cout<<"Real and Distinct"<<endl;
        cout<<root1<<root2<<endl;
    }
    else{
        cout<<"complex roots"<<endl;
    }












    return 0;
}