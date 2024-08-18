#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int ind,vector<int>&cost, vector<int>&dp){
        if(ind==cost.size()-1){
            return dp[ind]=cost[ind];
        }
        
        if(ind>(cost.size()-1)) return 0;

        if(dp[ind]!=-1) return dp[ind];

        // int left=INT_MAX; int right=INT_MAX;
        int left=cost[ind]+func(ind+1,cost,dp);
        int right=cost[ind]+func(ind+2,cost,dp);
        return dp[ind]=min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int mini=INT_MAX;
        
        for(int ind=0;ind<2;ind++){
            vector<int>dp(cost.size()+1,-1);
            int f=func(ind,cost,dp);
            // cout<<f<<endl;`
            mini=min(f,mini);
        }
        return mini;
    }
};