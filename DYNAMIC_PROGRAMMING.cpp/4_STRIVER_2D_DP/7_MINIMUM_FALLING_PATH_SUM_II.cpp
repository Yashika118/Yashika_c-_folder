#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(row==grid.size()-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int res=INT_MAX;
        for(int j=0;j<grid.size();j++){
            if(col==j) continue;
            int a=grid[row][col]+func(row+1,j,grid,dp);
            res=min(res,a);
        }
        return dp[row][col]=res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int result=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int j=0;j<n;j++){
            int ans=func(0,j,grid,dp);
            result=min(result,ans);
        }

        return result;
    }
};