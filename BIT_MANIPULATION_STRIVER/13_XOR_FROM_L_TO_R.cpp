#include<bits/stdc++.h>
using namespace std;
// int func(int L,int R){
//     int xo_r=0;
//     for(int i=L;i<=R;i++){
//         xo_r=xo_r ^ i;
//     }

//     return xo_r;

//     // TC: O(R-(L-1));
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
    int L ,R;
    cin>> L >>R;
    int ans=func(L-1) ^ func(R);
    cout<<ans<<endl;
    
}