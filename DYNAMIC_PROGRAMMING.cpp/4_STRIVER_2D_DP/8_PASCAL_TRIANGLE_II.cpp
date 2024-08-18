#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int row,int col,vector<vector<int>>&dp){
        
        if(col==0){
            return dp[row][col]=1;
        }
        if(row==col) return dp[row][col]=1;
        if(dp[row][col]!=-1) return dp[row][col];

        return dp[row][col]=func(row-1,col,dp)+func(row-1,col-1,dp);
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp(rowIndex+1,vector<int>(rowIndex+1,-1));
        
        for(int i=0;i<=rowIndex;i++){
            func(rowIndex,i,dp);
        }

        // for(int i=0;i<=rowIndex;i++){
        //     for(int j=0;j<=rowIndex;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[rowIndex];
    }
};