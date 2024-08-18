// #include<bits/stdc++.h>
// using namespace std;
// void func(int i,int n){
//     if(i>n) return;
//     cout<<i<<endl;
//     func(i+1,n);
// }
// int main(){
//     int n;cin>>n;
//     func(1,n);
// }



//BACKTRACKING
#include<bits/stdc++.h>
using namespace std;
void func(int i,int n){
    if(i<1) return;
    func(i-1,n);
    cout<<i<<endl;
}
int main(){
    int n;cin>>n;
    func(n,n);
}