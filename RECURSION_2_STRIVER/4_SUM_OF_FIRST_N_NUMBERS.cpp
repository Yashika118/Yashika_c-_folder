// #include<bits/stdc++.h>
// using namespace std;
// void func(int n,int sum){
//     if(n<1){
//         cout<<sum<<endl;
//         return;
//     }
//     func(n-1,sum+n);
// }
// int main(){
//     int n;cin>>n;
//     func(n,0);
// }



// USING FUNCTIONAL
#include<bits/stdc++.h>
using namespace std;
int func(int n){
    if(n==0) return 0;
    return n+func(n-1);
}
int main(){
    int n;cin>>n;
    cout<<func(n)<<endl;
}