#include<iostream>
using namespace std;
int main(){

char C;
    cin>>C;
if((C>=65)&&(C<=90)){
    cout<<"uppercase"<<endl;
}

else if((C>=97)&&(C<=122)){
    cout<<"lowercase"<<endl;
}
else{
    cout<<"invalid"<<endl;
}










return 0;
}