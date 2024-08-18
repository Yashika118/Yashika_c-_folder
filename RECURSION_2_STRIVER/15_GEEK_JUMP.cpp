//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(int ind,int tot_ener,vector<int>& height,vector<int>&dp){
        
        if(ind==0){
            return tot_ener;
        }
        
        // if(dp[ind]!=-1) return dp[ind];
        
        int l=func(ind-1,tot_ener+abs(height[ind]-height[ind-1]),height,dp);
        int r=INT_MAX;
        
        if(ind!=1){
            r=func(ind-2,tot_ener+abs(height[ind]-height[ind-2]),height,dp);
        }
        
        return min(l,r);
        // return min(l,r);
    } 
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        // dp[n-1]=0;
        return func(n-1,0,height,dp);
    }
};

