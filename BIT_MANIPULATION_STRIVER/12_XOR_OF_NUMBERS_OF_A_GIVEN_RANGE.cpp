#include<bits/stdc++.h>
using namespace std;
// int func(int n){
//     int xo_r=0;
//     for(int i=1;i<=n;i++){
//         xo_r=xo_r ^ i;
//     }
//     return xo_r;

//     // TC: O(N)  --> INTERVIEWER WILL NOT HAPPY WITH THIS
//     // SC: O(1)
// }

int func(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;

    // TC: O(1)  -->INTERVIEWER WILL BE HAPPY HERE
    // SC: O(1)
}
int main(){
    int n; cin>>n;
    cout<< func(n)<<endl;
}