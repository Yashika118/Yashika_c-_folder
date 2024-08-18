#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(row<0 || col<0) return 0;
        if(obstacleGrid[row][col]==1) return 0;
        if(row==0 and col==0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];

        int up=func(row-1,col,obstacleGrid,dp);
        int left=func(row,col-1,obstacleGrid,dp);

        return dp[row][col]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        
        return func(m-1,n-1,obstacleGrid,dp);
    }
};


// TABULATION
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//             for(int row=0;row<m;row++){
//                 for(int col=0;col<n;col++){
//                     if(obstacleGrid[row][col]==1){
//                         dp[row][col]=0;
//                     }
//                     else if(row==0 and col==0){
//                         dp[row][col]=1;
//                     }
//                     else{
//                         int up=0; int left=0;
//                         if(row>0) up=dp[row-1][col];
//                         if(col>0) left=dp[row][col-1];
//                         dp[row][col]=up+left; 
//                     }
//                 }
//             }
//         return dp[m-1][n-1];
//     }
// };