// USING MEMOISATION
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int noOfWays(int n,int dp[]){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];

        int left=noOfWays(n-1,dp);
        int right=0;
        if(n!=1){
            right=noOfWays(n-2,dp);
        }
        return dp[n]=left+right;
    }
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int ans=noOfWays(n,dp);
        return ans;
    }
    // TC:O(N)
    // SC:O(N)+O(N)
};


// TABULATION
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int climbStairs(int n) {
//         int arr[n+1];
//         arr[0]=1;
//         if(n==0) return 1;

//         int l=0 ; int r=0;
//         for(int i=1;i<=n;i++){
//             l=arr[i-1];
//             if(i!=1){
//                 r=arr[i-2];
//             }
//             arr[i]=l+r;
//         }
//         return arr[n];
//     }
// };

// TABULATION AND MEMORY MINIMISATION CAN BE DO SAME AS RECURSION AS WELL