//Memoization --> tend to store the value of sub problems in some map or table
//Tabulation -->(Bottom Up)--> Base Case to the Required


// //--> using memoization
// #include<bits/stdc++.h>
// using namespace std;
// int func(int n,int dp[]){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=func(n-1,dp)+func(n-2,dp);
// }
// int main(){
//     int n;
//     cin>>n;

//     int dp[n+1];
//     memset(dp,-1,sizeof(dp));

//     cout<< func(n,dp);
    
// // TC:O(N)
// // SC:O(N)+O(N) ----> FOR RECURSION STACK SPACE AND ARRAY
// }




// //-->usnig tabulation
// #include<bits/stdc++.h>
// class Solution {
// public:
//     int fib(int n) {
//         int dp[n+1];
//         if(n==0) return 0;
//         if(n==1) return 1;
//         memset(dp,-1,sizeof(dp));
//         dp[0]=0;
//         dp[1]=1;
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
//      TC:O(N);
//      SC:O(N);
// };


// TO REDUCE THIS SC-->
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a=0; int b=1;
    int c=-1;
    if(n==a) {
        cout<<a<<endl;
    }
    if(n==b){
        cout<<b<<endl;
    }
    for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        
    }
    cout<<c<<endl;
}