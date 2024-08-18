// MEMOISATION
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    int func(int ind,vector<int>& height,vector<int>&dp){
        
        if(ind==0){
            return 0;
        }
        
        if(dp[ind]!=-1) return dp[ind];
        
        int l=func(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
        int r=INT_MAX;
        
        if(ind!=1){
            r=func(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
        }
        
        return dp[ind]=min(l,r);
    } 
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        return func(n-1,height,dp);
    }
    // TC: O(N)
    // SC :O(N)+O(N)
};


// TABULATION
// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;
// // } Driver Code Ends
// class Solution {
//   public:
//     int minimumEnergy(vector<int>& height, int n) {
//         // Code here
//         int dp[n];
//         memset(dp,-1,sizeof(dp));
//         dp[0]=0;
        
//         int l,r;
//         for(int i=1;i<n;i++){
//              l=dp[i-1]+abs(height[i]-height[i-1]);
//              r=INT_MAX;
//             if(i>1){
//                 r=dp[i-2]+abs(height[i]-height[i-2]);
//             }
//             dp[i]=min(l,r);
//         }
//         return dp[n-1];
//     }
//      // TC: O(N)
//      // SC: O(N)
// };



// //MEMORY OPTIMISATION
// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;
// // } Driver Code Ends
// class Solution {
//   public:
//     int minimumEnergy(vector<int>& height, int n) {
//         // Code here
//         int a=0;
//         int b=0;
//         int c;
        
//         int l,r;
//         for(int i=1;i<n;i++){
//              l=a+abs(height[i]-height[i-1]);
//              r=INT_MAX;
//             if(i>1){
//                 r=b+abs(height[i]-height[i-2]);
//             }
//             c=min(l,r);
//             b=a;
//             a=c;
//         }
//         return c;
//     }
//      // TC:O(N); SC:O(1)
// };