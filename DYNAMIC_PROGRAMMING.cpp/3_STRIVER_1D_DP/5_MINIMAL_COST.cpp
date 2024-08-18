// MEMOISATION
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
  int minCost(int ind,vector<int>height,int k,int dp[]){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int l=INT_MAX;
    for(int i=1;i<=k;i++){
        if(ind>i-1){
             l=min(l,minCost(ind-i,height,k,dp)+abs(height[ind]-height[ind-i]));
        }
    }
     return dp[ind]=l;
  }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return minCost(n-1,height,k,dp);
    }
    // TC: O(N)*K
    // SC: O(N)+O(N)
};
