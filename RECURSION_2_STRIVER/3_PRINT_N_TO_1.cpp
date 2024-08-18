// #include<bits/stdc++.h>
// using namespace std;
// void func(int n){
//     if(n==0) return;
//     cout<<n<<endl;
//     func(n-1);
// }
// int main(){
//     int n;cin>>n;
//     func(n);
// }




//BACKTRACKING
#include<bits/stdc++.h>
using namespace std;
void func(int i,int n){
    if(i>n) return;
    func(i+1,n);
    cout<<i<<endl; 
}
int main(){
    int n;cin>>n;
    func(1,n);
}